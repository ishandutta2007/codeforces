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

const int MN=150001;
int n,a[MN],dp[MN];
map<int,int>mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
scan(n);
for (int i = 1; i <= n; i++) {
    scan(a[i]);
    mp[a[i]]++;
}sort(a+1,a+n+1);

int curv=0; int tot=0;
for (auto p:mp){
    // debug(curv,tot,p.first,p.second);
if (p.second>=3) {
    int add = p.first + 1 - max(p.first-1-1,curv);
    tot+=add;
    curv=max(p.first-1-1,curv)+add;
}
else if (p.second == 2) {
    int add = p.first + 1 - max(p.first-1-1,curv);
    while (add>2){
        add--;
    }
    tot+=add;
    curv=max(p.first-1-1,curv)+add;
}
else {
    if (curv < p.first+1) {
        curv= max(p.first-1-1,curv)+1;
        tot++;
    }
}
}

cout <<tot<<"\n";

    return 0;
}