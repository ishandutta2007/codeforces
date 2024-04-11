//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=301019;
const ll mod=1000000007ll;
int p[N],q[N];
map<pair<int,int>,int>mp;
vector<int>g[N];
bool del[N];
void solve(){
    ll n,k;cin>>n>>k;
    ll sum=((n+k-1)/k)*k;
    cout<<(sum+n-1)/n<<endl;



}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*

*/