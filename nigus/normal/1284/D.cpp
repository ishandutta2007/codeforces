#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 100001;

vl X1, kind1, I1, ind1;
vl X2, kind2, I2, ind2;

ll A1[MAXN] = {0};
ll A2[MAXN] = {0};

ll B[MAXN] = {0};

bool comp1(int i, int j){
    if(X1[i] == X1[j]){
        return kind1[i] < kind1[j];
    }
    return X1[i] < X1[j];
}

bool comp2(int i, int j){
    if(X2[i] == X2[j]){
        return kind2[i] < kind2[j];
    }
    return X2[i] < X2[j];
}

ll base = 124;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a >> b >> c >> d;
        X1.push_back(a);
        X1.push_back(b);
        kind1.push_back(0);
        kind1.push_back(1);
        I1.push_back(c1);
        I1.push_back(c1);
        ind1.push_back(sz(ind1));
        ind1.push_back(sz(ind1));

        X2.push_back(c);
        X2.push_back(d);
        kind2.push_back(0);
        kind2.push_back(1);
        I2.push_back(c1);
        I2.push_back(c1);
        ind2.push_back(sz(ind2));
        ind2.push_back(sz(ind2));
    }

    base = random2()%1000000 + 123456;
    b = 1;
    rep(c1,0,n){
        B[c1] = b;
        b *= base;
        b %= big;
    }

    sort(all(ind1), comp1);
    ll sum = 0;
    trav(i, ind1){
        if(kind1[i] == 1){
            sum += B[I1[i]];
            sum %= big;
        }
        else{
            A1[I1[i]] += sum;
            A1[I1[i]] %= big;
        }
    }
    reverse(all(ind1));
    trav(i, ind1){
        if(kind1[i] == 0){
            sum += B[I1[i]];
            sum %= big;
        }
        else{
            A1[I1[i]] += sum;
            A1[I1[i]] %= big;
        }
    }




    sort(all(ind2), comp2);
    sum = 0;
    trav(i, ind2){
        if(kind2[i] == 1){
            sum += B[I2[i]];
            sum %= big;
        }
        else{
            A2[I2[i]] += sum;
            A2[I2[i]] %= big;
        }
    }
    reverse(all(ind2));
    trav(i, ind2){
        if(kind2[i] == 0){
            sum += B[I2[i]];
            sum %= big;
        }
        else{
            A2[I2[i]] += sum;
            A2[I2[i]] %= big;
        }
    }

    string ans = "YES";
    rep(c1,0,n){
        if(A1[c1] != A2[c1])ans = "NO";
       // cerr << A1[c1] << "  " << A2[c1] << "   fdsh\n";
    }
    cout << ans << "\n";

    return 0;
}