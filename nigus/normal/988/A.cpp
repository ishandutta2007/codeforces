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

const ll big = 1000000007;
const ll mod = 998244353;

int n,m,k,q,p;
ll T;



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c;

    cin >> n >> k;
    vi A;
    bool F[100001] = {0};

    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }

    vi ANS;

    for(int c1 = 0; c1 < n; c1++){
        if(!F[A[c1]]){
            F[A[c1]] = 1;
            ANS.push_back(c1);
        }
    }

    if(sz(ANS) < k){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for(int c1 = 0; c1 < k; c1++){
            cout << ANS[c1]+1 << " ";
        }
    }

    return 0;
}