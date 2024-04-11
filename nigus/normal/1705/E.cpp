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

const int MAXN = 210006;

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}

    int find_max(){
        if(val == 0)return -1;
        if(lo+1 == hi)return lo;
        push();
        int R = (r->find_max());
        if(R != -1)return R;
        return (l->find_max());
    }

	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}

    int find_nex(int L, int goal){
        if(L >= hi)return inf;
        if(L <= lo && val != goal)return inf;
        if(lo+1 == hi)return lo;
        push();
        int x = (l->find_nex(L, goal));
        if(x != inf)return x;
        return (r->find_nex(L, goal));
    }


	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

int F[MAXN] = {0};
vi F2;

vi A;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n >> q;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
        F[a]++;
    }


    F2.push_back(0);
    rep(c1,1,MAXN){
        F2.push_back(F[c1] + F2[c1-1]/2);
    }

    vi MOD, MOD2;
    rep(c1,0,MAXN){
        MOD.push_back(F2[c1]%2);
        MOD2.push_back(-(F2[c1]%2));
    }

    Node ST(F2, 0, MAXN);
    Node MAX(MOD, 0, MAXN);
    Node MIN(MOD2, 0, MAXN);


    rep(c1,0,q){
        cin >> a >> b;

        a--;

        int hi;
        /*
        int lo = A[a];
        hi = MAXN;
        while(lo < hi-1){
            int mid = (lo+hi)/2;
            bool res = (MAX.query(A[a], mid) == 1);
            if(res){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        */

        hi = MAX.find_nex(A[a], 1)+1;

        ST.add(A[a], hi, -1);
        MAX.set(A[a], hi-1, 1);
        MAX.set(hi-1, hi, 0);
        MIN.set(A[a], hi-1, -1);
        MIN.set(hi-1, hi, 0);

        A[a] = b;
        /////////

        /*
        lo = A[a];
        hi = MAXN;
        while(lo < hi-1){
            int mid = (lo+hi)/2;
            bool res = (MIN.query(A[a], mid) == 0);
            if(res){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
*/

        hi = MIN.find_nex(A[a], 0)+1;

        ST.add(A[a], hi, 1);
        MAX.set(A[a], hi-1, 0);
        MAX.set(hi-1, hi, 1);
        MIN.set(A[a], hi-1, 0);
        MIN.set(hi-1, hi, -1);


        int ans = (ST.find_max());

        cout << ans << "\n";


    }


    return 0;
}