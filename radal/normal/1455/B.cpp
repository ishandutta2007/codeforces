#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef pair<int,int> pll;
const long long int N=1e7+30,mod = 1e9+7,inf=2e5;
const long double eps = 0.0001;
int dp[N];

int main(){
    int T;
    cin >> T;
    while (T--){
        int x;
        ll mi=inf;
        cin >> x;
        ll ans = 1;
        while (ans*(ans+1)/2 < x){
            int i = (x-ans*(ans+1)/2);
            int f = 0;
            if (ans > 1 && i % (ans-1)) f++;
            if (ans > 1) i = i/(ans-1) + f;
            if (ans*(ans+1)/2 + i*ans-i >= x)mi = min(mi,i+ans);
            ans++;
        }
        mi = min(mi,ans*(ans+1)/2-x+ans);
        cout << mi << endl;

    }
    return 0;
}