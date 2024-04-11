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
typedef pair<double,double> pdd;


const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T,q;

ll F[123012] = {0};

ll lis(vi & A){
    ll na = sz(A);
    ll ans = 0;
    for(int c1 = 0; c1 < na; c1++){
        F[c1] = 1;
        for(int c2 = 0; c2 < c1; c2++){
            if(A[c2] < A[c1]){
                F[c1] = max(F[c1], F[c2]+1);
            }
        }
        ans = max(ans, F[c1]);
    }
    return ans;
}

ll lds(vi & A){
    ll na = sz(A);
    ll ans = 0;
    for(int c1 = 0; c1 < na; c1++){
        F[c1] = 1;
        for(int c2 = 0; c2 < c1; c2++){
            if(A[c2] > A[c1]){
                F[c1] = max(F[c1], F[c2]+1);
            }
        }
        ans = max(ans, F[c1]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;
    /*
    ll anss[12] = {0};
    for(int c1 = 2; c1 <= 11; c1++){

        vi ind;
        for(int c2 = 0; c2 < c1; c2++){
            ind.push_back(c2+1);
        }

        ll f = 1;
        for(int c2 = 0; c2 < c1; c2++){
            f *= c2+1;
        }
        vi ANS;
        ll ma = 2*c1;
        for(int c2 = 0; c2 < f; c2++){
            ll k = lis(ind)+lds(ind);
            if(k < ma){
                ma = k;
                ANS = ind;
            }
            next_permutation(all(ind));
        }
        cout <<"L: " << c1 << "   ans: " << ma << "\n";
        for(int c2 = 0; c2 < c1; c2++){
            cout << ANS[c2] << " ";
        }
        cout << "\n\n";
        anss[c1] = ma;

    }
*/

    cin >> n;

    ll ans = 2*n;
    ll k = 1;
    for(ll c1 = 1; c1 <= n; c1++){
        ll temp = c1 + (n+c1-1)/c1;
        if(temp < ans){
            ans = temp;
            k = c1;
        }
    }

  //  cout << ans << " " << anss[n] << "\n";

    ll n2 = n;
    for(ll c1 = 0; c1 < n/k; c1++){
        for(int c2 = 0; c2 < k; c2++){
            cout << k*c1+k-c2 << " ";
            n2--;
        }
    }
    a = n;



    while(n2 > 0){
        cout << a << " ";
        n2--;
        a--;
    }

    return 0;
}