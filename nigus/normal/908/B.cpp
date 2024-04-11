#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T;


ll M[51][51] = {0};

ll DX[4] = {1,0,-1,0};
ll DY[4] = {0,1,0,-1};

bool inbounds(ll i, ll j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> m;

    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;

    for(ll c1 = 0; c1 < n; c1++){
        string s;
        cin >> s;
        for(ll c2 = 0; c2 < m; c2++){
            if(s[c2] == '#')M[c1][c2] = 1;
            if(s[c2] == 'S'){x1 = c1;y1 = c2;}
            if(s[c2] == 'E'){M[c1][c2] = 2;}
        }
    }

    vector<ll> ind;
    for(ll c1 = 0; c1 < 4; c1++){
        ind.push_back(c1);
    }

    ll ans = 0;
    string s2;
    cin >> s2;
    k = s2.length();
    for(ll c1 = 0; c1 < 24; c1++){
        ll i = x1;
        ll j = y1;
        for(ll c2 = 0; c2 < k; c2++){
            a = s2[c2]-'0';
            i += DX[ind[a]];
            j += DY[ind[a]];
            if(!inbounds(i,j))break;
            if(M[i][j] == 1)break;
            if(M[i][j] == 2){ans++;break;}
        }

        next_permutation(all(ind));
    }

    cout << ans << "\n";

    return 0;
}