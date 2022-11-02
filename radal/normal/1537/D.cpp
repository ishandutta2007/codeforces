#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 131072;
bool dp[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    cin >> T;

    while (T--){
        int n;
        cin >> n;
        if (n&1) cout << "Bob" << endl;
        else{
            int cnt = 0;
            while (n%2 == 0){
                n/=2;
                cnt++;
            }
            if (n != 1) cout << "Alice" << endl;
            else{
                if (cnt&1) cout << "Bob" << endl;
                else cout << "Alice" << endl;
            }
        }
    }
}