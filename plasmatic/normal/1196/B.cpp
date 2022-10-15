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
    arr[MN];

void solve() {
    int oddc = 0;
    for (int i = 0; i < n; i++)
        oddc += arr[i];
    
    if (oddc >= k && oddc % 2 == k % 2) {
        cout << "YES\n";
        int left = k, lastBegin = n - 1;
        vector<int> ss;
        for (int i = n - 1; i >= 0, left > 0; i--) {
            if (arr[i]) {
                left--;
                ss.push_back(lastBegin + 1);
                lastBegin = i - 1;
                // cout << << " ";
            }
            // cout 
        }
        sort(ss.begin(), ss.end());
        // cout << ss << "\n";
        for (auto x : ss) cout << x << " ";
        cout << "\n";
    }
    else 
        cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
     scan(t);
     while (t--) {
         scan(n, k);
         for (int i = 0; i < n; i++) {
             scan(arr[i]);
             arr[i] %= 2;
         }
         solve();
     }

    return 0;
}