#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

typedef pair<pii, int> Vector;

const int maxn = 123456;
const ll maxlen = 2.25e12;

int n;
Vector v[maxn];
int mat[maxn];
bool sig[maxn];

pii operator + (const pii &lhs, const pii &rhs) {
    return mp(lhs._1 + rhs._1, lhs._2 + rhs._2);
}

pii operator - (const pii &lhs, const pii &rhs) {
    return mp(lhs._1 - rhs._1, lhs._2 - rhs._2);
}

inline ll len(pii a) {
    return ll(a._1) * a._1 + ll(a._2) * a._2;
}

int main() {
    scanf("%d", &n);
    pii now;
    REP(i, n) {
        scanf("%d%d", &v[i]._1._1, &v[i]._1._2);
        v[i]._2 = i;
    }
    do {
        random_shuffle(v, v + n);
        now = mp(0, 0);
        REP(i, n) {
            pii n1 = now + v[i]._1, n2 = now - v[i]._1;
            if (len(n1) > len(n2)) {
                now = n2;
                sig[v[i]._2] = false;
            } else {
                now = n1;
                sig[v[i]._2] = true;
            }
        }
    } while (len(now) > maxlen);
//    BUG(len(now));
    REP(i, n) printf("%d ", sig[i] ? 1 : -1);
    puts("");
    return 0;
}