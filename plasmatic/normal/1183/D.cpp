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
int n,
    arr[MN];

void solve(vector<int> &freqs) {
    int tot = 0, last = INF;
    for (int freq : freqs) {
        if (last == 0) last = 1;
        tot += min(freq, last - 1);
        last = min(freq, last - 1);
    }

    cout << tot << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; scan(q);
    while (q--) {
        scan(n);

        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            scan(arr[i]);
            cnt[arr[i]]++;
        }
        
        vector<int> freqs;
        for (auto p : cnt) {
            freqs.push_back(p.second);
        }
        sort(freqs.begin(), freqs.end(), greater<int>());

        solve(freqs);
    }

    return 0;
}