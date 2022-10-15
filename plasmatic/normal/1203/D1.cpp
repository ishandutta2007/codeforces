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

const int MN=2e5+10;
string s, t, tt;
int n, m,
    lhs[MN],rhs[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(s,t);n=s.length();m=t.length();
    tt=t;
    reverse(tt.begin(), tt.end());

    int cid=0;
    for (int i = 0; i < n; i++) {
        if (cid < m && s[i] == t[cid]) {
            cid++;
        }
        lhs[i]=cid;
    }

    cid = m;
    for (int i = n-1; i >=0; i--) {
        if (cid > 0 && s[i]==t[cid-1]){
            cid--;
        }
        rhs[i]=cid;
    }
    rhs[n]=m;int best=-1;

    // printArray(cout,lhs,n);
    // printArray(cout,rhs,n+1);
    

    for (int i = n; i >=0; i--) {
        int ptr = lower_bound(lhs,lhs+n,rhs[i])-lhs;
        int id=ptr;
        id++;
        // debug(id);

        if (rhs[i]==0)
            id=0;

        best=max(best,i-id);
    }
    cout << best << "\n";

    return 0;
}