#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1000 + 5;

template <typename T1, typename T2, typename T3>
struct triple {
    T1 first;
    T2 second;
    T3 third;
    triple(): first(), second(), third() {}
    triple(T1 first, T2 second, T3 third) : first(first), second(second), third(third) {}

    bool operator==(const triple& rhs) const { return tie(first, second, third) == tie(rhs.first, rhs.second, rhs.third); }
    bool operator!=(const triple& rhs) const { return !(*this == rhs); }
    bool operator< (const triple& rhs) const { return tie(first, second, third) < tie(rhs.first, rhs.second, rhs.third); }
    bool operator> (const triple& rhs) const { return rhs < *this; }
    bool operator<=(const triple& rhs) const { return !(*this > rhs); }
    bool operator>=(const triple& rhs) const { return !(*this < rhs); }
};

int n, m, xt, yt, xm, ym;
string a[N];

bool visited[N][N][4];
int lvl[N][N][4];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

string s1 = "^>v<", s2 = "URDL";

char change(char c, int t) {
    if (c == '+')
        return '+';
    if (c == '-')
        return t & 1 ? '|' : '-';
    if (c == '|')
        return t & 1 ? '-' : '|';
    if (c == '^')
        return s1[t];
    if (c == '>')
        return s1[(t + 1) % 4];
    if (c == 'v')
        return s1[(t + 2) % 4];
    if (c == '<')
        return s1[(t + 3) % 4];
    if (c == 'U')
        return s2[t];
    if (c == 'R')
        return s2[(t + 1) % 4];
    if (c == 'D')
        return s2[(t + 2) % 4];
    return s2[(t + 3) % 4];
}

map<char, set<int>> skip;

int bfs() {
    queue<triple<int, int, int>> q;
    q.emplace(xt, yt, 0);

    visited[xt][yt][0] = true;
    lvl[xt][yt][0] = 0;

    while (!q.empty()) {
        auto[x, y, t] = q.front();
        q.pop();

        if (!visited[x][y][(t + 1) % 4]) {
            visited[x][y][(t + 1) % 4] = true;
            lvl[x][y][(t + 1) % 4] = 1 + lvl[x][y][t];
            q.emplace(x, y, (t + 1) % 4);
        }

        char ch = change(a[x][y], t);
        for (int k = 0; k < 4; k++) {
            if (skip[ch].count(k)) continue;

            int new_x = x + dx[k], new_y = y + dy[k];

            if (new_x >= 0 and new_x < n and new_y >= 0 and new_y < m and !visited[new_x][new_y][t] and a[new_x][new_y] != '*') {
                char temp = change(a[new_x][new_y], t);
                if (k < 2 and skip[temp].count(1 - k)) continue;
                if (k > 1 and skip[temp].count(5 - k)) continue;

                if (new_x == xm and new_y == ym)
                    return 1 + lvl[x][y][t];

                visited[new_x][new_y][t] = true;
                lvl[new_x][new_y][t] = 1 + lvl[x][y][t];
                q.emplace(new_x, new_y, t);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> xt >> yt >> xm >> ym;
    --xt; --yt; --xm; --ym;

    if (xt == xm and yt == ym) {
        cout << "0\n";
        return 0;
    }

    skip['+'] = {};
    skip['-'] = {0, 1};
    skip['|'] = {2, 3};
    skip['^'] = {0, 2, 3};
    skip['>'] = {0, 1, 3};
    skip['v'] = {1, 2, 3};
    skip['<'] = {0, 1, 2}; //URDL
    skip['U'] = {1};
    skip['R'] = {2};
    skip['D'] = {0};
    skip['L'] = {3};
    cout << bfs();
    return 0;
}