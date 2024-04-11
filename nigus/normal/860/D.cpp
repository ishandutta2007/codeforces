#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,w,h;

vector<vector<ll> > C(200001, vector<ll>());
vector<vector<ll> > CT(200001, vector<ll>());

vector<vector<ll> > CW(200001, vector<ll>());

bool mark[200001] = {0};

unordered_set<ll> flips;

void dfs(ll i){
    mark[i] = 1;;
    for(ll c1 = 0; c1 < sz(C[i]); c1++){
        ll a = C[i][c1];
        if(mark[a] == 0){
            CT[i].push_back(1);
            dfs(a);
        }
        else{
            CT[i].push_back(0);
        }
    }
}

ll dfs2(ll i, ll par){
    ll c = 0;
    ll ans = 0;
    for(ll c1 = 0; c1 < sz(C[i]); c1++){

        ll a = C[i][c1];
        ll b = CT[i][c1];
        c += CW[i][c1];

        if(b == 1 && a != par){
            ll d = dfs2(a,i);
            ans += d;
            if(d%2 == 1){
                flips.insert(i*1000000 + a);
            }
        }
    }
    return ans+(c%2);
}


int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m;

    for(ll c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);

        c = rand()%2;

        CW[a].push_back(c);
        CW[b].push_back(1-c);

    }

    for(ll c1 = 0; c1 < n; c1++){
        if(mark[c1] == 0){
            dfs(c1);
            dfs2(c1,-1);
        }
    }


    for(ll c1 = 0; c1 < n; c1++){

        for(ll c2 =0 ; c2 < sz(C[c1]); c2++){

            a = 1000000*c1+C[c1][c2];
            b = 1000000*C[c1][c2]+c1;

            if(flips.find(a) != flips.end()){
                CW[c1][c2] = 1-CW[c1][c2];
            }
            if(flips.find(b) != flips.end()){
                CW[c1][c2] = 1-CW[c1][c2];
            }
        }

    }


    vector<ll> A1;
    vector<ll> A2;
    vector<ll> A3;


    for(ll c1 = 0; c1 < n; c1++){
        vector<ll> B;
        for(ll c2 = 0; c2 < sz(C[c1]); c2++){
            if(CW[c1][c2] == 1){
                B.push_back(C[c1][c2]);
            }
        }

        for(ll c2 = 0; c2 < sz(B)-1; c2+=2){
           // cout << B[c2]+1 << " " << c1+1 << " " << B[c2+1]+1 << "\n";
            A1.push_back(B[c2]+1);A2.push_back(c1+1);A3.push_back(B[c2+1]+1);
        }

    }

    cout << sz(A1) << "\n";

    for(ll c1 = 0; c1 < sz(A1); c1++){
        cout << A1[c1] << " " << A2[c1] << " " << A3[c1] << "\n";
    }


    return 0;
}