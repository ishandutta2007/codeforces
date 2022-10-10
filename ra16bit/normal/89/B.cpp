#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;
int n,k,i,j,kk,l,xx,yy,x[111],y[111],z[111],p[111],u[111];
long long w[111],h[111];
vector <int> g[111];
char s[88],t[88];
string st,s1,s2;
map <string, int> m;
map <string, int> :: iterator it;
void dfs(int i) {
  if (u[i]==1) return;
  u[i]=1;
  if (z[i]==0) { w[i]=x[i]; h[i]=y[i]; return; }
  if (g[i].size()==0) return;
  int j,k;
  for (j=0; j<g[i].size(); j++) {
    k=g[i][j];
    dfs(k);
    if (z[i]==1) w[i]+=w[k]; else if (w[k]>w[i]) w[i]=w[k];
    if (z[i]==2) h[i]+=h[k]; else if (h[k]>h[i]) h[i]=h[k];
  }
  if (z[i]==1) w[i]+=(int(g[i].size())-1)*y[i]; else h[i]+=(int(g[i].size())-1)*y[i];
  w[i]+=2*x[i];
  h[i]+=2*x[i];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    if (s[0]=='W') {
      scanf("%s",s); st="";
      for (j=0; s[j]!='('; j++) st+=s[j];
      sscanf(s+j,"(%d,%d)",&xx,&yy);
      m[st]=++k; x[k]=xx; y[k]=yy; z[k]=0;
    } else if (s[0]=='H') {
      scanf("%s",t); st=t;
      m[st]=++k; z[k]=1;
    } else if (s[0]=='V') {
      scanf("%s",t); st=t;
      m[st]=++k; z[k]=2;
    } else {
      for (j=0; s[j]!='.'; j++);
      st=s; s1=st.substr(0,j);
      for (kk=j; s[kk]!='('; kk++);
      if (s[j+1]=='p') {
        for (l=kk; s[l]!=')'; l++);
        s2=st.substr(kk+1,l-kk-1);
        g[m[s1]].push_back(m[s2]);
      } else if (s[j+5]=='b') {
        j=m[s1];
        for (l=kk+1, x[j]=0; s[l]!=')'; l++) x[j]=x[j]*10+s[l]-'0';
      } else {
        j=m[s1];
        for (l=kk+1, y[j]=0; s[l]!=')'; l++) y[j]=y[j]*10+s[l]-'0';
      }
    }
  }
  for (i=1; i<=k; i++) if (p[i]==0) dfs(i);
  for (it=m.begin(); it!=m.end(); it++) printf("%s %I64d %I64d\n",(*it).first.c_str(),w[(*it).second],h[(*it).second]);
  return 0;
}