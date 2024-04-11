#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 100007;

vi X, Y, I;

unordered_map<int, int> MX;
unordered_map<int, int> MY;
vi XX, YY;
int mx = 0;


void flipx(){
    rep(c1,0,n){
        X[c1] = mx-1-X[c1];
    }
}

void flipy(){
    rep(c1,0,n){
        Y[c1] = mx-1-Y[c1];
    }
}

void swp(){
    rep(c1,0,n){
        swap(X[c1], Y[c1]);
    }
}

bool solve3(vi &X1, vi &X2, int goal){
    if(sz(X1) < goal || sz(X2) < goal)return 0;
    int x = X1[goal-1];
    int y = X2[sz(X2)-goal];
    return (y > x);
}

bool solve2(int i, int j, int x_no, int goal){
    vi X1, X2, Y1, Y2;
    rep(c1,0,n){
        if(X[c1] > x_no){
            if(I[c1] == i){
                X1.push_back(X[c1]);
                Y1.push_back(Y[c1]);
            }
            if(I[c1] == j){
                X2.push_back(X[c1]);
                Y2.push_back(Y[c1]);
            }
        }
    }

    sort(all(X1));
    sort(all(X2));
    sort(all(Y1));
    sort(all(Y2));

    if(solve3(X1, X2, goal))return 1;
    if(solve3(X2, X1, goal))return 1;
    if(solve3(Y1, Y2, goal))return 1;
    if(solve3(Y2, Y1, goal))return 1;
    return 0;
}

int solve(int i){
    vi oth;
    rep(c1,0,3){
        if(c1 != i){
            oth.push_back(c1);
        }
    }

    vi X2;
    rep(c1,0,n){
        if(I[c1] == i){
            X2.push_back(X[c1]);
        }
    }
    sort(all(X2));

    int lo = 0;
    int hi = n/3+1;

    while(lo < hi-1){
        int mid = (lo+hi)/2;
        bool temp = 0;
        if(mid == 0)temp = 1;
        if(mid > 0){
            int x = X2[mid-1];
            temp = solve2(oth[0], oth[1], x, mid);
        }
        if(temp){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> n;

    rep(c1,0,n){
        cin >> a >> b >> c;
        X.push_back(a);
        Y.push_back(b);
        I.push_back(c-1);

        if(MX.find(a) == MX.end()){
            MX[a] = 0;
            XX.push_back(a);
        }
        if(MY.find(b) == MY.end()){
            MY[b] = 0;
            YY.push_back(b);
        }
    }
    sort(all(XX));
    sort(all(YY));
    rep(c1,0,sz(XX)){
        MX[XX[c1]] = c1;
    }
    rep(c1,0,sz(YY)){
        MY[YY[c1]] = c1;
    }
    mx = max(sz(XX), sz(YY));
    rep(c1,0,n){
        X[c1] = MX[X[c1]];
        Y[c1] = MY[Y[c1]];
    }


    int ans = 0;

    rep(c1,0,2){
        rep(c2,0,2){
            rep(i,0,3){
                int res = solve(i)*3;
              //  cerr << res << "  heh\n";
                ans = max(ans, res);
            }
            flipx();
        }
        swp();
    }

    cout << ans << "\n";

    return 0;
}