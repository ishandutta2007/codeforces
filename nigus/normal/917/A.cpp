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

vector<ll> A;
vector<ll> B;

bool yes[1001][1001] = {0};

void stress(ll i){

if(i != sz(B)){

    //B[i] = 1;
    A[B[i]] = 1;
    stress(i+1);
    //B[i] = -1;
    A[B[i]] = -1;
    stress(i+1);
    A[B[i]] = 0;

}
else{

    for(ll c1 = 0; c1 < n; c1++){

        ll a = 0;
        for(ll c2 = c1; c2 < n; c2++){
            a += A[c2];
            if(a < 0)break;
            if(a == 0)yes[c1][c2] = 1;
        }
    }


}
return;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    string s;
    cin >> s;

    n = s.length();
    for(ll c1 = 0; c1 < n; c1++){
        a = 0;
        if(s[c1] == '(')a=1;
        if(s[c1] == ')')a=-1;
        A.push_back(a);
        if(a == 0)B.push_back(c1);
    }

    ll ans = 0;
    ll low = 0;
    for(ll c1 = 0; c1 < n; c1++){
        a = 0;
        ll mi = 0;
        ll qu = 0;
        low = 0;
        for(ll c2 = c1; c2 < n; c2++){
            a += A[c2];
            if(A[c2] == 0)qu++;
            if(a+qu < 0)break;
            if(a-low > 0 && A[c2] == 0)low++;
            if(a-low < 0)low = a;

            if((c2-c1)%2 == 1){
                if(a <= low)ans++;
            }

        }

    }
    /*
    stress(0);
    ll ans2 = 0;
    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = c1; c2 < n; c2++){
            ans2 += yes[c1][c2];
        }
    }
    */
    cout << ans << "\n";
    return 0;
}