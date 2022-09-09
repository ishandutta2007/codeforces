#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 2e5 + 5;

int ls, lt, k;
int s[MAXN], t[MAXN];
string tmp;

int chtn(char ch) {
    if (ch == 'A') {
        return 0;
    }
    if (ch == 'C') {
        return 1;
    }
    if (ch == 'G') {
        return 2;
    }
    if (ch == 'T') {
        return 3;
    }
    assert(false);
}

int nowbal[4];
bool can[4][MAXN];
bitset <MAXN> can2[4];
bitset <MAXN> t2[4];
bitset <MAXN> res;

int zf[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> ls >> lt >> k;

    cin >> tmp;    
    for (int i = 0; i < ls; ++i) {  
        s[i] = chtn(tmp[i]);
    }

    cin >> tmp;    
    for (int i = 0; i < lt; ++i) {  
        t[i] = chtn(tmp[i]);
        t2[t[i]][i] = 1;
    }

    for (int i = 0; i <= k; ++i) {
        nowbal[s[i]]++;
    }

    for (int i = 0; i < ls; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (nowbal[j]) {
                can2[j][i] = 1;
            }
        }
        if (i - k >= 0) {
            nowbal[s[i - k]]--;
        }
        if (i + k + 1 < ls) {
            nowbal[s[i + k + 1]]++;
        }
    }

    for (int i = 0; i < ls; ++i) {
        res[i] = 1;
    }

    int ans = 0;
    for (int i = 0; i < lt; ++i) {
        res &= can2[t[i]] >> i;
        if (i & 1 && clock() > CLOCKS_PER_SEC * 2.8) {
            break;
        }
    }

    for (int i = 0; i < ls; ++i) {
        ans += res[i];
    }

    cout << ans << endl;

    return 0;
}