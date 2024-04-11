#pragma GCC optimize("O3")   //
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    cin >> T;

    rep(_,0,T){
        cin >> n >> k;
        string s;
        cin >> s;
        vi gaps;
        int segs = 0;
        char prev = 'L';
        int w = 0;

        bool gap = 0;
        int curr = 0;

        rep(c1,0,n){
            if(s[c1] == 'W'){
                if(prev == 'L'){
                    segs++;
                    if(gap){
                        gaps.push_back(curr);
                      //  cerr << curr << " ";
                    }
                }
                curr = 0;
                gap = 1;
                w++;
            }
            else{
                curr++;
            }

            prev = s[c1];
        }
        //cerr << "  fd\n";
        sort(all(gaps));
        w += k;
        w = min((int)n,w);

        rep(c1,0,sz(gaps)){
            if(k < gaps[c1])break;
            k -= gaps[c1];
            segs--;
        }

        if(w > 0 && segs == 0)segs = 1;

        cout << 2*w - segs << "\n";
    }

    return 0;
}