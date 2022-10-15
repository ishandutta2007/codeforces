#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long
#define M 1000000007

int n, m;
string s[555];


#define P pair<int,int>
#define L(x,y) ((x)*600+(y))

int d[555][555];
int v[555][555];

vector<P> vl[555];
vector<P> ol[555];

ll t;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    
    if (n == 1 && m == 1) {
        cout << 1 << "\n";
        return 0;
    }
    if (n == 1 && m == 2) {
        cout << (s[0][0] == s[0][1]) << "\n";
        return 0;
    }
    if (n == 2 && m == 1) {
        cout << (s[0][0] == s[1][0]) << "\n";
        return 0;
    }
    
    int z = (n+m)/2-1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a = i+j;
            int b = n-i-1+m-j-1;
            if (a <= b) vl[a].push_back({i,j});
            if (b <= a) ol[b].push_back({i,j});
        }
    }
    d[0][n-1] = (s[0][0] == s[n-1][m-1]);
    for (int i = 1; i <= z; i++) {
        for (int a = 0; a < vl[i].size(); a++) {
            for (int b = 0; b < ol[i].size(); b++) {
                int y1 = vl[i][a].first;
                int x1 = vl[i][a].second;
                int y2 = ol[i][b].first;
                int x2 = ol[i][b].second;
                ll u = 0;
                if (s[y1][x1] == s[y2][x2]) {
                    if (y1-1 >= 0 && y2+1 < n) u += d[y1-1][y2+1];
                    u %= M;
                    if (x1-1 >= 0 && y2+1 < n) u += d[y1][y2+1];
                    u %= M;
                    if (y1-1 >= 0 && x2+1 < m) u += d[y1-1][y2];
                    u %= M;
                    if (x1-1 >= 0 && x2+1 < m) u += d[y1][y2];
                    u %= M;
                }
                v[y1][y2] = u;
                if (i == z && abs(x1-x2)+abs(y1-y2) <= 1) {
                    t += u;
                    t %= M;
                }
            }
        }
        for (int a = 0; a < vl[i].size(); a++) {
            for (int b = 0; b < ol[i].size(); b++) {
                int y1 = vl[i][a].first;
                int x1 = vl[i][a].second;
                int y2 = ol[i][b].first;
                int x2 = ol[i][b].second;
                d[y1][y2] = v[y1][y2];
            }
        }
    }
    cout << t << "\n";
}