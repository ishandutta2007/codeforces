#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < k; i++) {
        int c;
        cin >> c;
        c--;
        int x = 0,y = c;
        while (x < n) {
            if(a[x][y] == 1) {
                a[x][y] = 2;
                y++;
            }
            else if(a[x][y] == 2) {
                x++;
            }
            else {
                a[x][y] = 2;
                y--;
            }
        }
        cout << y+1 << ((i+1 == k)?"\n":" ");
    }
}