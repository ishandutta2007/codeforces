#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
const int MAXN = 2e5 + 5;
const int MAXL = 5e5 + 5, bd = 19, bdv = 1 << bd;
const int INF = 1e9 + 7;
const int MAXQ = 5e5 + 5;

int bdarr[bd + 1];
int maxbd[MAXL];

/*
const int MAX_MEM = (int)230 * 1024 * 1024;

int mpos, max_mpos;
char memory[MAX_MEM];                        

inline void * operator new (size_t n) {
  char *res = memory + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}

inline void operator delete (void *) { }*/

int n, q;
string s;
vector <string> inp;
int startfrom[MAXN];
int whose[MAXL];

vector <int> calc_suffarr(string s) {
    vector <int> suffarr;
    vector <int> classes;
    suffarr.resize(szof(s));
    classes.resize(szof(s));
    for (int i = 0; i < szof(s); ++i) {
        classes[i] = s[i];
    }
    for (int j = 1, i = 0; j <= szof(s); j <<= 1, ++i) {
        //cerr << i << endl;
        for (int k = 0; k < szof(s); ++k) {
            //cerr << classes[k] << " ";
        }
        //cerr << endl;
        vector <pair <pii, int> > v;
        for (int k = 0; k < szof(s); ++k) {
            v.puba(mapa(mapa(classes[k], classes[(k + j) % szof(s)]), k));
        }
        sort(bend(v));
        pii prev = v[0].ff;
        int c = 0;
        for (int k = 0; k < szof(v); ++k) {
            if (prev != v[k].ff) {
                prev = v[k].ff;
                ++c;
            }
            classes[v[k].ss] = c;
        }
    }
    for (int i = 0; i < szof(s); ++i) {
        suffarr[classes[i]] = i;
    }
    return suffarr;
}

int sparsetable[bd][MAXL];

/*
int rmq[bdv * 2];

int segtree_getmin(int v, int vl, int vr, int l, int r) {
    if (vr < l || r < vl) {
        return INF;
    }
    if (l <= vl && vr <= r) {
        return rmq[v];
    }
    int vm = (vl + vr) / 2;
    return min(segtree_getmin(v * 2, vl, vm, l, r), segtree_getmin(v * 2 + 1, vm + 1, vr, l, r));
}*/

int segtree_getmin(int v, int vl, int vr, int l, int r) {
    int nbd = maxbd[r - l + 1];
    return min(sparsetable[nbd][r], sparsetable[nbd][l + bdarr[nbd] - 1]);
}

int ans[MAXQ];
int ssum[MAXN];

int get_ssum(int l, int r) {
    return ssum[r + 1] - ssum[l];
}

int rsq[bdv * 2];

int segtree_plus(int pos, int num) {
    pos += bdv;
    rsq[pos] += num;
    pos /= 2;
    while (pos) {
        rsq[pos] = rsq[pos * 2] + rsq[pos * 2 + 1];
        pos /= 2;
    }
    return 0;
}

int segtree_getsum(int v, int vl, int vr, int l, int r) {
    if (vr < l || r < vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return rsq[v];
    }
    int vm = (vl + vr) / 2;
    return segtree_getsum(v * 2, vl, vm, l, r) + segtree_getsum(v * 2 + 1, vm + 1, vr, l, r);
}

char ns[MAXL];

int main() {    
    //freopen("inp", "r", stdin);
    //freopen(".out", "w", stdout);

    bdarr[0] = 1;
    for (int i = 1; i <= bd; ++i) {
        bdarr[i] = bdarr[i - 1] * 2;
    }

    maxbd[0] = 0;

    for (int i = 1; i < MAXL; ++i) {
        maxbd[i] = maxbd[i - 1];
        if (bdarr[maxbd[i]] * 2 <= i) {
            ++maxbd[i];
        }
    }
    /*
    for (int i = 0; i < 10; ++i) {
        cerr << maxbd[i] << endl;
    }*/

    //cin >> n >> q;
    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; ++i) {
        //string ns;
        //cin >> ns;
        scanf("%s", ns);
        int len = strlen(ns);
        ssum[i + 1] = ssum[i] + len + 1;
        startfrom[i] = szof(s);
        inp.puba(ns);
        //s += ns;
        for (int j = 0; j < len; ++j) {
            s += ns[j];
        }
        /*
        for (int j = startfrom[i]; j < szof(s); ++j) {
            whose[j] = i;
        }*/
        if (i < n - 1) {
            s += '#';
        } else {
            s += '!';
        }
    }
    
    startfrom[n] = szof(s);

    //s = "abacaba#";

    vector <int> suffarr = calc_suffarr(s);
    /*
    for (int i = 0; i < szof(s); ++i) {
        cout << suffarr[i] << " ";
    }
    cout << endl;*/
    vector <int> classes;
    classes.resize(szof(suffarr));

    for (int i = 0; i < szof(suffarr); ++i) {
        classes[suffarr[i]] = i;
    }

    
    
    //cerr << "@" << endl;

    vector <int> lcp;
    lcp.resize(szof(suffarr));

    //cerr << szof(s) << endl;
    
    for (int i = 0; i < szof(suffarr); ++i) {
        if (classes[i] == szof(suffarr) - 1) {
            //cerr << "skip" << endl;
            continue;
        }
        //cerr << i << " " << s[i] << endl;
        if (i > 0) {
            lcp[classes[i]] = max(0, lcp[classes[i - 1]] - 1);
        }
        //cerr << lcp[classes[i]] << endl;
        //cerr << i + suffarr[classes[i] + 1] << endl;
        for (int j = lcp[classes[i]]; i + j < szof(s) && j + suffarr[classes[i] + 1] < szof(s) && s[j + i] == s[j + suffarr[classes[i] + 1]]; ++j) {
            //cerr << "@ " << j << endl;
            ++lcp[classes[i]];
        }
    }
    
    /*
    for (int i = 0; i < szof(s); ++i) {
        for (int j = suffarr[i]; j < szof(s); ++j) {
            cout << s[j];
        }
        cout << endl;
        cout << lcp[i] << endl;
    }*/
    
    /*
    for (int i = 0; i < szof(s); ++i) {
        rmq[i + bdv] = lcp[i];
    }
    for (int i = bdv - 1; i > 0; --i) {
        rmq[i] = min(rmq[i * 2], rmq[i * 2 + 1]);
    }*/

    for (int i = 0; i < szof(s); ++i) {
        sparsetable[0][i] = lcp[i];
        for (int j = 1; i - bdarr[j] + 1 >= 0; ++j) {
            sparsetable[j][i] = min(sparsetable[j - 1][i], sparsetable[j - 1][i - bdarr[j - 1]]);
        }
    }

    vector <pii > froml, fromr;
    vector <pii > lr;

    for (int i = 0; i < q; ++i) {
        //cerr << i << endl;
        int l, r, num;
        //cin >> l >> r >> num;
        scanf("%d%d%d", &l, &r, &num);
        --l;--r;--num;
        froml.puba(mapa(l, i));
        fromr.puba(mapa(r, i));
        //ans[i] = get_ssum(l, r);
        //cerr << ans[i] << endl;
        int pos = classes[startfrom[num]];
        int len = szof(inp[num]);
        int lg = pos, rg = szof(s);
        while (rg - lg > 1) {
            int med = (lg + rg) / 2;
            //cerr << med << " " << segtree_getmin(1, 0, bdv - 1, pos, med) << endl;                       
            if (segtree_getmin(1, 0, bdv - 1, pos, med - 1) >= len) {
                lg = med;
            } else {
                rg = med;
            }
        }
        int rrg = lg;
        lg = -1, rg = pos;
        while (rg - lg > 1) {
            int med = (lg + rg) / 2;
            //cerr << lg << " " << rg << " " << med << endl;
            if (segtree_getmin(1, 0, bdv - 1, med, pos - 1) >= len) {
                rg = med;
            } else {
                lg = med;
            }
        }
        int rlg = rg;
        //cerr << rlg << " " << rrg << endl;
        ans[i] = rrg - rlg + 1;
        lr.puba(mapa(rlg, rrg));
    }

    //cerr << "@" << endl;

    sort(bend(froml));
    sort(bend(fromr));
    reverse(bend(fromr));

    int c = 0;
    for (int i = 0; i < n; ++i) {
        //cerr << i << endl;
        while (c < szof(froml) && froml[c].ff == i) {
            int num = froml[c].ss;
            ans[num] -= segtree_getsum(1, 0, bdv - 1, lr[num].ff, lr[num].ss);
            ++c;
        }
        for (int j = startfrom[i]; j < startfrom[i + 1]; ++j) {
            segtree_plus(classes[j], 1);
        }
    }

    memset(rsq, 0, sizeof rsq);

    c = 0;
    for (int i = n - 1; i >= 0; --i) {
        //cerr << i << endl;
        while (c < szof(fromr) && fromr[c].ff == i) {
            int num = fromr[c].ss;
            ans[num] -= segtree_getsum(1, 0, bdv - 1, lr[num].ff, lr[num].ss);
            ++c;
        }
        for (int j = startfrom[i]; j < startfrom[i + 1]; ++j) {
            segtree_plus(classes[j], 1);
        }
    }

    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}