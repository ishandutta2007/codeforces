//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=100010;
int p[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    int f=1;
    while (f<=n && p[f]==f) f++;
    if (f<=n){
        int r=-1;
        for (int i=f;i<=n;i++){
            if (p[i]==f){
                r=i;
                break;
            }
        }
        reverse(p+f,p+r+1);
    }
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;


}

int32_t  main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;

    while (tt--){
        solve();
    }
    return 0;
}

/**
1
4 2
1 2
1 3
1 4
**/