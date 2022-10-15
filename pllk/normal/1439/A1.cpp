#include <iostream>
#include <vector>

using namespace std;

string s[101];

vector<vector<int>> moves;

void flip(int y, int x) {
    if (s[y][x] == '0') s[y][x] = '1';
    else s[y][x] = '0';
}

void add(vector<int> a, vector<int> b, vector<int> c) {
    moves.push_back({a[0],a[1],b[0],b[1],c[0],c[1]});
    flip(a[0],a[1]);
    flip(b[0],b[1]);
    flip(c[0],c[1]);
}

void fix(int y, int x) {
    vector<vector<int>> v0, v1;
    if (s[y][x] == '0') v0.push_back({y,x});
    if (s[y][x] == '1') v1.push_back({y,x});
    if (s[y][x+1] == '0') v0.push_back({y,x+1});
    if (s[y][x+1] == '1') v1.push_back({y,x+1});
    if (s[y+1][x] == '0') v0.push_back({y+1,x});
    if (s[y+1][x] == '1') v1.push_back({y+1,x});
    if (s[y+1][x+1] == '0') v0.push_back({y+1,x+1});
    if (s[y+1][x+1] == '1') v1.push_back({y+1,x+1});
    if (v0.size() == 4) return;
    if (v0.size() == 3) {
        add(v0[0],v0[1],v1[0]);
        fix(y,x);
    }
    if (v0.size() == 2) {
        add(v0[0],v0[1],v1[0]);
        fix(y,x);
    }
    if (v0.size() == 1) {
        add(v1[0],v1[1],v1[2]);
    }
    if (v0.size() == 0) {
        add(v1[0],v1[1],v1[2]);
        fix(y,x);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            s[i] = "#"+s[i];
        }
        moves.clear();
        for (int i = 1; i <= n-1; i++) {
            for (int j = 1; j <= m-1; j++) {
                fix(i,j);
            }
        }
        cout << moves.size() << "\n";
        for (auto v : moves) {
            for (auto x : v) cout << x << " ";
            cout << "\n";
        }
    }
}