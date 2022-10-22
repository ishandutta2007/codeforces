#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef  long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k;

vector<ll> A;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c;

    cin >> n;
    ll sum = 0;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        sum += a;
        A.push_back(a);
    }

    bool ans = 0;
    if(sum%2 == 1){
        cout << "NO\n";
    }
    else{

        ll sum2 = 0;
        for(ll c1 = 0; c1 < n; c1++){
            if(sum2 == sum/2){
                ans = 1;
            }
            sum2 += A[c1];
        }

        set<ll> S;
        sum2 = 0;
        for(ll c1 = 0; c1 < n; c1++){
            S.insert(A[c1]);
            sum2 += A[c1];
            if(sum2 > sum/2){
                ll delta = sum2 - sum/2;
                if(S.find(delta) != S.end())ans = 1;
            }
        }
        S.clear();
        sum2 = 0;

        for(ll c1 = n-1; c1 >= 0; c1--){
            S.insert(A[c1]);
            sum2 += A[c1];
            if(sum2 > sum/2){
                ll delta = sum2 - sum/2;
                if(S.find(delta) != S.end())ans = 1;
            }
        }

        if(ans){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

    }

    return 0;
}