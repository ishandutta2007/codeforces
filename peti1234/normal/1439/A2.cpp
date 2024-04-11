#include <bits/stdc++.h>

using namespace std;
const int c=102;
int w;
int n, m;
bool v[c][c];
string s;
vector<int> sol;
void pb(int a, int b) {
    v[a][b]=1-v[a][b];
    sol.push_back(a), sol.push_back(b);
}
void add(int a, int b, int c) {
    if (c!=1) pb(a, b);
    if (c!=2) pb(a, b+1);
    if (c!=3) pb(a+1, b);
    if (c!=4) pb(a+1, b+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m;
        sol.clear();
        for (int i=1; i<=n; i++) {
            cin >> s;
            for (int j=0; j<m; j++) {
                v[i][j+1]=(s[j]=='1');
            }
        }
        if (n%2) {
            for (int j=1; j<m; j++) {
                if (v[n][j]) add(n-1, j, 4);
            }
            if (v[n][m]) {
                add(n-1, m-1, 3);
            }
        }
        if (m%2) {
            if (v[n][m]) {
                add(n-1, m-1, 3);
            }
            if (v[n-1][m]) {
                if (n==2) {
                    add(n-1, m-1, 4);
                } else {
                    add(n-2, m-1, 3);
                }
            }
            for (int i=m-2; i>=1; i--) {
                if (v[i][m]) {
                    add(i, m-1, 4);
                }
            }
        }
        for (int i=1; i<n; i+=2) {
            for (int j=1; j<m; j+=2) {
                int db=v[i][j]+v[i][j+1]+v[i+1][j]+v[i+1][j+1];
                int a=v[i][j], b=v[i][j+1], c=v[i+1][j], d=v[i+1][j+1];
                if ((db-a)%2) add(i, j, 1);
                if ((db-b)%2) add(i, j, 2);
                if ((db-c)%2) add(i, j, 3);
                if ((db-d)%2) add(i, j, 4);
            }
        }
        int si=sol.size();
        cout << si/6 << "\n";
        for (int i=0; i<si; i+=6) {
            for (int j=0; j<6; j++) {
                cout << sol[i+j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
/*
1
5 5
01011
11001
00010
11011
10000
*/