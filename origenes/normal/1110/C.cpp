#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

map<int, int> ans;

void init() {
    ans[3] = 1;
    ans[7] = 1;
    ans[15] = 5;
    ans[31] = 1;
    ans[63] = 21;
    ans[127] = 1;
    ans[255] = 85;
    ans[511] = 73;
    ans[1023] = 341;
    ans[2047] = 89;
    ans[4095] = 1365;
    ans[8191] = 1;
    ans[16383] = 5461;
    ans[32767] = 4681;
    ans[65535] = 21845;
    ans[131071] = 1;
    ans[262143] = 87381;
    ans[524287] = 1;
    ans[1048575] = 349525;
    ans[2097151] = 299593;
    ans[4194303] = 1398101;
    ans[8388607] = 178481;
    ans[16777215] = 5592405;
    ans[33554431] = 1082401;
}

int q, a;

int main() {
    init();
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &a);
        if (ans.count(a)) printf("%d\n", ans[a]);
        else {
            REP(i, 25) if (a >= (1 << i) && a < (1 << i + 1)) {
                    int mask = 1 << i + 1;
                    printf("%d\n", mask - 1);
                    break;
                }
        }
    }
}