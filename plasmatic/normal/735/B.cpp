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

const int MAX = 100001;
int n, n1, n2,
    val[MAX];
double ans1 = 0., ans2 = 0.;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(n, n1, n2);

    for (int i = 0; i < n; i++)
        scan(val[i]);
    sort(val, val + n, greater<int>());

    if (n1 > n2) swap(n1, n2);

    for (int i = 0; i < n1; i++)
        ans1 += val[i];
    for (int i = n1; i < n1 + n2; i++)
        ans2 += val[i];
    
    // debug(ans1, ans2);
    
    printf("%.10f\n", ans1 / n1 + ans2 / n2);

    return 0;
}