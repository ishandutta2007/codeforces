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

const int MAXN = 500006;


bool row[MAXN] = {0};
bool col[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;

    if(n == 1 || n == 2){
        cout << "1\n1 1\n";
        return 0;
    }

    /*
    if(n == 5){
        cout << "3\n1 1\n2 3\n3 2\n";
        return 0;
    }
    if(n == 6){
        cout << "4\n1 1\n2 3\n3 2\n4 4\n";
        return 0;
    }
    */

    ll odd2 = 1;

    for(ll odd = 1; odd <= n; odd++){
        ll even = n-odd;

        ll diags = 2*odd-1;

        if(even < diags)break;
        odd2 = odd;
    }

    ll even2 = n-odd2;

    cout << even2 << "\n";

    int r = even2-1;
    for(int diff = -odd2+1; diff <= odd2-1; diff++){
        int c = r+diff;

        while(r < 0 || c < 0 || c >= even2 || col[c] || row[r]){
            r--;

            if(r+diff < 0)r = even2-1;

            c = r+diff;

        }

        cout << r+1 << " " << c+1 << "\n";
        row[r] = 1;
        col[c] = 1;
        r--;
    }

    r = 0;

    for(int c = 0; c < even2; c++){
        if(!col[c]){
            while(row[r]){
                r++;
            }
            col[c] = 1;
            row[r] = 1;
            cout << r+1 << " " << c+1 << "\n";
        }
    }


    return 0;
}