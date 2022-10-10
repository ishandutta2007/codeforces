#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
int n,m,i,j,cur,old,A,B,a[5050],b[5050],c[5050];
char s[5050],mn[5050],mx[5050];
string name,op[5050],v[5050];
map<string,int> mm;
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%s",s);
    name=s;
    mm[name]=i;
    scanf("%s",s);
    scanf("%s",s);
    if (s[0]=='0' || s[0]=='1') v[i]=s; else {
      name=s;
      if (name=="?") a[i]=0; else a[i]=mm[name];
      scanf("%s",s);
      op[i]=s;
      scanf("%s",s); name=s;
      if (name=="?") b[i]=0; else b[i]=mm[name];
    }
  }
  for (j=0; j<m; j++) {
    for (c[0]=0; c[0]<2; c[0]++) {
      cur=0;
      for (i=1; i<=n; i++) {
        if (v[i]=="") {
          A=c[a[i]];
          B=c[b[i]];
          if (op[i]=="AND") c[i]=(A&B);
            else if (op[i]=="OR") c[i]=(A|B); else c[i]=(A^B);
        } else c[i]=int(v[i][j]=='1');
        cur+=c[i];
      }
      if (c[0]==0 || cur<old) mn[j]=char('0'+c[0]);
      if (c[0]==0 || cur>old) mx[j]=char('0'+c[0]);
      old=cur;
    }
  }
  puts(mn);
  puts(mx);
  return 0;
}