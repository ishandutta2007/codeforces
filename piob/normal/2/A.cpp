#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m;
string A[1010];
int C[1010];
map<string, int> M;
set<string> S;

int main(){
    cin >> n;
    FWD(i,0,n){
        cin >> A[i] >> C[i];
        M[A[i]] += C[i];
    }
    for(auto p : M) m = max(m, p.y);
    for(auto p : M) if(p.y == m) S.insert(p.x);
    M.clear();
    FWD(i,0,n){
        cin >> A[i] >> C[i];
        M[A[i]] += C[i];
        if(S.find(A[i]) != S.end() && M[A[i]] >= m){
            cout << A[i] << endl;
            return 0;
        }
    }
    return 0;
}