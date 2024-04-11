//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=500010;
ll a[N];
void solve(){
    int n,m;cin>>n>>m;
    m++;
    int ans=0;
    for (int i=30;i>=0;i--){
        if (n&(1<<i)){
            if (!(m&(1<<i))) break;
        } else {
            if (m&(1<<i)){
                ans^=(1<<i);
            }
        }
    }
    cout<<ans<<endl;

//    x^n>m
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}