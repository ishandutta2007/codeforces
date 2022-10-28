#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int mod = 998244353;
const int SZ = 100;
const int r = 3;

const int N = 32000;
int pr[N+1], ppr[N+1], ippr[N+1];
map<int, int> mp;

int expo(int n, int p) {
    int ans = 1;
    while (p) {
        if (p & 1) {
            ans = (ans * 1LL * n) % mod;
        }
        n = (n * 1LL * n) % mod;
        p >>= 1;
    }
    return ans;
}

int no;

struct matrix{
    int arr[SZ][SZ];
    void reset(){
        memset(arr , 0 , sizeof(arr));
    }
    void makeiden(){
        reset();
        for(int i = 0 ; i < no ; ++i){
            arr[i][i] = 1;
        }
    }
    inline matrix operator =(const matrix& o) {
    	FOR (i, 0, no-1) FOR (j, 0, no-1) arr[i][j] = o.arr[i][j];
    	return *this;
    }
    inline matrix operator * (const matrix &o) const {
        matrix res;
        for(int i = 0 ; i < no ; ++i){
            for(int j = 0 ; j < no ; ++j){
                unsigned long long sum = 0;
                for(int k = 0 ; k < no ; ++k){
                    sum = (sum + 1LL * arr[i][k] * o.arr[k][j]) % (mod-1);
                }
                res.arr[i][j] = sum;
            }
        }
        return res;
    }
    inline matrix operator ^(int n) const {
    	matrix res; res.makeiden();
    	matrix cur = *this;
    	while (n) {
    		if (n & 1) {
    			res = res * cur;
    		}
    		n >>= 1;
    		cur = cur * cur;
    	}
    	return res;
    }
};


int Log(int x) {
	FOR (i, 0, N-1) {
		int y = (ippr[i] * 1LL * x)%mod;
		if (mp.count(y)) {
			assert(expo(3,i*N+mp[y]) == x);
			return i*N+mp[y];
		}
	}
	assert(0);
	return -1;
}

int extended_euclid(int a, int b, int &x, int &y) {
	int xx = y = 0;
	int yy = x = 1;
	while (b) {
		// pr(b);
		int q = a / b;
		int t = b; b = a % b; a = t;
		t = xx; xx = x - q * xx; x = t;
		t = yy; yy = y - q * yy; y = t;
	}
	return a;
}



int mod_inverse(int a, int n) {
  int x, y;
  int d = extended_euclid(a, n, x, y);
  if (d > 1) return -1;
  return (x+n)%n;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);


	pr[0] = 1; ppr[0] = 1, ippr[0] = 1;
	mp[1] = 0;
	FOR (i, 1, N) {
		pr[i] = (pr[i-1] * 3LL)%mod;
		ppr[i] = expo(pr[i], N);
		ippr[i] = expo(ppr[i], mod-2);
		mp[pr[i]] = i;
	}
	cin >> no;
	vi b(no); FOR (i, 0, no-1) cin >> b[i];
	matrix yo; yo.reset();
	FOR (i, 1, no-1) {
		yo.arr[i-1][i] = 1;
	}
	FOR (i, 0, no - 1) {
		yo.arr[no-1][i] = b[no-1-i];
	}
	int n, m; cin >> n >> m;
	// FOR (i, 0, no-1) FOR (j, 0, no-1) cout << yo.arr[i][j] << " \n"[j+1==no];
	yo = yo ^ (n-no);
	// FOR (i, 0, no-1) FOR (j, 0, no-1) cout << yo.arr[i][j] << " \n"[j+1==no];

	int x = yo.arr[no-1][no-1], y = Log(m);
	if (x == 0 and y == 0) {
		cout << "1\n";
		return 0;
	}
	// if (x == 0) {
	// 	cout << "-1\n";
	// 	return 0;
	// }
	int g = __gcd(x, y);
	x /= g, y /= g;
	
	
	int bc = mod_inverse(x, mod-1);
	if (bc==-1) {
		cout << "-1\n";
		return 0;	
	}
	
	
	// pr(bc);
	// pr((bc*1LL*y)%(mod-1));
	cout << expo(3, (bc*1LL*y)%(mod-1)) << "\n";

	
	return 0;
}