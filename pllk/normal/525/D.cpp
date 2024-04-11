#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
string s[2222];
int p[2222][2222];
vector<pair<int,int>> v;

void poista(int y, int x) {
    if (y < 0 || x < 0) return;
    if (y >= n-1 || x >= m-1) return;
    int c = 0;
    if (s[y][x] == '.') c++;
    if (s[y+1][x] == '.') c++;
    if (s[y][x+1] == '.') c++;
    if (s[y+1][x+1] == '.') c++;
    if (c != 3) return;
    for (int i = 0; i <= 1; i++)
    for (int j = 0; j <= 1; j++) {
        if (s[y+i][x+j] == '*' && !p[y+i][x+j]) {
            p[y+i][x+j] = 1;
            v.push_back(make_pair(y+i,x+j));
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            poista(i,j);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        int y = v[i].first;
        int x = v[i].second;
        s[y][x] = '.';
        for (int a = -1; a <= 1; a++) {
            for (int b = -1; b <= 1; b++) {
                poista(y+a, x+b);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << "\n";
    }
}