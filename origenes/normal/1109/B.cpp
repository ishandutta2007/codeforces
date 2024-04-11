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

const int maxn = 5123;

char s[maxn << 1];
int n;

bool pal(int st, int en) {
    int i = st, j = en;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}

void rev(int st, int en) {
    int i = st, j = en;
    while (i < j) {
        swap(s[i], s[j]);
        i++, j--;
    }
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    map<int, int> tmp;
    FOR(i, 1, n) tmp[s[i]]++;
    if (tmp.size() == 1) {
        puts("Impossible");
        return 0;
    }
    if ((n & 1) && tmp.size() == 2 && (tmp.begin()->_2 == 1 || tmp.rbegin()->_2 == 1)) {
        puts("Impossible");
        return 0;
    }
    FOR(i, 1, n / 2) {
        if (pal(1, i) && pal(i + 1, n)) continue;
        rev(1, i);
        rev(i + 1, n);
        if (pal(1, n)) {
            puts("1");
            return 0;
        }
        rev(1, i);
        rev(i + 1, n);
    }
    puts("2");
}