#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
const long long INF = 100000000000000;
const int Y = 1000;
const int m = 1000;
vector<int>ED[Y + 1];
bool visited[Y + 1];
int p1, p2;
int v1 = -1, v2 = -1;
int y;
int cl[1001];
void dfs1(int i, int p) {
    if (i == v1 || i == v2) {
        if (v1 == i) {
            p1 = p;
        }
        else {
            p2 = p;
        }
    }
    for (auto x : ED[i]) {
        if (x == p)continue;
        dfs1(x, i);
    }
}
void dfs2(int i, int p) {
    if (ED[i].size() == 1) {
        v2 = v1;
        v1 = i;
    }
    for (auto x : ED[i]) {
        if (x == p)continue;
        dfs2(x, i);
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ++cl[a];
        ++cl[b];
        ED[a].push_back(b);
        ED[b].push_back(a);
    }
    int r = 1;
    for (int i = 1; i <= n; ++i) {
        if (cl[i] == 1) {
            v2 = v1;
            v1 = i;
        }
    }
    int ot = 0;
    while (ot != n/2) {
        cout << "? " << v1 << " " << v2 << endl;
        cin >> y;
        if (y == v1 || y == v2) {
            cout << "! " << y << endl;
            return 0;
        }
        r = y;
        for (auto x : ED[y]) {
            dfs1(x, y);
        }
        ED[v2].erase(find(ED[v2].begin(), ED[v2].end(), p2));
        ED[v1].erase(find(ED[v1].begin(), ED[v1].end(), p1));
        ED[p1].erase(find(ED[p1].begin(), ED[p1].end(), v1));
        ED[p2].erase(find(ED[p2].begin(), ED[p2].end(), v2));
        v1 = v2 = -1;
        if (ED[y].size()==0) {
            cout << "! " << y << endl;
            return 0;
        }
        dfs2(y, -1);
        ++ot;
    }
    cout << "! " << r;
    return 0;
}