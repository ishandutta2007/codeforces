//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int A=1000001;
const ll mod=1000000007ll;
int a[N];
#define int ll
void solve(){
    int n,k;cin>>n>>k;
    if (n%2==0){
        cout<<(k-1)%n+1<<endl;
    } else {
        int x=(n/2)+1;
        int y=0;

        for (int i=30;i>=0;i--){
            y+=(1<<i);
            if (y-y/x>=k){
//                cout<<y-y/x<<" "<<y<<endl;
                y-=(1<<i);
            }
        }
//        y++;
//        cout<<y-y/x<<endl;
        cout<<y%n+1<<endl;
    }


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;

    while (tt--){
        solve();
    }
    return 0;
}