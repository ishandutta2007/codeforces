#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,i,m,cnt,x,a[MX];
bool u[MX],lst[MX],now[MX];
char s[7],st[7],sh[7];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) lst[i]=true;
  while (true) {
    printf("? ");
    for (m=x=i=0; i<n; i++) if (!u[i] && lst[i]) {
      if (x==0) { now[i]=true; a[m++]=i; }
      x^=1;
    }
    for (i=0; i<n; i++) if (!u[i] && !lst[i]) {
      if (x==0) { now[i]=true; a[m++]=i; }
      x^=1;
    }
    printf("%d",m);
    for (i=0; i<m; i++) printf(" %d",a[i]+1);
    puts("");
    fflush(stdout);
    for (cnt=i=0; i<n; i++) if (!u[i]) fprintf(stderr,"%d[%d] ",i+1,lst[i]);
    fprintf(stderr,"\n");
    for (cnt=i=0; i<n; i++) if (!u[i]) {
      if (lst[i] || now[i]) ++cnt;
    }
    fprintf(stderr,"=%d",cnt);
    for (cnt=i=0; i<n; i++) if (!u[i]) {
      if (lst[i] || !now[i]) ++cnt;
    }
    fprintf(stderr,"/%d\n",cnt);
    scanf("%s",s);
    if (s[0]=='N') for (i=0; i<n; i++) now[i]=!now[i];
    for (cnt=i=0; i<n; i++) if (!u[i]) {
      if (!lst[i] && !now[i]) u[i]=true; else ++cnt;
    }
    if (cnt<=3) break;
    for (i=0; i<n; i++) if (now[i]) {
      lst[i]=true;
      now[i]=false;
    } else lst[i]=false;
  }
  if (cnt==3) {
    vector<int> t;
    for (i=0; i<n; i++) if (!u[i]) t.push_back(i);
    printf("? 2 %d %d\n",t[0]+1,t[1]+1);
    fflush(stdout);
    scanf("%s",s);
    for (i=0; i<n; i++) if (!u[i]) t.push_back(i);
    printf("? 2 %d %d\n",t[0]+1,t[1]+1);
    fflush(stdout);
    scanf("%s",st);
    if (s[0]==st[0]) {
      if (s[0]=='N') {
        u[t[0]]=true;
        u[t[1]]=true;
      } else u[t[2]]=true;
    } else if (st[0]=='Y') {
      s[0]=st[0];
      printf("? 2 %d %d\n",t[0]+1,t[1]+1);
      fflush(stdout);
      scanf("%s",st);
      if (st[0]=='Y') u[t[2]]=true; else {
        printf("? 2 %d %d\n",t[1]+1,t[2]+1);
        fflush(stdout);
        scanf("%s",s);
        if (s[0]=='N') u[t[1]]=true; else u[t[0]]=true;    
      }
    } else {
      printf("? 2 %d %d\n",t[1]+1,t[2]+1);
      fflush(stdout);
      scanf("%s",s);
      if (s[0]=='N') u[t[1]]=true; else u[t[0]]=true;    
    }
  }
  for (i=0; i<n; i++) if (!u[i]) {
    printf("! %d\n",i+1);
    fflush(stdout);
    scanf("%s",s);
    if (s[1]==')') break;
  }
  return 0;
}