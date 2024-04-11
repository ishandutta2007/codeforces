#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

#define mod 1000000007
#define sz(a) signed(a.size())

struct node {
    int mn = mod, mn2 = mod;
    node() {}
    node(int x) { mn = x; }
    void apply(int x) {
        if (x < mn) mn2 = mn, mn = x;
        else mn2 = min(mn2, x);
    }
    int get() {
        if (mn2 == mod) return 2 * mod;
        return mn + mn2;
    }
};
 
node merge(node a, node b) {
    a.apply(b.mn);
    a.apply(b.mn2);
    return a;
}
 
struct Tree {
    static const int n = 1 << 18;
    node t[2 * n + 5];
    void upd(int r, int x) {
        r += n;
        t[r] = node(x);
        for (r >>= 1; r > 0; r >>= 1)
            t[r] = merge(t[r + r], t[r + r + 1]);
    }
    node get(int l, int r) {
        l += n;
        r += n + 1;
        node ans;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = merge(ans, t[l++]);
            if (r & 1) ans = merge(t[--r], ans);
        }
        return ans;
    }
} t[9];
 
string conv(int x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    while (sz(s) < 9) s += '0';
    return s;
} 
 
void upd(int r, int x) {
    string s = conv(x);
    for (int i = 0; i < sz(s); ++i)
        t[i].upd(r, s[i] == '0' ? mod : x);
}

#define LL long long
 
LL read( ){LL sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) return -sum;return sum;}
void read(int &sum){sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) sum=-sum;}
void read(LL &sum){sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) sum=-sum;}

 
signed main() {
    int n, m;
    read(n);
    read(m);
    for (int i = 0; i < n; ++i) {
        int a;
        read(a);
        upd(i, a);
    }
    for (int i = 0; i < m; ++i) {
        int mode;
        read(mode);
        if (mode == 1) {
            int r, x;
            read(r);
            read(x);
            upd(r - 1, x);
        }
        if (mode == 2) {
            int l, r;
            read(l);
            read(r);
            --l, --r;
            int ans = 2 * mod;
            for (int i = 0; i < 9; ++i)
                ans = min(ans, t[i].get(l, r).get());
            if (ans == 2 * mod) printf("-1\n");
            else printf("%d\n", ans);
        }
    }
    return 0;
}