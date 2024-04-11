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

ll n,m,T,k,q;

vector<vector<ll> > fixm(ll c){
    vector<vector<ll> > ANS;
    for(ll c1 = 0; c1 < 16; c1++){
        vector<ll> temp;
        for(ll c2 = 0; c2 < 16; c2++){

            if(c1 > c || c2 > c || abs(c1-c2) > 1){
                temp.push_back(0);
            }
            else{
                temp.push_back(1);
            }
        }
        ANS.push_back(temp);
    }
    return ANS;
}

vector<vector<ll> > mul(vector<vector<ll> > &M1, vector<vector<ll> > &M2){
    vector<vector<ll> > ANS;
    for(ll c1 = 0; c1 < 16; c1++){
        vector<ll> temp;
        for(ll c2 = 0; c2 < 16; c2++){
            ll a = 0;
            for(ll c3 = 0; c3 < 16; c3++){
                a += M1[c1][c3]*M2[c3][c2];
                a %= big;
            }
            temp.push_back(a);
        }
        ANS.push_back(temp);
    }
    return ANS;
}

vector<vector<ll> > pow(vector<vector<ll> > M1, ll i){
    vector<vector<ll> > ANS;
    if(i == 0){
        for(ll c1 = 0; c1 < 16; c1++){
            vector<ll> temp;
            for(ll c2 = 0; c2 < 16; c2++){
                temp.push_back(c1==c2);
            }
            ANS.push_back(temp);
        }
        return ANS;
    }
    if(i%2 == 0){
        vector<vector<ll> > ANS1;
        ANS1 = pow(M1, i/2);
        return mul(ANS1,ANS1);
    }
    vector<vector<ll> > ANS1 = pow(M1,i-1);
    return mul(M1,ANS1);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> k;

    ll X[16] = {0};
    X[0] = 1;

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a >> b >> c;
        if(b > k)b = k;
        for(ll c2 = c+1; c2 < 16; c2++){
            X[c2] = 0;
        }
        vector<vector<ll> > MAT = pow(fixm(c),b-a);
        ll Y[16] = {0};
        for(ll c2 = 0; c2 < 16; c2++){
            a = 0;
            for(ll c3 = 0; c3 < 16; c3++){
                a += MAT[c2][c3]*X[c3];
                a %= big;
            }
            Y[c2] = a;
        }
        for(ll c2 = 0; c2 < 16; c2++){
            X[c2] = Y[c2];
        }

    }
    cout << X[0] << "\n";

    return 0;
}