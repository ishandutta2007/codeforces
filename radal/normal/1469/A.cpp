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
typedef pair<int,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int n = s.size();
        if (n %2 || s[0] == ')' || s[n-1] == '('){
            cout << "NO" << endl;
            continue;
        }
        int cnt = 0;
        bool f = 0;
        rep(i,0,n){
            if (s[i] == '?'){
                if (cnt < n/2-1 && !f || (cnt < n/2 && f)){
                    s[i] = '(';
                    cnt++;
                }
                else{
                    s[i] = ')';
                }
            }
            else if (s[i] == '('){
                f = 1;
                cnt++;
            }
        }
        stack <char> st;
        rep(i,0,n){
            if (s[i] == ')' && !st.empty() && st.top() == '(') st.pop();
            else st.push(s[i]);
        }
        st.empty() ? cout << "yes" << endl : cout << "NO" << endl;
    }
    return 0;
}