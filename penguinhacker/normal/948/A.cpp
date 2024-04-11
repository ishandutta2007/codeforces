#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int dx[4] = {1,-1,0,0}; int dy[4] = {0,0,1,-1};

int main() {
	int R, C;
	cin >> R >> C;
    char grid[502][502];
    for (int i=1; i<=R; ++i) {
        string s;
        cin >> s;
        for (int j=1; j<=C; ++j) {
            grid[i][j] = s[j-1];
        }
    }
    for (int i=0; i<C+2; ++i) {
        grid[0][i] = '.';
        grid[R+1][i] = '.';
    }
    for (int i=0; i<R+2; ++i) {
        grid[i][0] = '.';
        grid[i][C+1] = '.';
    }

    for (int i=1; i<=R; ++i) {
        for (int j=1; j<=C; ++j) {
            if (grid[i][j] == 'S') {
                for (int k=0; k<4; ++k) {
                    if (grid[i+dx[k]][j+dy[k]] == 'W') {
                        cout << "No" << '\n';
                        return 0;
                    }
                }
            }
        }
    }

    cout << "Yes" << '\n';
	for (int i=1; i<=R; ++i) {
        for (int j=1; j<=C; ++j) {
            if (grid[i][j] == '.') cout << 'D';
            else cout << grid[i][j];
        }
        cout << '\n';
    }
	return 0;
}