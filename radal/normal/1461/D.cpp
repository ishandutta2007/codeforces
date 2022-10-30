#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
//#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
typedef pair<int,int> pll;
const long long int N=1e5+30,inf = 1e9;
set <int> st;
vector <int> a;
void qsort(vector<int> ve){
    int mx = -inf, mi = inf,sum = 0;
    for (int u : ve){
        mx = max(mx,u);
        mi = min(mi,u);
        if (sum < 1e9+1000) sum += u;
    }
    if (sum <= 1e9) st.insert(sum);
    if (mi == mx) return;
    vector <int> ve1,ve2;
    for (int u : ve){
        if (u <= (mx+mi)/2) ve1.pb(u);
        else ve2.pb(u);
    }
    qsort(ve1);
    qsort(ve2);
    return;
    
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,q;
        st.clear();
        a.clear();
        cin >> n >> q;
        rep(i,0,n){
            int x;
            cin >> x;
            a.pb(x);
        }
        qsort(a);
        rep(i,0,q){
            int s;
            cin >> s;
            if (st.find(s) == st.end()) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    return 0;
}