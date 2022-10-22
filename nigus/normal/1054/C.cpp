#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
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

ll n,m,T,k,d;
const ll big = 1000000007;

vi L;
vi R;
vi ind;

ll A[1001] = {0};

bool comp(ll i, ll j){
    return L[i]+R[i] < L[j]+R[j];
}

bool check(){
    for(int c1 = 0; c1 < n; c1++){
        ll l = 0;
        ll r = 0;
        for(int c2 = 0; c2 < c1; c2++){
            if(A[c2] > A[c1])l++;
        }
        for(int c2 = c1+1; c2 < n; c2++){
            if(A[c2] > A[c1])r++;
        }

        if(l != L[c1] || r != R[c1])return 0;

    }
    return 1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        L.push_back(a);
        //R.push_back(b);
        ind.push_back(c1);
    }

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        R.push_back(a);
        //R.push_back(b);
        //ind.push_back(c1);
    }

    sort(all(ind),comp);
    reverse(all(ind));
    ll num = 0;
    ll prev = -1;
    for(int c1 = 0; c1 < n; c1++){
        a = ind[c1];
        if(L[a]+R[a] != prev){
            num++;
        }
        A[a] = num;
        prev = L[a]+R[a];
    }
    bool ch = check();
    if(!ch){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for(int c1 = 0; c1 < n; c1++){
            cout << A[c1] << " ";
        }

    }

    return 0;
}