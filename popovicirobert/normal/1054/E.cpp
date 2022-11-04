#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 300;

struct Data {
    int l1, c1, l2, c2;
};

deque <bool> mat[MAXN + 1][MAXN + 1];
vector <Data> sol1, sol2;

inline void move1(int l1, int c1, int l2, int c2) {
    sol1.push_back({l1, c1, l2, c2});
    mat[l2][c2].push_front(mat[l1][c1].back());
    mat[l1][c1].pop_back();
}

inline void move2(int l1, int c1, int l2, int c2) {
    sol2.push_back({l1, c1, l2, c2});
    mat[l2][c2].push_back(mat[l1][c1].front());
    mat[l1][c1].pop_front();
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            string str;
            cin >> str;
            for(auto it : str) {
                mat[i][j].push_back(it - '0');
            }
        }
    }
    /////////////////////////////////////
    for(i = 1; i < n; i++) {
        while(!mat[i][1].empty()) {
            move1(i, 1, n, 1);
        }
    }
    for(i = 2; i <= m; i++) {
        while(!mat[n][i].empty()) {
            move1(n, i, n, 1);
        }
    }
    for(i = 1; i < n; i++) {
        for(j = 2; j <= m; j++) {
            while(!mat[i][j].empty()) {
                if(mat[i][j].back() == 0) {
                    move1(i, j, i, 1);
                }
                else {
                    move1(i, j, n, j);
                }
            }
        }
    }
    for(i = 2; i < n; i++) {
        while(!mat[i][1].empty()) {
            move1(i, 1, 1, 1);
        }
    }
    for(i = 2; i < m; i++) {
        while(!mat[n][i].empty()) {
            move1(n, i, n, m);
        }
    }
    while(!mat[n][1].empty()) {
        if(mat[n][1].back() == 0) {
            move1(n, 1, 1, 1);
        }
        else {
            move1(n, 1, n, m);
        }
    }

    ///////////////////////////////////////////////
    ///////////////////////////////////////////////

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            string str;
            cin >> str;
            mat[i][j].clear();
            for(auto it : str) {
                mat[i][j].push_back(it - '0');
            }
        }
    }
    //////////////////////////////////////////////
    for(i = 1; i < n; i++) {
        while(!mat[i][1].empty()) {
            move2(i, 1, n, 1);
        }
    }
    for(i = 2; i <= m; i++) {
        while(!mat[n][i].empty()) {
            move2(n, i, n, 1);
        }
    }
    for(i = 1; i < n; i++) {
        for(j = 2; j <= m; j++) {
            while(!mat[i][j].empty()) {
                if(mat[i][j].front() == 0) {
                    move2(i, j, i, 1);
                }
                else {
                    move2(i, j, n, j);
                }
            }
        }
    }
    for(i = 2; i < n; i++) {
        while(!mat[i][1].empty()) {
            move2(i, 1, 1, 1);
        }
    }
    for(i = 2; i < m; i++) {
        while(!mat[n][i].empty()) {
            move2(n, i, n, m);
        }
    }
    while(!mat[n][1].empty()) {
        if(mat[n][1].front() == 0) {
            move2(n, 1, 1, 1);
        }
        else {
            move2(n, 1, n, m);
        }
    }

    reverse(sol2.begin(), sol2.end());
    ///////////////////////////////////////////////////////////
    cout << sol1.size() + sol2.size() << "\n";
    for(auto it : sol1) {
        cout << it.l1 << " " << it.c1 << " " << it.l2 << " " << it.c2 << "\n";
    }
    for(auto it : sol2) {
        cout << it.l2 << " " << it.c2 << " " << it.l1 << " " << it.c1 << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}