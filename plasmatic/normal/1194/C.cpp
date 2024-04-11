#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Defines and one-liners
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
template <typename T> inline T& back(vector<T> &vec) { return *(vec.end() - 1); }
template <typename T> inline void pop(vector<T> &vec) { return vec.erase(vec.end() - 1); }

// Scan, Debug, and other nonsense
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> void printArray(ostream& out,T* arr,int sz){out<<"[";for(int i=0;i<sz;i++){out<<arr[i]<<", "; } out<<"]";}
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}

void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f,R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)

const int MN = 1e2 + 1;
int dp[MN][MN];
string s, t, p;
unordered_map<int, int> chars;

void solve() {
    // Do DP
    int sl = s.length(), tl = t.length();
    for (int i = 1; i <= sl; i++) {
        for (int j = 1; j <= tl; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    // debug(sl, tl, dp[sl][tl]);

    // SL is not a subsequence of TL
    if (dp[sl][tl] != sl) {
        cout << "NO\n";
        return;
    }

    // Count chars
    for (char ch : t)
        chars[ch]++;
    for (char ch : s)
        chars[ch]--;
    for (char ch : p)
        chars[ch]--;
    
    for (pair<char, int> p : chars) {
        if (p.second > 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tno; scan(tno);
    while (tno--) {
        scan(s, t, p);

        chars.clear();
        memset(dp, 0, sizeof dp);

        solve();
    }

    return 0;
}