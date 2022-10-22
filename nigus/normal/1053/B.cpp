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

ll n,m,k,q,T;

vl A;
vl CS;

vector<vl> CI(2, vl());
vector<vl> CS2(2, vl());

ll brute(){
    ll ans = 0;
for(int c1 = 0; c1 < n; c1++){
    ll sum = 0;
    ll ma = 0;
    for(int c2 = c1; c2 < n; c2++){

        sum += A[c2];
        ma = max(ma,A[c2]);

        if(sum%2 == 0 && sum >= 2*ma)ans++;

    }
}
return ans;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    //n = 12333;
    CS.push_back(0);
    CS2[0].push_back(1);
    CS2[1].push_back(0);
    CI[0].push_back(0);
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        //a = rand();
        b = 0;
        while(a>0){
            b += a%2;
            a/=2;
        }
        A.push_back(b);
        CS.push_back((CS[c1]+b));
        c = (CS[c1]+b);
        CS2[0].push_back(CS2[0][c1] + (c%2 == 0));
        CS2[1].push_back(CS2[1][c1] + (c%2 == 1));
        CI[c%2].push_back(c1+1);
    }

    vector<vl> Z(2, vl());
    ll lim = 130;
    ll ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ll sum = 0;
        ll ma = A[c1];
        ll bryt = 0;
        for(int c2 = 0; c2 < lim; c2++){
            if(c1-c2 < 0){bryt = c1-c2; break;}
            if(sum > lim){bryt = c1-c2; break;}
            ma = max(ma,A[c1-c2]);
            sum += A[c1-c2];
           // cerr << ma << " " << sum << "\n";
            if(CS[c1+1]%2 == CS[c1-c2]%2){
                if(sum >= 2*ma){
                    ans++;
                }
            }
            bryt = c1-c2-1;
        }

        if(bryt >= 0){
            ans += CS2[(CS[c1+1]%2)][bryt];
        }

    }


    cout << ans << "\n";
    //cout << brute();
    return 0;
}