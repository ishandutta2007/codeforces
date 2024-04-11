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

const int MAXN = 300001;

int hej2(int a,int b){
    rep(c,b,2*b+1){
        if((c|a) == c)return c;
    }return -1;
}

int hej(int a,int b){
    int start = (a|b);
    int t = 1;
    int b2 = start;
    int a2 = a;
    rep(c1,0,22){
        if(b2%2 == 1 && a2%2 == 0 && start-t >= b){
            start -= t;
        }
        t *= 2;
        b2 /= 2;
        a2 /= 2;
    }

  /*  if(start != hej2(a, b)){
        cerr << "ERROR: " << a << " " << b << ": " << hej2(a, b) << "  and not " << start << "\n";
    }*/



    return start;
}


int solve(int a, int b){
    int ans = abs(b-a);
    int e = 0;
    int a2 = a;
    rep(_,0,b-a2){
        int temp = e+hej(a,b)-b+1;
       // if(b == hej(a,b))temp--;
        //cerr << hej(a,b) << "  gd\n";
        ans = min(ans, temp);
        a++;
        e++;
    }

    /*
    int weird = big;
    if(a2 < b)weird = 1 + solve(a2+1, b);

    if(weird < ans){
        cerr << "ERROR: " << a2 << " " << b << "   -   " << weird << " and not " << ans << "\n";
    }
*/
    return ans;
}

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> a >> b;
      //  a = rand()%10;
       // b = rand()%10;
        if(a > b)swap(a, b);
        cout << solve(a, b) << "\n";
    }

    return 0;
}