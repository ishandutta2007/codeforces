#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
#pragma GCC optimize("unroll-loops,O3")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k /= 2;
    } 
    return z; 
}

int n,m;
int a[N];
set<pll> st;

ll calc(int l,int r){ // [ ) 
    ll ans = 0;
    ans += 1ll*l*(n-r);
    ans += 1ll*(r-l)*(n-r);
    ans += 1ll*(r-l)*l;
    ans += 1ll*(r-l)*(r-l+1)/2;

    return ans;
}

void solve(){
    cin >> n >> m;
    rep(i,0,n)
        cin >> a[i];

    ll ans = 0;

    rep(i,0,n){
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        ans += calc(i,j);
        st.insert({i,j});
        i = j-1;
    }

    while (m--){
        int i,x;
        cin >> i >> x;
        i--;
        if (a[i] == x){
            cout << ans << endl;
            continue;
        }
        auto it = st.lower_bound({i+1,0});
        it--;
        auto p = (*it);
        if (i > p.X && i < p.Y-1){
            st.erase(p);
            ans -= calc(p.X,p.Y);
            st.insert({p.X,i});
            st.insert({i,i+1});
            st.insert({i+1,p.Y});
            ans += calc(p.X,i)+calc(i,i+1)+calc(i+1,p.Y);
            cout << ans << endl;
            a[i] = x;
            continue;
        }
        if (p.Y-p.X == 1){
            if ((!i || a[i-1] != x) && (i == n-1 || a[i+1] != x)){
                a[i] = x;
                cout << ans << endl;
                continue;
            }
            a[i] = x;
            st.erase(p);
            ans -= calc(p.X,p.Y);
            if (i && a[i-1] == x && i < n-1 && a[i+1] == x){
                it = st.lower_bound({i,0});
                it--;
                auto u = (*it);
                it++;
                auto v = (*it);
                ans -= calc(u.X,u.Y);
                ans -= calc(v.X,v.Y);
                st.erase(u);
                st.erase(v);
                st.insert({u.X,v.Y});
                ans += calc(u.X,v.Y);
                cout << ans << endl;
                continue;
            }
            if (i && a[i-1] == x){
                it = st.lower_bound({i,0});
                it--;
                auto u = (*it);
                st.erase(u);
                ans -= calc(u.X,u.Y);
                st.insert({u.X,i+1});
                ans += calc(u.X,i+1);
                cout << ans << endl;
                continue;
            }
            if (i < n-1 && a[i+1] == x){
                it = st.lower_bound({i,0});
                auto v = (*it);
                ans -= calc(v.X,v.Y);
                st.erase(v);
                st.insert({i,v.Y});
                ans += calc(i,v.Y);
                cout << ans << endl;
                continue;
            }
        }
        if (i == p.X){
            st.erase(p);
            ans -= calc(i,p.Y);
            st.insert({i+1,p.Y});
            ans += calc(i+1,p.Y);
            a[i] = x;
            if (!i || a[i] != a[i-1]){
                st.insert({i,i+1});
                ans += calc(i,i+1);
                cout << ans << endl;
                continue;
            }
            auto it = st.lower_bound({i,0});
            it--;
            auto u = (*it);
            ans -= calc(u.X,u.Y);
            ans += calc(u.X,i+1);
            st.erase(u);
            st.insert({u.X,i+1});
            cout << ans << endl;
            continue;
        }
        st.erase(p);
        st.insert({p.X,i});
        ans -= calc(p.X,p.Y);
        ans += calc(p.X,i);
        a[i] = x;
        if (a[i] != a[i+1] || i+1 == n){
            st.insert({i,i+1});
            ans += calc(i,i+1);
            cout << ans << endl;
            continue;
        }
        it = st.lower_bound({i,0});
        auto u = (*it);
        ans -= calc(u.X,u.Y);
        ans += calc(i,u.Y);
        st.erase(u);
        st.insert({i,u.Y});
        cout << ans << endl;    
    }

}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
 //   cin >> T;
    while (T--){
        solve();
    }
    return 0;
}