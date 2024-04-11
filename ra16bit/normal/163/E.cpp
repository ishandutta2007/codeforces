#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MX=1000010;
int gt,n,m,k,i,j,cur,p,fi,fr,fc,x,y,e,num,q[MX],b[MX][26],where[MX],f[MX],first[MX],last[MX],a[2*MX];
vector <int> g[MX];
char s[MX],ch;
bool active[MX];
long long r;
void dfs(int i) {
  first[i]=++gt;
  for (int j=0; j<g[i].size(); j++) dfs(g[i][j]);
  last[i]=++gt;
}
inline void modify(int i, int v) {
  for (e=i; e<=gt; e=(e<<1)-(e&(e-1))) a[e]+=v;
}
int main() {
  scanf("%d%d",&m,&k);
  for (p=1; p<=k; p++) {
    scanf("%s",s);
    n=strlen(s);
    for (i=j=0; i<n; i++) {
      cur=s[i]-'a';
      if (b[j][cur]==0) b[j][cur]=++num;
      j=b[j][cur];
    }
    where[p]=j;
  }
  fi=0; fr=1; q[0]=0;
  while (fi<fr) {
    i=q[fi++];
    for (j=0; j<26; j++) if (b[i][j]!=0) {
      cur=b[i][j];
      if (i>0) {
        for (fc=f[i]; fc>0; fc=f[fc]) if (b[fc][j]!=0) break;
        if (b[fc][j]!=0) fc=b[fc][j];
        f[cur]=fc;
      } else f[cur]=0;
      g[f[cur]].push_back(cur);
      q[fr++]=cur;
    }
  }
  dfs(0);
  for (p=1; p<=k; p++) {
    active[p]=true;
    modify(first[where[p]],1);
    modify(last[where[p]],-1);
  }
  while (m--) {
    for (ch=getchar(); ch!='?' && ch!='+' && ch!='-'; ch=getchar());
    if (ch=='?') {
      scanf("%s",s);
      n=strlen(s);
      for (i=j=r=0; i<n; i++) {
        cur=s[i]-'a';
        for (fc=j; fc>0; fc=f[fc]) if (b[fc][cur]!=0) break;
        j=b[fc][cur];
        if (j>0) for (e=first[j]; e>0; e&=e-1) r+=a[e];
      }
      printf("%I64d\n",r);
    } else {
      x=0; y=(ch=='-')?-1:1;
      for (ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) x=x*10+ch-'0';
      if ((y>0 && active[x]) || (y<0 && !active[x])) continue;
      active[x]=!active[x];
      modify(first[where[x]],y);
      modify(last[where[x]],-y);
    }
  }
  return 0;
}