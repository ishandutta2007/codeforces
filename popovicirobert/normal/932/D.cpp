#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

const int MAXN = (int) 4e5;
const int LOG = 19;

int father[MAXN + 1][LOG + 1];
int dp[MAXN + 1][LOG + 1];
int lvl[MAXN + 1];

int to[MAXN + 1][LOG + 1];
ll sp[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int type, q, bit;
    ll r, w, x;
    ios::sync_with_stdio(false);
    cin >> q;
    int last = 0;
    int cnt = 1;
    lvl[1] = 1;
    while(q > 0) {
        q--;
        cin >> type >> r;
        r ^= last;
        if(type == 1) {
            cin >> w;
            w ^= last;
            dp[++cnt][0] = w;
            father[cnt][0] = r;
            for(bit = 1; bit <= LOG; bit++) {
                father[cnt][bit] = father[father[cnt][bit - 1]][bit - 1];
                dp[cnt][bit] = max(dp[cnt][bit - 1], dp[father[cnt][bit - 1]][bit - 1]);
            }
            int nod = r;
            for(bit = LOG; bit >= 0; bit--) {
                if(dp[nod][bit] < w)
                    nod = father[nod][bit];
            }
            if(dp[nod][0] < w)
                nod = father[nod][0];
            if(dp[r][0] >= w)
                nod = r;
            to[cnt][0] = nod;
            for(bit = 1; bit <= LOG; bit++) {
                to[cnt][bit] = to[to[cnt][bit - 1]][bit - 1];
            }
            sp[cnt] = sp[nod] + w;
            lvl[cnt] = lvl[nod] + 1;
        }
        else {
            cin >> x;
            x ^= last;
            int nod = r;
            for(bit = LOG; bit >= 0; bit--) {
                if(sp[r] - sp[to[nod][bit]] <= x)
                    nod = to[nod][bit];
            }
            last = lvl[r] - lvl[nod];
            cout << last << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}