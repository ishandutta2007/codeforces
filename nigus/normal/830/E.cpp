#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
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

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 300001;

vector<vi> C(MAXN, vi());
ll A[MAXN] = {0};

int CC[MAXN] = {0};
int cc = 0;

bool comp(ll i, ll j){
    return sz(C[i]) > sz(C[j]);
}

bool mark1[MAXN] = {0};
int par[MAXN] = {0};
vi I;
int cyc1 = -1;
int cyc2 = -1;

void dfs1(int i){
    CC[i] = cc;
    if(mark1[i])return;
    mark1[i] = 1;
    I.push_back(i);
    trav(y, C[i]){
        if(y == par[i])continue;
        if(mark1[y]){
            if(cyc1 == -1){
                cyc1 = i;
                cyc2 = y;
            }
            continue;
        }
        par[y] = i;
        dfs1(y);
    }
}

bool mark2[MAXN] = {0};
void dfs2(int i){
    if(mark2[i])return;
    mark2[i] = 1;
    trav(y, C[i]){
        if(!mark2[y]){
            par[y] = i;
            dfs2(y);
        }
    }
}

void fill_path(int from, int to, int with){
    while(1){
        A[from] = with;
        if(from == to)break;
        from = par[from];
    }
}

void fill_around(int i, int x, int with){
    trav(y, C[i]){
        if(A[y] == 0 && x > 0){
            A[y] = with;
            x--;
        }
    }
}


map<ll, pii> M;

pii dp(ll i, ll prev, ll par){
    if(prev <= 1 && sz(C[i]) != 3)return {0,0};
    ll h = i*n*1234 + prev*n + par;
    if(M.find(h) != M.end())return M[h];
    ll lim = prev;
    if(sz(C[i]) == 3)lim = 11;
    pii best = {-big,0};
    rep(val,0,lim){
        if(val == 0 && sz(C[i]) == 3)continue;
        int num = val*prev - val*val;
        trav(y, C[i]){
            if(y != par){
                num += dp(y, val, i).first;
            }
        }
        if(num > best.first)best = {num, val};
    }
    M[h] = best;
    return best;
}

void get_ans(ll i, ll prev, ll par){
    ll h = i*n*1234 + prev*n + par;
    if(M.find(h) == M.end())return;
    pii nxt = M[h];
    A[i] = nxt.second;
    trav(y, C[i]){
        if(y != par){
            get_ans(y, A[i], i);
        }
    }
}

void print_ans(){
    cout << "YES\n";
    rep(c1,0,n){
        if(CC[c1] != cc)A[c1] = 0;
        cout << A[c1] << " ";
    }cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(_,0,T){
        cin >> n >> m;
        rep(c1,0,n){
            C[c1].clear();
            mark1[c1] = 0;
            mark2[c1] = 0;
            A[c1] = 0;
            par[c1] = -1;
            CC[c1] = cc;
        }
        M.clear();
        rep(c1,0,m){
            cin >> a >> b;
            a--;
            b--;
            C[a].push_back(b);
            C[b].push_back(a);

        }
        bool solved = 0;
        rep(c1,0,n){
            if(!mark1[c1]){
                I.clear();
                cyc1 = -1;
                cyc2 = -1;
                dfs1(c1);
                if(cyc1 != -1){
                    fill_path(cyc1, cyc2, 1);
                    print_ans();
                    solved = 1;
                    break;
                }
                sort(all(I), comp);
                int i = I[0];
                if(sz(I) <= 1)continue;
                int j = I[1];
                if(sz(C[i]) <= 2){
                    continue;
                }
                if(sz(C[i]) > 3){
                    A[i] = 2;
                    fill_around(i, 4, 1);
                    print_ans();
                    solved = 1;
                    break;
                }
                if(sz(C[j]) < 3){
                    pii thing = dp(i, 0, -1);
                    if(thing.first >= 0){
                        get_ans(i, 0, -1);
                        print_ans();
                        solved = 1;
                        break;
                    }

                    trav(y, I){
                        A[y] = 0;
                    }
                    continue;
                }
                dfs2(i);
                fill_path(j, i, 2);
                fill_around(i, 2, 1);
                fill_around(j, 2, 1);
                print_ans();
                solved = 1;
                break;
            }
        }

        if(!solved){
            cout << "NO\n";
        }
    }

    return 0;
}