#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

li n, mod = 998244353, ans = 1, sum=1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=2; i<=n; i++){
        ans = (ans*i)%mod;
    }
    ans = (ans*n)%mod;
    for (int i=n; i>1; i--){
        sum = (sum*i)%mod;
        ans = (ans - sum + mod)%mod;
    }
    cout << ans;
}