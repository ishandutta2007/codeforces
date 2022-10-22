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

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 400001;


int where[MAXN] = {0};

int mark[MAXN] = {0};
int cc = 0;

void bfs(int i, int diff){
    while(mark[i] != cc){
        mark[i] = cc;
        i = (where[i]-diff+n)%n;
    }
}

int cyc(int diff){
    int res = 0;
    cc++;
    rep(c1,0,n){
        if(mark[c1] != cc){
            res++;
            bfs(c1, diff);
        }
    }
    return res;
}

ll F[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;

        vi ind;
        rep(c1,0,n){
            ind.push_back(c1+1);
        }
        random_shuffle(all(ind));


        rep(c1,0,n){
            cin >> a;


           // a = ind[c1];


            a--;
            F[(c1-a+n)%n]++;
            where[a] = c1;
        }
        vi ans;
        rep(c1,0,n){

            ll LOW = (n - F[c1] + 1)/2;
            if(m >= LOW){
                int moves = n-cyc(c1);
                //cerr << cyc(c1) << "  fdsfsd\n";
                if(moves <= m)ans.push_back(c1);
            }

        }
        cout << sz(ans) << " ";
        trav(y, ans){
            cout << y << " ";
        }cout << "\n";
    }

    return 0;
}