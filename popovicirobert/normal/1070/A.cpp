#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXD = 500;
const int MAXS = 5000;

bool vis[MAXD][MAXS + 1];
int dig[MAXD][MAXS + 1], from[MAXD][MAXS + 1];

struct Data {
    int last, c, prev_r;
    int r, sum;
    bool operator <(const Data &other) const {
        return last < other.last;
    }
};

queue <Data> mst;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int d, s;
    ios::sync_with_stdio(false);
    cin >> d >> s;
    mst.push({0, 0, 0, 0, 0});
    int last = 0;
    while(!mst.empty()) {
        auto it = mst.front();
        int r = it.r, sum = it.sum;
        int prev_r = it.prev_r, c = it.c;
        mst.pop();
        if(vis[r][sum]) {
            continue;
        }
        vis[r][sum] = 1;
        dig[r][sum] = c;
        from[r][sum] = prev_r;
        for(c = 0; c < 10; c++) {
            int cur = (r * 10 + c) % d;
            if(sum + c <= s && vis[cur][sum + c] == 0) {
                mst.push({++last, c, r, cur, sum + c});
            }
        }
    }
    if(vis[0][s]) {
        vector <int> sol;
        int r = 0;
        while(s > 0) {
            int cur = dig[r][s];
            sol.push_back(cur);
            r = from[r][s];
            s -= cur;
        }
        reverse(sol.begin(), sol.end());
        for(auto it : sol) {
            cout << it;
        }
        return 0;
    }
    cout << -1;
    //cin.close();
    //cout.close();
    return 0;
}