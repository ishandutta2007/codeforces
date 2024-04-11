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

struct pt{
ll x,y;
};

vector<pt> sq1;

vector<pt> sq2;

vector<ll> dif;
vl sum;

vl X1;
vl Y1;
set<ll> XX;
set<ll> YY;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    for(int c1 = 0; c1 < 4; c1++){
        cin >> a >> b;
        sq1.push_back({a,b});
        if(XX.find(a) == XX.end()){
            XX.insert(a);
            X1.push_back(a);
        }
        if(YY.find(b) == YY.end()){
            YY.insert(b);
            Y1.push_back(b);
        }
    }
    sort(all(X1));
    sort(all(Y1));
    for(int c1 = 0; c1 < 4; c1++){
        cin >> a >> b;
        sq2.push_back({a,b});
    }

    string ans = "NO";

    for(int c1 = 0; c1 < 4; c1++){
        ll x1 = sq2[c1].x;
        ll y1 = sq2[c1].y;
        if(x1 >= X1[0] && x1 <= X1[1] && y1 >= Y1[0] && y1 <= Y1[1])ans = "YES";
        for(int c2 = c1+1; c2 < 4; c2++){

            ll x2 = sq2[c2].x;
            ll y2 = sq2[c2].y;
            if(x1-y1 == x2-y2){
                dif.push_back(x1-y1);
            }
            if(x1+y1 == x2+y2){
                sum.push_back(x1+y1);
            }
        }
    }

    sort(all(dif));
    sort(all(sum));


    for(int c1 = X1[0]; c1 <= X1[1]; c1++){
        for(int c2 = Y1[0]; c2 <= Y1[1]; c2++){
            sq1.push_back({c1,c2});
        }
    }

    for(int c1 = 0; c1 < sz(sq1); c1++){
        ll x1 = sq1[c1].x;
        ll y1 = sq1[c1].y;

        if(x1-y1 >= dif[0] && x1-y1 <= dif[1] && x1+y1 >= sum[0] && x1+y1 <= sum[1]){
            ans = "YES";
        }
    }
    cout << ans << "\n";

    return 0;
}