#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k;
ll c,d;

vector<ll> A1;
vector<ll> B1;

vector<vector<ll> > C1(200001 , vector<ll>());

vector<ll> A2;
vector<ll> B2;

vector<vector<ll> > C2(200001 , vector<ll>());

vector<ll> MA;
vector<ll> X;

ll bs(ll i){

if(X.size() == 0)return -1;
if(X[0] > i)return -1;
ll l = 0;
ll r = X.size();
while(l < r-1){

    ll mid = (l+r)/2;
    if(X[mid] <= i){
        l = mid;
    }
    else{
        r = mid;
    }

}

return MA[l];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b;

    cin >> n >> c >> d;;

    ll max1 = -1;
    ll max2 = -1;


    for(ll c1 = 0; c1 < n; c1++){
        char ch;
        cin >> a >> b >> ch;
        if(ch == 'C'){
            if(b <= c){
                max1 = max(max1 , a);
            }
            A1.push_back(a);
            B1.push_back(b);
            C1[b].push_back(a);
        }
        else{
            if(b <= d){
                max2 = max(max2 , a);
            }
            A2.push_back(a);
            B2.push_back(b);
            C2[b].push_back(a);
        }
    }
    ll a1 = -1;
    if(max1 != -1 && max2 != -1){
        a1 = max1+max2;
    }

    ll a2 = -1;
    ll a3 = -1;

    ll prev = -1;
    for(ll c1 = 0; c1 < 200001; c1++){
        for(ll c2 = 0; c2 < C1[c1].size(); c2++){
            a = C1[c1][c2];
            if(c-c1 >= 0){
                b = bs(c-c1);
                if(b != -1){
                    a2 = max(a2,a+b);
                }
            }
            X.push_back(c1);
            MA.push_back(max(prev, a));
            prev = max(a,prev);
        }
    }

    prev = -1;
    X.clear();
    MA.clear();

    for(ll c1 = 0; c1 < 200001; c1++){
        for(ll c2 = 0; c2 < C2[c1].size(); c2++){
            a = C2[c1][c2];
            if(d-c1 >= 0){
                b = bs(d-c1);
                if(b != -1){
                    a3 = max(a3,a+b);
                }
            }
            X.push_back(c1);
            MA.push_back(max(prev, a));
            prev = max(a,prev);
        }
    }


    //cout << a1 << " " << a2 << " " << a3 << "\n";

    ll ans = max(a1,max(a2,a3));
    if(ans == -1)ans++;
    cout << ans << "\n";

    return 0;
}