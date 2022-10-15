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

const int MN = 5e4;
int n, m;
vector<string> grid;

void solve() {
    int cntOnRow[n + 1], cntOnCol[m + 1];
    memset(cntOnRow, 0, sizeof cntOnRow);
    memset(cntOnCol, 0, sizeof cntOnCol);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cntOnRow[i] += grid[i][j] == '*';
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cntOnCol[i] += grid[j][i] == '*';
    
    int best = INF, req = n + m - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            best = min(best, req - (cntOnRow[i] + cntOnCol[j] - (grid[i][j] == '*')));
        }
    }
    cout << best << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; scan(t);
    while (t--) {
        scan(n, m);

        grid.resize(n);
        for (int i = 0; i < n; i++)
            scan(grid[i]);
        
        solve();
    }

    return 0;
}