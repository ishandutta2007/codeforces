#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> A;
int co[100005];
int c2[100005];
int c3[100005];
int ro[100005];
int r2[100005];
int r3[100005];
signed main() {
    //cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    A.resize(N);
    int i, j;
    for(i=0;i<N;i++) {
        A[i].resize(M);
        for(j=0;j<M;j++) cin >> A[i][j];
    }
    int ans = 0;
    for(i=0;i<N;i++) {
        set<int> S;
        for(j=0;j<M;j++) {
            //co[A[i][j]]++;
            ans += c2[A[i][j]] + (i-c3[A[i][j]]) * co[A[i][j]];
            S.insert(A[i][j]);
        }
        for(auto it = S.begin();it!=S.end();it++) {
            c2[*it] += (i-c3[*it])*co[*it];
            c3[*it] = i + 1;
        }
        for(j=0;j<M;j++) co[A[i][j]]++;
        for(auto it = S.begin();it!=S.end();it++) {
            c2[*it] += co[*it];
        }
        //cout << ans << ' ';
    }
    //cout << "row\n";
    for(j=0;j<M;j++) {
        set<int> S;
        for(i=0;i<N;i++) {
            //co[A[i][j]]++;
            ans += r2[A[i][j]] + (j-r3[A[i][j]]) * ro[A[i][j]];
            S.insert(A[i][j]);
        }
        for(auto it = S.begin();it!=S.end();it++) {
            r2[*it] += (j-r3[*it])*ro[*it];
            r3[*it] = j + 1;
        }
        for(i=0;i<N;i++) ro[A[i][j]]++;
        for(auto it = S.begin();it!=S.end();it++) {
            r2[*it] += ro[*it];
        }

    }
    cout << ans;
}