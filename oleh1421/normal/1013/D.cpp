#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int dsu[400001];
int dsu_find(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=dsu_find(dsu[x]);
}
int res=0;
void unite(int x,int y){
     if (dsu_find(x)!=dsu_find(y)){
         dsu[dsu_find(x)]=dsu_find(y);
         res--;
     }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,q;cin>>n>>m>>q;
    for (int i=1;i<=n+m;i++) dsu[i]=i;
    res=n+m;
    while (q--){
        int r,c;cin>>r>>c;
        c+=n;
        unite(r,c);
    }
    cout<<res-1;
    return 0;
}
//2 6 -2 -6  2