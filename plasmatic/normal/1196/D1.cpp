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

const int MN = 2e5 + 1;
int n, k, 
    pfx[MN];
char refStr[MN];
string s, ans;

namespace asjdofaisdfoisdjfo {
    int idxOf[(int)'Z' + 1];
    const string S = "RGB"; 

    void init() {
        idxOf['G'] = 1;
        idxOf['B'] = 2;
    }
    char next(char ch) {
        return S[(idxOf[(int)ch] + 1) % 3];
    }
    char prev(char ch) {
        return S[(idxOf[(int)ch] + 2) % 3]; // - 1 + 3
    }
    char get(int idx) {
        return S[idx];
    }
}
using asjdofaisdfoisdjfo::init; using asjdofaisdfoisdjfo::prev; using asjdofaisdfoisdjfo::next; using asjdofaisdfoisdjfo::get;

void solve() {
    int best = INF;

    for (int i = 0; i < 3; i++) {
        refStr[0] = get(i);
        for (int j = 1; j < n; j++)
            refStr[j] = next(refStr[j - 1]);
        
        fill(pfx, pfx + n + 1, 0);
        for (int j = 0; j < n; j++)
            pfx[j + 1] = s[j] != refStr[j];
        partial_sum(pfx, pfx + n + 1, pfx);

        for (int j = k; j <= n; j++)
            best = min(best, pfx[j] - pfx[j - k]);
    }

    cout << best << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int t; scan(t);
    while (t--) {
        scan(n, k, s);

        solve();
    }

    return 0;
}