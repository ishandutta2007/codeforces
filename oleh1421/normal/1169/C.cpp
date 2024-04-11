#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[300001];
bool ok(int x){
    int last=0;
    for (int i=1;i<=n;i++){
        int maxx=0;
        maxx=min(m-1,a[i]+x);
        if (maxx<last) return 0;
        if (a[i]>last && ((a[i]+x)%m<last || a[i]+x<m)) last=a[i];

    }
    return 1;
}
int main() {
   cin>>n>>m;
   for (int i=1;i<=n;i++) cin>>a[i];
   ll l=0ll;
   ll r=m-1ll;
   while (r-l>1){
        ll m=(l+r)/2ll;
        if (ok(m)) r=m;
        else l=m;
   }
   if (ok(l)) cout<<l;
   else cout<<r;
   return 0;
}
/*
6 7
1 2
2 3
1 3
4 5
5 6
4 6
3 4
*/