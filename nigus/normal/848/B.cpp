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

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k,q,p,w,h;

vector<ll> X;
vector<ll> Y;
vector<ll> ind;
vector<ll> kind;

vector<ll> XI;
vector<ll> YI;

ll ANSX[200001] = {0};
ll ANSY[200001] = {0};
ll STOPX[200001] = {0};
ll STOPY[200001] = {0};

bool compx(ll i, ll j){
    return X[i] < X[j];
}

bool compy(ll i, ll j){
    return Y[i] < Y[j];
}

bool compsum(ll i, ll j){
    return X[i]+Y[i] < X[j]+Y[j];
}

void solvec(){
    sort(all(XI),compx);
    sort(all(YI),compy);
    vector<ll> TOT;
    vector<ll> TOT2;
    for(ll c1 = 0; c1 < sz(XI); c1++){
        TOT.push_back(XI[c1]);
    }
    for(ll c1 = 0; c1 < sz(YI); c1++){
        TOT.push_back(YI[sz(YI)-c1-1]);
    }
    for(ll c1 = 0; c1 < sz(YI); c1++){
        TOT2.push_back(YI[sz(YI)-c1-1]);
    }
    for(ll c1 = 0; c1 < sz(XI); c1++){
        TOT2.push_back(XI[c1]);
    }
    for(ll c1  = 0; c1 < sz(TOT); c1++){
        ANSX[TOT2[c1]] = STOPX[TOT[c1]];
        ANSY[TOT2[c1]] = STOPY[TOT[c1]];
    }
}

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> w >> h;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a >> b >> c;
        if(a == 1){
            X.push_back(b);
            Y.push_back(-c);
            STOPX[c1] = b;
            STOPY[c1] = h;
        }
        else{
            X.push_back(-c);
            Y.push_back(b);
            STOPX[c1] = w;
            STOPY[c1] = b;
        }
        //cout <<c1 << "  " << X[c1]+Y[c1] << "  gg\n";

        kind.push_back(a);
        ind.push_back(c1);
    }
    sort(all(ind),compsum);
    ll prev = X[ind[0]] + Y[ind[0]];
    vector<ll> CURR;
    for(ll c1 = 0; c1 < n; c1++){
        a = ind[c1];
        ll xy = X[ind[c1]] + Y[ind[c1]];
        if(xy != prev){
            solvec();
            XI.clear();
            YI.clear();
        }
        if(kind[a] == 1){
            XI.push_back(a);
        }
        else{
            YI.push_back(a);
        }
        prev = xy;
    }
    if(sz(XI)+sz(YI) != 0){
        solvec();
    }

    for(ll c1 = 0; c1 < n; c1++){
        cout << ANSX[c1] << " " << ANSY[c1] << "\n";
    }

    return 0;
}