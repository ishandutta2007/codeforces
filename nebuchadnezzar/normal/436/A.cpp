#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
const int MAXN = 2005;

int n, x;
int t, h, m;
vector <pair <int, int> > mas[2], mem[2];
bool used[2][MAXN];

int main() {    
    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        cin >> t >> h >> m;
        mas[t].puba(mapa(h, m));
    } 
    sort(all(mas[0]));
    sort(all(mas[1]));
    mem[0] = mas[0];
    mem[1] = mas[1];
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        int c = 0, nowx = x;
        
        while (true) {            
            int c2 = 0;
            pair <int, int> nowmax = mapa(-1, -1);
            while (c2 < szof(mas[(i + c) % 2]) && mas[(i + c) % 2][c2].ff <= nowx) {
                //cout << c2 << endl;
                if (!used[(i + c) % 2][c2]) {
                    nowmax = max(nowmax, mapa(mas[(i + c) % 2][c2].ss, c2));
                }
                ++c2;
            }
            if (nowmax.ff == -1) {
                break;
            }
            used[(i + c) % 2][nowmax.ss] = true;
            nowx += nowmax.ff;
            ++c;
        }
        ans = max(ans, c); 
        mas[0] = mem[0];
        mas[1] = mem[1];
        memset(used, 0, sizeof used);
    }

    cout << ans;
    return 0;
}