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
typedef pair<int,int> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 3e5+20;
ll poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (r*r)%mod*poww(n,k&1)%mod;
}
int a[N],cnt[N];
ll dp[N];
int main(){
    int n;
    cin >> n;
    multiset<int> st;
    rep(i,0,n){
        cin >> a[i];
        if (!i){
            if (a[i] >= 0){
                dp[i] = a[i];
                cnt[i] = 1;
                st.insert(a[i]);
            }
        }
        else{
            dp[i] = dp[i-1];
            cnt[i] = cnt[i-1];
            if (a[i] >= 0){
                dp[i] += a[i];
                cnt[i]++;
                st.insert(a[i]);
            }
            else{
                if (dp[i]+a[i] >= 0){
                    dp[i] += a[i];
                    cnt[i]++;
                    st.insert(a[i]);
                }
                else{
                    if (st.empty()) continue;
                    int val = *(st.begin());
                    if (val < a[i]){
                        st.erase(st.begin());
                        st.insert(a[i]);
                        dp[i] += (a[i]-val);
                    }
                }
            }
        }
    }
    cout << cnt[n-1];
    return 0;
}