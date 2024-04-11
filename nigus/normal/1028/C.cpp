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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q;

struct rect{
    ll xmin,xmax,ymin,ymax;
};

rect intersect(rect R1, rect R2){
    return {max(R1.xmin,R2.xmin), min(R1.xmax,R2.xmax), max(R1.ymin,R2.ymin), min(R1.ymax,R2.ymax)};
}

bool bad(rect R){
    return (R.xmin>R.xmax)||(R.ymin>R.ymax);
}

vector<rect> R;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b >> c >> d;
        ll xmin = min(a,c);
        ll xmax = max(a,c);
        ll ymin = min(b,d);
        ll ymax = max(b,d);
        R.push_back({xmin,xmax,ymin,ymax});
    }

    rect res;
    ll failed;

    res = R[0];
    failed = 0;

    for(int c1 = 1; c1 < n; c1++){
        rect temp = intersect(res,R[c1]);
        if(bad(temp)){
            failed++;
        }
        else{
            res = temp;
        }
    }


    if(failed < 2){
        cout << res.xmin << " " << res.ymin << "\n";
        return 0;
    }

    reverse(all(R));

    res = R[0];
    failed = 0;

    for(int c1 = 1; c1 < n; c1++){
        rect temp = intersect(res,R[c1]);
        if(bad(temp)){
            failed++;
        }
        else{
            res = temp;
        }
    }

    assert(failed < 2);
    cout << res.xmin << " " << res.ymin << "\n";

    return 0;
}