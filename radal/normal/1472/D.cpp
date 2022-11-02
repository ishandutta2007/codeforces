#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
ll dp[N],a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        priority_queue<int> even,odd;
        rep(i,0,n){
            cin >> a[i];
            if (a[i]%2) odd.push(a[i]);
            else even.push(a[i]);
        }
        ll sum1=0,sum2=0;
        rep(i,0,n){
            if(i%2){
                if (even.empty() || (!odd.empty() && odd.top() >= even.top())){
                    sum2 += odd.top();
                    odd.pop();
                }
                else{
                    even.pop();
                }
            }
            else{
                if (odd.empty() || (!even.empty() && odd.top() <= even.top())){
                    sum1 += even.top();
                    even.pop();
                }
                else{
                    odd.pop();
                }
            }
        }
        if (sum1 == sum2) cout << "Tie" << endl;
        if (sum1 > sum2) cout << "Alice" << endl;
        if (sum1 < sum2) cout << "Bob" << endl;
    }
    return 0;
}