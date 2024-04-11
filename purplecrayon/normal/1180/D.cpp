#include <bits/stdc++.h>

#define int long long

#define pii pair<int, int>

#define x1 x1228
#define y1 y1228

#define left left228
#define right right228

#define pb push_back
#define eb emplace_back

#define mp make_pair                                                                

#define ff first                                                                  
#define ss second   

#define matr vector<vector<int> > 

#define all(x) x.begin(), x.end()


using namespace std;
typedef long long ll; 
typedef long double ld; 
                                                                                                   
const int maxn = 3e5 + 7, mod = 1e9 + 7, inf = 1e18, MAXN = 1e6 + 7;
const double eps = 1e-9;
mt19937 rnd(time(0));
int n, m; 

void solve() {        
    cin >> n >> m; 
    if (n == 2 && m == 3) {
        cout << "1 1\n1 3\n1 2\n2 2\n2 3\n2 1"; 
        return; 
    }
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << i+1 << " " << j+1 << '\n';
            cout << n - i - 1+1 << " " << m - j - 1+1 << '\n';             
        }
    }                      
    if (n % 2) {          
        int x = n / 2;
        deque<int> have; 
        cout << x+1 << " " << 1 << '\n'; 
        for (int i = 1; i < m; ++i) {
            have.pb(i);         
        } 
        while (have.size()) {
            cout << x+1 << " "  << have.back()+1 << '\n'; 
            have.pop_back(); 
            if (have.size()) {
                cout << x+1 << " " << have.front()+1 << '\n'; 
                have.pop_front(); 
            }
        }                
    }
}                                
   
signed main() {
#ifdef LOCAL1
    freopen("TASK.in", "r", stdin);
    freopen("TASK.out", "w", stdout);
#else 
    
#endif // LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20); 
    cout << fixed; 
    int t = 1; 
    for (int i = 0; i < t; ++i) {              
        solve();
    }
    return 0;
}