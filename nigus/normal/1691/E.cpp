
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

const int MAXN = 400006;

struct UF {
	vi e, r;
	UF(int n, vi R) : e(n, -1) {r = R;}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		r[a] = max(r[a], r[b]);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

vi ind;
int X[MAXN] = {0};
int I[MAXN] = {0};
int COL[MAXN] = {0};
bool kind[MAXN] = {0};

bool comp(int i, int j){
    if(X[i] == X[j])return kind[i] < kind[j];
    return X[i] < X[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        ind.clear();
        vi R;
        rep(c1,0,n){
            cin >> a >> b >> c;
            b--;
            c--;
            R.push_back(c);
            X[sz(ind)] = b;
            kind[sz(ind)] = 0;
            COL[sz(ind)] = a;
            I[sz(ind)] = c1;
            ind.push_back(sz(ind));

            X[sz(ind)] = c;
            kind[sz(ind)] = 1;
            COL[sz(ind)] = a;
            I[sz(ind)] = c1;
            ind.push_back(sz(ind));

        }
        UF uf(n, R);
        sort(all(ind), comp);
        int F[2] = {0};
        int ans = n;
        vi C;
        trav(i, ind){
            if(kind[i] == 0){
                F[COL[i]]++;
                C.push_back(I[i]);
            }
            else{
                F[COL[i]]--;
            }
            if(F[0] > 0 && F[1] > 0){
                vi merg;
                trav(y, C){
                    if(uf.r[y] >= X[i]){
                        merg.push_back(y);
                    }
                }
                int fin = merg[0];
                rep(c2,1,sz(merg)){
                    uf.join(fin, merg[c2]);
                    ans--;
                    fin = uf.find(fin);
                }
                C.clear();
                C.push_back(fin);
            }
        }
        cout << ans << "\n";

    }

    return 0;
}