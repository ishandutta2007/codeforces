#include <cstdio>
#include <algorithm>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define BS 5375
#define N 200000

using namespace std;

struct _ {
    int m, r;
    long long M, R;
    bool operator<(const _&o) const {
        if (r == 0 && o.r == 0) return m < o.m;
        else if (r == 0) return false;
        else if (o.r == 0) return true;
        return m/r < o.m/o.r;
    }
};

int s[N], m[N], r[N];
int lt[N];
int blt[N];
_ x[N];
int n, Z;

long long min(long long a, long long b) {
    return (((a-b)>>63)&(a^b))^b;
}

void read(int &r) {
    r = 0;
    char ch;
    while ((ch=getchar())<'0');
    while (ch >= '0') {
        r = r*10 + ch -'0';
        ch = getchar();
    }
}

int main() {
    read(n);
    FO(i,0,n) read(s[i]), read(m[i]), read(r[i]);
    FO(i,0,n) lt[i] = 0, blt[i] = -1;

    FO(i,0,n) x[i].m = x[i].M = m[i], x[i].r = x[i].R = r[i];
    for (int i = 0; i < n; i += BS) {
        int S = i, E = min(i+BS,n);
        sort(x+S,x+E);
        FO(i,S+1,E) x[i].m += x[i-1].m;
        for (int i = E-2; i >= S; i--) x[i].r += x[i+1].r;
    }

    read(Z);
    FO(T,0,Z) {
        int _t, L, R;
        read(_t); read(L); read(R);
        L--; R--;
        long long res = 0, t = _t;
        int bl = L/BS, br = R/BS;
        if (bl == br) {
            if (blt[bl] != -1) {
                FO(i,bl*BS,bl*BS+BS) lt[i] = blt[bl];
            }
            blt[bl] = -1;
            FO(i,L,R+1) {
                res += min(m[i], s[i]+r[i]*(t-lt[i]));
                s[i] = 0; lt[i] = t;
            }
        } else {
            if (blt[bl] != -1) {
                FO(i,bl*BS,bl*BS+BS) lt[i] = blt[bl];
            }
            if (blt[br] != -1) {
                FO(i,br*BS,br*BS+BS) lt[i] = blt[br];
            }
            blt[bl] = -1;
            FO(i,L,bl*BS+BS) {
                res += min(m[i], s[i]+r[i]*(t-lt[i]));
                s[i] = 0; lt[i] = t;
            }
            blt[br] = -1;
            FO(i,br*BS,R+1) {
                res += min(m[i], s[i]+r[i]*(t-lt[i]));
                s[i] = 0; lt[i] = t;
            }
            FO(bi,bl+1,br) {
                if (blt[bi] == -1) {
                    FO(i,bi*BS,bi*BS+BS) {
                        res += min(m[i], s[i]+r[i]*(t-lt[i]));
                        s[i] = 0; lt[i] = t;
                    }
                    blt[bi] = t;
                } else {
                    int S = bi*BS, E = min(bi*BS+BS,n);
                    int lastcap = S-1;
                    int s = S, e = E-1;
                    while (s <= e) {
                        int md = (s+e)/2;
                        if ((t-blt[bi])*x[md].R > x[md].M) {
                            lastcap = md;
                            s = md+1;
                        } else e = md-1;
                    }
                    if (lastcap != S-1) res += x[lastcap].m;
                    if (lastcap+1 != E) res += x[lastcap+1].r * (t-blt[bi]);
                    blt[bi] = t;
                }
            }
        }
        printf("%lld\n", res);
    }
}