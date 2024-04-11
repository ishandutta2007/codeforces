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

int n, a[200];

void solve(){
    int id1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]==1){
            id1=i;
            break;
        }
    }

    int cpos = 1;
    bool pass = true;
    for (int i = 0; i < n; i++) {
        pass &= a[(id1 + i) % n] == cpos;
        cpos++;
    }

    bool flag2=true;
    cpos = 1;
    for (int i = 0; i < n; i++) {
        flag2 &= a[(id1 - i + n) % n] == cpos;
        cpos++;
    }
    pass = pass || flag2;

    cout << (pass?"YES\n":"NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;scan(t);while(t--){
        scan(n);
        for (int i = 0; i < n; i++) {
            scan(a[i]);
        }
        solve();
    }

    return 0;
}