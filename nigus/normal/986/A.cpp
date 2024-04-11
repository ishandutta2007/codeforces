#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q,p;
ll T;

ll s;

vector<vi> C(100001, vi());
vi A;

int dist[100001][101] = {0};

vi B;

void bfs(int c){
    queue<int> Q;
    for(int c1 = 0; c1 < n; c1++){
        if(A[c1] == c){
            Q.push(c1);
            dist[c1][c] = 1;
        }
    }
    while(!Q.empty()){
        int a = Q.front();
        Q.pop();
        for(int c1 = 0; c1 < sz(C[a]); c1++){
            int b = C[a][c1];
            if(dist[b][c] == 0){
                dist[b][c] = dist[a][c]+1;
                Q.push(b);
            }
        }
    }
    return;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    cin >> n >> m >> k >> s;

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        a--;
        A.push_back(a);
    }

    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    for(int c1 = 0; c1 < k; c1++){
        bfs(c1);
    }



    for(int c1 = 0; c1 < n; c1++){
        B.clear();
        for(int c2 = 0; c2 < k; c2++){
            B.push_back(dist[c1][c2]-1);
        }
        sort(all(B));
        a = 0;
        for(int c2 = 0; c2 < s; c2++){
            a += B[c2];
        }
        cout << a << " ";
    }

    return 0;
}