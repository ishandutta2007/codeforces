#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second

using namespace std;

const int MAXN = (int) 1e3;

pair <int, int> pts[MAXN + 1];

bool used[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> pts[i].y;
        pts[i].x = i;
    }
    bool flag = 1;
    for(i = 4; i <= n && flag; i++) {
        if(1LL * (pts[3].y - pts[2].y) * (pts[i].x - pts[2].x) != 1LL * (pts[i].y - pts[2].y) * (pts[3].x - pts[2].x))
            flag = 0;
    }
    if(flag == 1 && 1LL * (pts[3].y - pts[2].y) * (pts[2].x - pts[1].x) != 1LL * (pts[2].y - pts[1].y) * (pts[3].x - pts[2].x)) {
        cout << "Yes";
        return 0;
    }
    for(i = 2; i <= n; i++) {
        memset(used, 0, sizeof(used));
        used[1] = 1;
        for(j = 2; j <= n; j++)
            if(1LL * (pts[i].y - pts[1].y) * (pts[j].x - pts[1].x) == 1LL * (pts[j].y - pts[1].y) * (pts[i].x - pts[1].x))
                used[j] = 1;
        j = 1;
        while(j <= n && used[j])
            j++;
        if(j <= n) {
            int pos1 = j;
            j++;
            while(j <= n && used[j])
                j++;
            if(j == n + 1) {
                cout << "Yes";
                return 0;
            }
            int pos2 = j;
            flag = 1;
            j++;
            while(j <= n && flag) {
                if(used[j] == 0 && 1LL * (pts[pos2].y - pts[pos1].y) * (pts[j].x - pts[pos1].x) != 1LL * (pts[j].y - pts[pos1].y) * (pts[pos2].x - pts[pos1].x)) {
                    used[j] = 1;
                    flag = 0;
                }
                j++;
            }
            if(flag == 1 && 1LL * (pts[pos2].y - pts[pos1].y) * (pts[i].x - pts[1].x) == 1LL * (pts[i].y - pts[1].y) * (pts[pos2].x - pts[pos1].x)) {
                //cout << pos1 << " " << pos2;
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    //cin.close();
    //cout.close();
    return 0;
}