#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const double eps = 1e-10;

const int MEM_SIZE = 200 * 1024 * 1024;
int MEM_POS = 0;
char MEM[MEM_SIZE];

inline void* operator new(size_t l) {
    MEM_POS += l;
    assert(MEM_POS <= MEM_SIZE);
    return MEM + MEM_POS - l;
}

inline void operator delete(void*) {}

double a, b, c, d;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    cin >> a >> b >> c >> d;

    double l = 0, r = max(max(fabs(a), fabs(b)), max(fabs(c), fabs(d)));

    int co = 0;
    while (true) {
        if (co - 1000 == 0) {
            co = 0;
            if (clock() > CLOCKS_PER_SEC * 0.9) {
                break;
            }
        }
        ++co;
        double med = (r + l) / 2;
        double la = a - med, ra = a + med;
        double ld = d - med, rd = d + med;
        double q = la * ld, w = la * rd, e = ra * ld, t = ra * rd;
        double lad = min(min(q, w), min(e, t));
        double rad = max(max(q, w), max(e, t));
        double lc = c - med, rc = c + med;
        double lb = b - med, rb = b + med;
        q = lc * lb, w = lc * rb, e = rc * lb, t = rc * rb;
        double lbc = min(min(q, w), min(e, t));
        double rbc = max(max(q, w), max(e, t));
        //cerr << med << " " << lad << " " << rad << " " << lbc << " " << rbc << endl;
        if (max(lbc, lad) <= min(rbc, rad)) {
            r = med;
        } else {
            l = med;
        }
    }

    printf("%.10lf", (double) l);

    return 0;
}