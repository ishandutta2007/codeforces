#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define LL long long
struct erz{LL a;int b;};
struct cmp
{
    bool operator() (erz &p,erz &q) {return(p.a>q.a);}
};
priority_queue<erz,vector<erz>,cmp> Q;

erz mp(LL a,int b) {erz c;c.a=a,c.b=b;return(c);}
LL wabs(LL x) {if (x<0) x=-x;return(x);}
int fh(LL x) {if (x>=0) return 1; else return -1;}
LL a[200005];
int main()
{
  //  freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    int i,n,m,f=1;LL x;
    scanf("%d%d%I64d",&n,&m,&x);
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        if (a[i]<0) f*=-1;
        Q.push(mp(wabs(a[i]),i));
    }
    for (i=1;i<=m;i++)
    {
        int c=Q.top().b;Q.pop();LL ac=a[c];
        if (f==1) {if (a[c]>=0) a[c]-=x; else a[c]+=x;}
         else {if (a[c]<0) a[c]-=x;else a[c]+=x;}
        if (fh(ac)!=fh(a[c])) f*=-1;
        Q.push(mp(wabs(a[c]),c)); 
    }
    
    printf("%I64d",a[1]);
    for (i=2;i<=n;i++) printf(" %I64d",a[i]);
    printf("\n");
    
    return 0;
}