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


struct xorSpace {
    int dimension, rank;
    array<int,20> basis;
 
    xorSpace() {
        dimension = 20;
        rank = 0;
        fill(all(basis),0);
    }
 
    //need to define this
    inline int getValAtDim(const int& v, int dim)  {
        return (((1 << dim) & v) != 0);
    }
 
    bool addToBasis(int num) {
        int pos = -1;
        for(int i = dimension - 1; i >= 0; i--) {
            if(getValAtDim(num, i) != 0)    {
                if(basis[i] == 0)   {
                    pos = i;
                    break;
                }   else    {
                    num ^= basis[i];
                }
            }
        }
 
        if(pos != -1)   {
            basis[pos] = num;
            // basisVectors.push_back(num);
            rank++;
            return true;
        }
        return false;
    }
    xorSpace operator+=(const xorSpace& o){
        if (o.rank == 0) return *this;
        if (rank == 0) return *this = o;
        FOR (i, 0, 19) if (o.basis[i]) {
            addToBasis(o.basis[i]);
        }
        return *this;
    }

    int getMax() {
        int ans = 0;
        for (int i = dimension - 1; i >= 0; --i) if (basis[i] and (ans & (1<<i))==0) {
            ans ^= basis[i];
        }
        return ans;
    }
};

const int k = 20;

int main()
{

    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vi a(n); FOR (i, 0, n - 1) cin >> a[i];

    while (n % k) a.push_back(0), ++n;

    vector<xorSpace> p(n), s(n);

    FOR (i, 0, n - 1) {
        if (i % k) p[i] = p[i-1];
        p[i].addToBasis(a[i]);
    }


    NFOR (i, n - 1, 0) {
        if (i % k != k-1) s[i] = s[i+1];
        s[i].addToBasis(a[i]);
    }
    

    int no = n / k;
    vector<vector<xorSpace>> dp(no, vector<xorSpace>(20));
    FOR (i, 0, no - 1) {
        dp[i][0] = s[i*k];
    }

    FOR (j, 1, 19) {
        FOR (i, 0, no - 1) {
            dp[i][j] = dp[i][j-1];
            if (i+(1<<(j-1)) < no) dp[i][j] += dp[i+(1<<(j-1))][j-1];
        }
    }


    int q; cin >> q; while (q--) {
        int l, r; cin >> l >> r; --l, --r;
        xorSpace ans;
        if (r-l+1 < k) {
            FOR (it, l, r) ans.addToBasis(a[it]);
        } else {
            if (l%k) ans += s[l];
            if (r%k!=k-1) ans += p[r];
            while (l % k) ++l;
            while (r % k!=k-1) --r;

            if (l <= r) {
                l /= k, r /= k;
                int bc = 31 - __builtin_clz(r-l+1);
                ans += dp[l][bc];
                ans += dp[r-(1<<bc)+1][bc];
            }
        }
        cout << ans.getMax() << "\n";
    }


    return 0;
}