#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
int A[N][N];
int li[N][N], lj[N][N], ri[N][N], rj[N][N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            cin >> A[i][j];
        }
    }
    int id;
    for(int i = 1; i <= n; i ++ ){
        vector<int> pp;
        for(int j = 1; j <= m ; j ++ ){
            pp.push_back(A[i][j]);
        }
        sort(pp.begin(), pp.end());
        pp.resize(unique(pp.begin(), pp.end()) - pp.begin());
        for(int j = 1; j <= m; j ++ ){
            id = lower_bound(pp.begin(), pp.end(), A[i][j]) - pp.begin();
            li[i][j] = id;
            ri[i][j] = pp.size() - id - 1;
        }
    }
    for(int j = 1; j <= m; j ++ ){
        vector<int> pp;
        for(int i = 1; i <= n; i  ++ ){
            pp.push_back(A[i][j]);
        }
        sort(pp.begin(), pp.end());
        pp.resize(unique(pp.begin(), pp.end()) - pp.begin());
        for(int i = 1; i <= n; i ++ ){
            id = lower_bound(pp.begin(), pp.end(), A[i][j]) - pp.begin();
            lj[i][j] = id;
            rj[i][j] = pp.size() - id - 1;
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            cout << max(li[i][j], lj[i][j]) + max(ri[i][j], rj[i][j]) + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}