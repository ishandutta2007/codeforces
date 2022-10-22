#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
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

ll n,m,T,k,d;
const ll big = 1000000007;

vector<vi> C(300001, vi());

vl X;
vl Y;
vi ind;
vl CSX;
vl CSY;

ll ANS[300001] = {0};

bool comp(int i, int j){
    return X[i]-Y[i] < X[j]-Y[j];
}

ll score(int i, int j){
    return min(X[i]+Y[j],X[j]+Y[i]);
}

ll brute(ll i){
    ll res = 0;
    for(int c1 = 0; c1 < n; c1++){
        if(c1 != i)res += score(i,c1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m;

  //  n = 300001;
  //  m = 0;

    ll sumy = 0;
    ll sumx = 0;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
      //  a = rand()*RAND_MAX+rand();
       // b = rand();
        X.push_back(a);
        Y.push_back(b);
        ind.push_back(c1);
        sumx+=a;
    }
    sort(all(ind),comp);
    reverse(all(ind));
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    for(int c1 = 0; c1 < n; c1++){
        a = ind[c1];
        sumx -= X[a];

        ANS[a] = sumx+sumy+Y[a]*(n-c1-1)+X[a]*c1;

       // c = brute(a);
       // if(c != ANS[a])cerr << "HJKHJKH\n";

        for(int c2 = 0; c2 < sz(C[a]); c2++){
            ANS[a] -= score(a,C[a][c2]);
        }

        sumy += Y[a];
    }
    for(int c1 = 0; c1 < n; c1++){
        cout << ANS[c1] << " ";
    }

    return 0;
}