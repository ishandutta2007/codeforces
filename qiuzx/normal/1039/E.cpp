#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n,w,q,a[N],ans[N],mx[N],mn[N],qry[N];
int main(){scanf("%d%d%d",&n,&w,&q);for(register int i=1;i<=n;i++) scanf("%d",&a[i]);for(register int i=1;i<=q;i++) scanf("%d",&qry[i]),qry[i]=w-qry[i],mn[i]=mx[i]=a[1];for(register int j=2;j<=n;j++) for(register int i=1;i<=q;++i) mx[i]=(mx[i]>a[j]?mx[i]:a[j]),mn[i]=(mn[i]<a[j]?mn[i]:a[j]),mx[i]-mn[i]<=qry[i]?:(mx[i]=mn[i]=a[j],ans[i]++);for(register int i=1;i<=q;i++) printf("%d\n",ans[i]);return 0;}