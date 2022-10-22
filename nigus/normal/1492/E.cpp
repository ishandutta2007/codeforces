#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
ll random2(){
    return (1ll << 31ll)*eng()+eng();
}
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;
const int MAXN = 250001;

int n,m;

vector<vi> grid2(MAXN, vi());
vector<vi> grid(MAXN, vi());

vi diff;

pii get_ors(vector<pii> &ors){
    if(sz(ors) == 0)return {42, 42};
    int a = ors[0].first;
    int b = -1;
    rep(c1,1,sz(ors)){
        if(ors[c1].first != a){
            if(b == -1){
                b = ors[c1].second;
            }
            if(b != ors[c1].second){
                a = -1;
                break;   
            }
        }
    }
    if(a != -1){
        if(b == -1)b = 42;
        return {a, b};
    }


    a = -1;
    b = ors[0].second;
    rep(c1,1,sz(ors)){
        if(ors[c1].second != b){
            if(a == -1){
                a = ors[c1].first;
            }
            if(a != ors[c1].first)return {-1, -1};
        }
    }
    if(a == -1)a = 42;
    return {a, b};
}

set<int> inds;

vi ans;
bool test(int x, int y){
    vector<pii> ors;
    int a1 = -1;
    int a2 = -1;
    rep(c1,1,n){
        int d = diff[c1] - (grid[c1][x] != grid[0][x]) - (grid[c1][y] != grid[0][y]);
        if(d > 2)return 0;
        if(d == 2){
            int b1 = grid[c1][x];
            int b2 = grid[c1][y];
            if(a1 != -1 && (a1 != b1 || a2 != b2))return 0;
            a1 = b1;
            a2 = b2;
        }
        if(d == 1){
            int b1 = grid[c1][x];
            int b2 = grid[c1][y];
            if(a1 != -1 && (a1 != b1 && a2 != b2))return 0;
            ors.push_back({b1, b2});
        }
    }

    pii res;
    trav(p, ors){
        if(a1 != -1 && (a1 != p.first && a2 != p.second))return 0;
    }
    res = get_ors(ors);
    if(res.first == -1)return 0;
    rep(c1,0,m){
        ans.push_back(grid[0][c1]);
    }
    if(sz(ors) > 0){
        ans[x] = res.first;
        ans[y] = res.second;
    }
    if(a1 != -1){
        ans[x] = a1;
        ans[y] = a2;
    }
    return 1;
    
}

bool test0(){
    rep(c1,1,n){
        if(diff[c1] > 2)return 0;
    }
    rep(c1,0,m){
        ans.push_back(grid[0][c1]);
    }
    return 1;
}

bool test1(int i){
    int fix = -1;
    rep(c1,1,n){
        int d = diff[c1] - (grid[c1][i] != grid[0][i]);
        if(d > 2)return 0;
        if(d == 2){
            if(fix != -1 && grid[c1][i] != fix)return 0;
            fix = grid[c1][i];
        }
    }
    rep(c1,0,m){
        ans.push_back(grid[0][c1]);
    }
    if(fix == -1)fix = 12;
    ans[i] = fix;
    return 1;
}

int old_m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    old_m = m;
    rep(c1,0,n){
        rep(c2,0,m){
            int a;
            cin >> a;
            grid2[c1].push_back(a);
        }
    }
    rep(c2,0,m){
        int a = grid2[0][c2];
        bool yes = 1;
        rep(c1,1,n){
            if(grid2[c1][c2] != a)yes = 0;
        }
        if(!yes){
            rep(c1,0,n){
                grid[c1].push_back(grid2[c1][c2]);
            }
            inds.insert(c2);
        }
   
    }
    m = sz(grid[0]);

    if(m > 2*n){
        cout << "No\n";
        return 0;
    }

    rep(c1,0,n){
        int a = 0;
        rep(c2,0,m){
            if(grid[c1][c2] != grid[0][c2])a++;
        }
        diff.push_back(a);
    }

    bool tmp1 = test0();
    if(tmp1){
        cout << "Yes\n";
        goto label;
    }

    rep(c1,0,m){
        bool tmp;
        tmp = test1(c1);
        if(tmp){
            cout << "Yes\n";
            goto label;
        }
        rep(c2,c1+1,m){
            tmp = test(c1,c2);
            if(tmp){
                cout << "Yes\n";
                goto label;
            }
        }
    }
    
    cout << "No\n";
    return 0;

    label:

    int i = 0;
    rep(c1,0,old_m){
        if(inds.find(c1) !=  inds.end()){
            cout << ans[i] << " ";
            i++;
        }
        else{
            cout << grid2[0][c1] << " ";
        }
    }cout << "\n";
    

    return 0;
}