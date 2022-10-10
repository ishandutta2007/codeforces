#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=2000200,md=1000000007;
int n,on,m,i,j,x,y,k,pv,len,cur,dst,nst,now,d[MX];
long long r[MX];
vector<pii> g[MX];
priority_queue<pii,vector<pii>,greater<pii>> q;
string st;
int main() {
  scanf("%d%d",&n,&m); on=n;
  for (i=1; i<=m; i++) {
    stringstream ss;
    ss<<i;
    st=ss.str();
    len=st.length();
    scanf("%d%d",&x,&y);
    for (pv=x, j=0; j+1<len; j++) {
      cur=++n;
      g[pv].push_back({st[j]-'0',cur});
      pv=cur;
    }
    g[pv].push_back({st[len-1]-'0',y});
    for (pv=y, j=0; j+1<len; j++) {
      cur=++n;
      g[pv].push_back({st[j]-'0',cur});
      pv=cur;
    }
    g[pv].push_back({st[len-1]-'0',x});
  }
  //for (i=1; i<=n; i++) sort(g[i].begin(),g[i].end());
  d[1]=1;
  for (i=2; i<=n; i++) d[i]=1000000000;
  q.push({1,1});
  pv=-1;
  while (!q.empty()) {
    i=q.top().second;
    dst=q.top().first;
    q.pop();
    if (dst!=d[i]) continue;
    if (dst!=pv) {
      ++now;
      pv=dst;
    }
    //all.push_back(i);
    for (j=0; j<g[i].size(); j++) {
      k=g[i][j].second;
      nst=now*10+g[i][j].first;
      if (nst<d[k]) {
        d[k]=nst;
        r[k]=(r[i]*10+g[i][j].first)%md;
        q.push({nst,k});
      }
    }
  }
  for (i=2; i<=on; i++) printf("%d\n",int(r[i]));
  return 0;
}