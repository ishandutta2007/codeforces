#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int ans[c][c], n;
bool v[c][c], baj;
void dfs(int a, int b, int ert) {
    //cout << "dfs " << a << " " << b << " " << ert << "\n";
    if (ans[a][b]!=0 && ans[a][b]!=ert) {
        baj=1;
        return;
    }
    if (v[a][b]) {
        return;
    }
    v[a][b]=true;
    ans[a][b]=ert;
    if (a==1 && b==1) {
        return dfs(a, b+1, ert);
    }
    if (a==1 && b==n) {
        return dfs(a+1, b, ert);
    }
    if (a==n && b==n) {
        return dfs(a, b-1, ert);
    }
    if (a==n && b==1) {
        return dfs(a-1, b, ert);
    }

    if (a==1) {
        if (b%2==1) {
            return dfs(a, b+1, ert);
        } else {
            return dfs(a+1, b+1, -ert);
        }
    }
    if (b==n) {
        if (a%2==1) {
            return dfs(a+1, b, ert);
        } else {
            return dfs(a+1, b-1, -ert);
        }
    }
    if (a==n) {
        if (b%2==0) {
            return dfs(a, b-1, ert);
        } else {
            return dfs(a-1, b-1, -ert);
        }
    }
    if (b==1) {
        if (a%2==0) {
            return dfs(a-1, b, ert);
        } else {
            return dfs(a-1, b+1, -ert);
        }
    }

    if ((a+b)%2==1) {
        if (b>a) {
            return dfs(a+1, b+1, -ert);
        } else {
            return dfs(a-1, b-1, -ert);
        }
    } else {
        if (a+b<n+1) {
            return dfs(a-1, b+1, -ert);
        } else {
            return dfs(a+1, b-1, -ert);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    //dfs(1, 1, 1);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char c;
            cin >> c;
            if (c=='S') {
                ans[i][j]=1;
            }
            if (c=='G') {
                ans[i][j]=-1;
            }
        }
    }
    if (n%2) {
        cout << "NONE\n";
        return 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!v[i][j] && ans[i][j]) {
                dfs(i, j, ans[i][j]);
            }
        }
    }

    if (baj) {
        cout << "NONE\n";
        return 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (!v[i][j]) {
                cout << "MULTIPLE\n";
                return 0;
            }
        }
    }
    cout << "UNIQUE\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << (ans[i][j]==1 ? 'S' : 'G');
        }
        cout << "\n";
    }
    return 0;
}
/*
6
......
......
..S...
......
......
G.....
*/