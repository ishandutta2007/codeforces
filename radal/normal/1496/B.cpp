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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const long long int N=1e5+10,mod = 17,inf=4e18,maxm = 1000;
const long double eps = 0.0001;
ll poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    long long ans = poww(a,k/2);
    ans *= ans;
    ans %= mod;
    if (k%2){
        ans*=a;
        ans %= mod;
    }
    return ans;
}
set<int> st;
int main(){
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        st.clear();
        rep(i,0,n){
            int x;
            cin >> x;
            st.insert(x);
        }
        n = st.size();
        if (!k){
            cout << n << endl;
            continue;
        }
        bool f = 0;
        int i = 0;
        for (auto it = st.begin(); it != st.end(); it++){
            if (*it != i) f=1;
            i++;
        }
        if (!f){
            cout << n+k<<endl;
            continue;
        }
        int mex = 0,mx = *(st.rbegin());
        rep(i,0,n+1){
            if (st.find(i) == st.end()){
                mex = i;
                break;
            }
        }
        int x = (mx+mex)/2+(mx+mex)%2;
        if (x == mex){
            cout << n+k << endl;
            continue;
        }
        if (st.find(x) == st.end()){
            cout << n+1 << endl;
        }
        else cout << n << endl;
    }
    return 0;
}