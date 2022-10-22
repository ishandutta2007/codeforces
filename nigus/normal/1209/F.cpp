#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 1000001;

vector<vi> C(MAXN, vi());
vector<vi> CW(MAXN, vi());
vector<vi> E(MAXN, vi());


ll now = 0;

ll ANS[MAXN] = {0};

ll DIST[MAXN] = {0};
bool mark[MAXN] = {0};

ll cc = 0;
bool comp(ll i, ll j){
    return CW[cc][i] < CW[cc][j];
}

void add_edge(int i,int j, int num){
    ll now2 = j;
    ll num3 = num;
    ll num2 = 0;

    while(num3 > 0){
        num2 = num2*10+num3%10;
        num3 /= 10;
    }

    while(num >= 10){
        C[now].push_back(now2);
        C[now2].push_back(now);
        CW[now].push_back(num%10);
        CW[now2].push_back(num2%10);
        E[now].push_back(sz(E[now]));
        E[now2].push_back(sz(E[now2]));
        num /= 10;
        num2 /= 10;
        now2 = now;
        now++;
    }
    C[i].push_back(now2);
    C[now2].push_back(i);
    CW[i].push_back(num%10);
    CW[now2].push_back(num2%10);
    E[i].push_back(sz(E[i]));
    E[now2].push_back(sz(E[now2]));

}

bool mark2[MAXN] = {0};

void solve(ll digit, vi & nodes){
    vi temp;
    //vector<vi> temps(10, vi());
    trav(i, nodes){
        rep(c1,0,sz(C[i])){
            ll bb = C[i][c1];
            if(CW[i][c1] == digit && mark2[bb] == 0 && DIST[bb] == DIST[i]+1){
                mark2[bb] = 1;
                ANS[bb] = (10*ANS[i]+digit)%big;
              //  cerr << bb+1 << " " << i+1 << " --  " << ANS[bb] << "\n";
                temp.push_back(bb);
            }
        }
    }
    if(sz(temp) == 0)return;
    rep(c1,0,10){
        solve(c1,temp);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m;
    now = n;

    rep(c1,0,m){
        cin >> a >> b;
        //a = c1+1;
       // b = c1+2;
        a--;
        b--;
        add_edge(a,b,c1+1);
       // cerr << c1+1 << ": " << a+1 << " " << b+1 << " edge\n";
    }
    /*
    rep(c1,0,m-n){
        a = rand()%n;
        b = rand()%n;
        if(a == b)continue;
        add_edge(a,b,c1+1+n);
       // cerr << c1+n+1 << ": " << a+1 << " " << b+1 << " edge\n";
    }
*/
    rep(c1,0,now){
        ANS[c1] = -1;
        DIST[c1] = -1;
        cc = c1;
        sort(all(E[c1]),comp);
    }


    DIST[0] = 0;
    ANS[0] = 0;

    queue<ll> Q;
    Q.push(0);
    while(!Q.empty()){
        a = Q.front();
        Q.pop();
        rep(c1,0,sz(C[a])){
            b = C[a][c1];
            if(DIST[b] == -1){
                DIST[b] = 1 + DIST[a];
                Q.push(b);
            }
        }
    }

    mark2[0] = 1;
    rep(c1,0,10){
        vi temp;
        temp.push_back(0);
        solve(c1,temp);
    }

    rep(c1,1,n){
        cout << ANS[c1] << "\n";
    }

    return 0;
}