#include <bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k,q;

ll M[101][101] = {0};

ll ans = 0;

vector<string> SANS;
vector<ll> ANS;

void fixrows(){

for(ll c1 = 0; c1 < n; c1++){
    ll mi = big;
    for(ll c2 = 0; c2 < m; c2++){
        mi = min(mi,M[c1][c2]);
    }
    for(ll c2 = 0; c2 < mi; c2++){
        SANS.push_back("row");
        ANS.push_back(c1+1);
    }
    for(ll c2 = 0; c2 < m; c2++){
        M[c1][c2] -= mi;
    }
}
}

void fixcols(){

for(ll c1 = 0; c1 < m; c1++){
    ll mi = big;
    for(ll c2 = 0; c2 < n; c2++){
        mi = min(mi,M[c2][c1]);
    }
    for(ll c2 = 0; c2 < mi; c2++){
        SANS.push_back("col");
        ANS.push_back(c1+1);
    }
    for(ll c2 = 0; c2 < n; c2++){
        M[c2][c1] -= mi;
    }
}
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m;
    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = 0; c2 < m; c2++){
            cin >> a;
            M[c1][c2] = a;
        }
    }

    if(m > n){
        fixrows();
        fixcols();
    }
    else{
        fixcols();
        fixrows();
    }

    bool nonz = 1;
    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = 0; c2 < m; c2++){
            if(M[c1][c2] != 0)nonz = 0;
        }
    }
    if(!nonz){
        cout << "-1\n";
    }
    else{

        cout << ANS.size() << "\n";

        for(ll c1 = 0; c1 < ANS.size(); c1++){
            cout << SANS[c1] << " " << ANS[c1] << "\n";
        }

    }

    return 0;
}