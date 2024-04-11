#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 3e5+20,mod = 1e9+7,inf = 1e18+10,sq = 500;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
string s[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        bool ok = 0;
        set<string> st;
        rep(i,0,n){
            cin >> s[i];
            if (s[i].size() == 1)
                ok = 1;
            else if (s[i].size() == 2 && s[i][0] == s[i][1]) ok = 1;
            else if (s[i].size() == 3 && s[i][0] == s[i][2]) ok = 1;
            if (!ok) st.insert(s[i]);
        }
        if (ok){
            cout << "YES" << endl;
            continue;
        }
        set<string> st2;
        rep(i,0,n){
            reverse(s[i].begin(),s[i].end());
            if (st.find(s[i]) != st.end()){
                ok = 1;
                break;
            }
            reverse(s[i].begin(),s[i].end());
            if (s[i].size() == 2) st2.insert(s[i]);
            else{
                string t = "";
                t += s[i][2];
                t += s[i][1];
                if (st2.find(t) != st2.end()){
                    ok = 1;
                    break;
                }
            }
        }
        if (ok){
            cout << "YES" << endl;
            continue;
        }
        st2.clear();
        repr(i,n-1,0){
            if (s[i].size() == 2){
                st2.insert(s[i]);
            }
            else{
                string t = "";
                t += s[i][1];
                t += s[i][0];
                if (st2.find(t) != st2.end()){
                    ok = 1;
                    break;
                }
            }
        }
        cout << ((ok) ? "YES"  : "NO") << endl;
    }
}