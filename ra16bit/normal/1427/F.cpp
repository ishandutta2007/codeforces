#include <bits/stdc++.h>
using namespace std;
const int MX=1212;
int num,n,x,i,j,cur,t,s[MX],a[MX][3],r[MX],mx[MX],mxs[MX];
priority_queue<pair<int,int>> q[2];
vector<int> v[MX];
bool u[MX];
int main() {
  scanf("%d",&n);
  for (i=0; i<3*n; i++) {
    scanf("%d",&x);
    u[x]=true;
  }
  for (i=1; i<=6*n; i++) if (t>1 && u[s[t]]==u[i] && u[s[t-1]]==u[i]) {
    a[++num][0]=s[t-1];
    a[num][1]=s[t];
    a[num][2]=i;
    t-=2;
    for (j=0; j<3; j++) mxs[num]=max(mxs[num],mx[a[num][j]]);
    v[s[t]].push_back(num);
    mx[s[t]]=max(mx[s[t]],mxs[num]+1);
  } else s[++t]=i;
  for (i=0; i<v[0].size(); i++) q[int(u[a[v[0][i]][0]])].push({mxs[v[0][i]],v[0][i]});
  for (i=0; i<2*n; i++) {
    cur=i&1;
    x=q[cur].top().second;
    q[cur].pop();
    r[2*n-i-1]=x;
    cur=1-cur;
    for (j=0; j<3; j++) for (int k: v[a[x][j]]) q[cur].push({mxs[k],k});
  }
  for (i=0; i<2*n; i++) for (j=0; j<3; j++) printf("%d%c",a[r[i]][j],(j==2)?'\n':' ');
  return 0;
}