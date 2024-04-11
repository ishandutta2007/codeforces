#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const unsigned long long shift=21,mask=(1LL<<shift)-1;
int n,i,j,k,m,a[1000100],b[1000100],all[1000100],l[2000100],cnt,cur,last,now,best=-1000000000;
unsigned long long f[2000100],id,lastId;
char s[2000100];
int main() {
  scanf("%s",s+1);
  n=strlen(s+1);
  for (i=1; i<=n; i++) {
    a[i]=a[i-1]+(s[i]=='('?1:-1);
    b[i]=min(b[i-1],a[i]);
    s[i+n]=s[i];
  }
  for (i=1; i<=2*n; i++) l[i-1]=1+int(s[i]==')');
  for (i=n; i>0; i--) {
    now=min(0,min(b[i]+last,cur));
    if (now>best) { best=now; m=0; }
    if (now==best) all[m++]=i;
    if (s[i]==')') {
      last--; cur=min(cur-1,-1);
    } else {
      last++; cur++;
    }
  }
  for (k=0; k<shift; k++) {
    /*for (i=0; i<2*n; i++) f[i]=e[i]=(l[i]<<shift)+(((i+(1<<k))>=2*n)?0:l[i+(1<<k)]);
    sort(f,f+2*n);
    for (i=0; i<2*n; i++) l[i]=lower_bound(f,f+2*n,e[i])-f+1;*/
    for (i=0; i<2*n; i++) {
      long long x=l[i];
      long long y=((i+(1<<k))>=2*n)?0:l[i+(1<<k)];
      if (x>=(1LL<<shift) || y>=(1LL<<shift)) puts("!");
      f[i]=(((x<<shift)+y)<<shift)+i;
      //if (k<4) printf("%I64d(%I64d,%I64d), ",f[i],x,y);
    }
    sort(f,f+2*n);
    for (lastId=-1, i=0; i<2*n; i++) {
      id=(f[i]>>shift);
      if (id!=lastId) {
        lastId=id; j=i+1;
      }
      //if (k<4 && i<5) printf("%d %d: (%I64d %I64d) %I64d\n",k,i,id>>shift,id&mask,f[i]&mask);
      l[f[i]&mask]=j;
    }
  }
  for (i=0; i<-best; i++) { putchar('('); cnt++; }
  for (i=k=0; i<m; i++) if (l[all[k]]>l[all[i]]) k=i;
  for (i=0; i<n; i++) {
    char ch=s[all[k]+i+1];
    cnt+=(ch=='('?1:-1);
    putchar(ch);
  }
  for (; cnt>0; cnt--) putchar(')');
  return 0;
}