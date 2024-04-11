#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;

ll n,m,T,k,q;

vector<ll> X;
vector<ll> Y;
vector<ll> ind;

ll start = 0;

bool mark[20000] = {0};
ll DIST[20000] = {0};

ll dis(ll i, ll j){
    if(Y[i] == Y[j] && abs(X[i]-X[j]) <= 1)return 0;
    if(X[i] == X[j] && abs(Y[i]-Y[j]) <= 1)return 0;
    if(abs(X[i]-X[j]) <= 2 || abs(Y[i]-Y[j]) <= 2)return 1;
    return -1;
}

void bfs(){
    deque<ll> Q;
    Q.push_back(start);
    while(!Q.empty()){
        ll a = Q.front();
        Q.pop_front();
        //cout << a << " " << DIST[a] << "\n";
        if(mark[a] == 0){
            for(ll c1 = 0; c1 < k; c1++){
                ll d = dis(a,c1);
                if(d == 0){
                    if(DIST[c1] > DIST[a]+d || DIST[c1] == -1){
                        DIST[c1] = DIST[a]+d;
                        Q.push_front(c1);
                    }
                }
                if(d == 1){
                    if(DIST[c1] > DIST[a]+d || DIST[c1] == -1){
                        DIST[c1] = DIST[a]+d;
                        Q.push_back(c1);
                    }
                }
            }
            mark[a] = 1;
        }
    }
}

ll main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    scanf("%d" , &n);
    scanf("%d" , &m);
    scanf("%d" , &k);
    for(ll c1 = 0; c1 < k; c1++){
        scanf("%d" , &a);
        scanf("%d" , &b);
        a--;
        b--;
        if(a+b==0)start = c1;
        X.push_back(a);
        Y.push_back(b);
        ind.push_back(c1);
        DIST[c1] = -1;
    }
    DIST[start] = 0;
    bfs();

    ll ans = big;

    X.push_back(n-1);
    Y.push_back(m-1);
    ind.push_back(k);

    for(ll c1 = 0; c1 < k; c1++){
        if(DIST[c1] != -1){
            ll d = dis(c1,k);
            if(X[c1] == n-1 && Y[c1] == m-1)ans = min(ans, DIST[c1]);
            if(abs(X[k]-X[c1]) <= 1 || abs(Y[k]-Y[c1]) <= 1)ans = min(ans, DIST[c1]+1);
        }

    }

    if(ans == big){
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }

    return 0;
}