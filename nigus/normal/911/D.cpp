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
const ll lim = 1000000;



int main() {

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    ll inv = 0;
    cin >> n;
    vector<ll> A;

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        for(ll c2 = 0; c2 < c1; c2++){
            if(A[c2] > a)inv++;
        }
    }
    inv %= 2;
    ll q;
    cin >> q;
    for(ll c1 = 0; c1 < q; c1++){
        cin >> a >> b;
        c = b-a+1;
        c = (c*c-c)/2;
        inv += c;
        inv %= 2;
        if(inv == 1){
            cout << "odd\n";
        }
        else{
            cout << "even\n";
        }

    }


    return 0;
}