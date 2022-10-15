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

const int MN = 1e5 + 1, D = 1e5;
int n;
struct {
    int x, y; bool a, b, c, d;
} rob[MN];
int minY, maxY, minX, maxX;

void solve() {
    for (int i = 0; i < n; i++) {
        if (!rob[i].a)
            minX = max(minX, rob[i].x);
        if (!rob[i].b)
            maxY = min(maxY, rob[i].y);
        if (!rob[i].c)
            maxX = min(maxX, rob[i].x);
        if (!rob[i].d)
            minY = max(minY, rob[i].y);        
    }

    if (minX > maxX || minY > maxY) 
        cout << "0\n";
    else
        cout << "1 " << minX << " " << minY << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; scan(t);
    while (t--) {
        scan(n);
        
        for (int i = 0; i < n; i++)
            scan(rob[i].x, rob[i].y, rob[i].a, rob[i].b, rob[i].c, rob[i].d);
        
        minX = minY = -1e5;
        maxX = maxY = 1e5;

        solve();
    }

    return 0;
}