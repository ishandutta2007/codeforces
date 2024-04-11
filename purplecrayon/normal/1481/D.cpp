#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n, m; cin >> n >> m;
    //a, b
    vector<string> g(n);
    for (auto& it : g) cin >> it;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) if (i != j && g[i][j] == g[j][i]){
            cout << yes;
            for (int k = 0; k < m+1; k++) cout << (k&1?i+1:j+1) << ' ';
            cout << '\n';
            return;
        }
    }
    if (m&1){
        cout << yes;
        int i=0, j=1;
        for (int k = 0; k < m+1; k++) cout << (k&1?i+1:j+1) << ' ';
        cout << '\n';
        return;
    }
    //aba
    //
    //1->2->3->1
    //
    //a
    //

    bool done=0;
    auto test = [&](int in, int mid, int out){
        if (done) return;
        if (in == -1 || mid == -1 || out == -1) return;
        cout << yes;
        
        if (g[in][mid] == g[mid][out] && g[mid][out] == g[out][in]){
            for (int i = 0; i < m+1; i++){
                if (i%3 == 0) cout << in+1;
                else if (i%3 == 1) cout << mid+1;
                else if (i%3 == 2) cout << out+1;
                else assert(false);
                cout << ' ';
            }
            cout << '\n';
            done=1;
            return;
        }
        int nm_rep = (m-2)/2;

        if (nm_rep%2 == 1){
            vector<int> ans;
            for (int i = 0; i < nm_rep+1; i++)
                if (i%2 == 0) ans.push_back(out);
                else ans.push_back(in);
            
            ans.push_back(mid), ans.push_back(out);
            for (int i = 0; i < nm_rep; i++)
                if (i%2 == 0) ans.push_back(in);
                else ans.push_back(out);

            assert(sz(ans) == m+1);
            for (auto& it : ans) cout << (it+1) << ' ';
            cout << '\n';
            done=1;
            return;
        }
        if (nm_rep%2 == 0){
            vector<int> ans;
            for (int i = 0; i < nm_rep+1; i++)
                if (i%2 == 1) ans.push_back(out);
                else ans.push_back(in);
            
            ans.push_back(mid), ans.push_back(out);
            for (int i = 0; i < nm_rep; i++)
                if (i%2 == 0) ans.push_back(in);
                else ans.push_back(out);

            assert(sz(ans) == m+1);
            for (auto& it : ans) cout << (it+1) << ' ';
            cout << '\n';
            done=1;
            return;
        }
    };
    for (int i = 0; i < n; i++){
        int ao=-1, bo=-1, ai=-1, bi=-1;
        for (int j = 0; j < n; j++) if (i != j){
            if (g[i][j] == 'a') ao=j;
            else if (g[i][j]=='b') bo=j;
            else assert(false);
        }
        for (int j = 0; j < n; j++) if (i != j){
            if (g[j][i] == 'a') ai=j;
            else if (g[j][i]=='b') bi=j;
            else assert(false);
        }
        test(ai, i, ao);
        test(bi, i, bo);
    }
    //a->a
    if (!done) cout << no;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}