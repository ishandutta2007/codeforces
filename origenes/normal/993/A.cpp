#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

pii operator - (pii a, pii b) {
    return {a._1 - b._1, a._2 - b._2};
}

inline int cross(pii a, pii b) {
    return abs(a._1 * b._2 - a._2 * b._1);
}

int area2(pii a, pii b, pii o) {
    return cross(o - a, o - b);
}

pii s1[5], s2[5];

int main() {
    REP(i, 4) {
        scanf("%d%d", &s1[i]._1, &s1[i]._2);
        s1[4]._1 += s1[i]._1;
        s1[4]._2 += s1[i]._2;
        s1[i]._1 *= 4;
        s1[i]._2 *= 4;
    }
    REP(i, 4) {
        scanf("%d%d", &s2[i]._1, &s2[i]._2);
        s2[4]._1 += s2[i]._1;
        s2[4]._2 += s2[i]._2;
        s2[i]._1 *= 4;
        s2[i]._2 *= 4;
    }
    int a1 = cross(s1[1] - s1[2], s1[3] - s1[2]);
    int a2 = cross(s2[1] - s2[2], s2[3] - s2[2]);
    REP(i, 5) {
        int tot = 0;
        REP(j, 4) tot += area2(s1[j], s1[(j + 1) % 4], s2[i]);
        if (tot == a1 * 2) {
            puts("YES");
            return 0;
        }
    }
    REP(i, 5) {
        int tot = 0;
        REP(j, 4) tot += area2(s2[j], s2[(j + 1) % 4], s1[i]);
        if (tot == a2 * 2) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}