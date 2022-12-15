#if (__APPLE__)
#include "/Users/zhaofuqing/c++_head/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;
#define M 600010
#define LL long long
#define rep(i, x, y) for(LL i = (x); i <= (y); i ++)
namespace fastIO_0 {
    template <typename T> inline void read(T &d) {
        static char c;
        static bool flag;
        c = d = 0; flag = 0; while (c < '0' || c > '9')
            {if (c == '-') {flag = 1; c = getchar(); break;} c = getchar();}
        while (c >= '0' && c <= '9') d = (T)(d * 10 + c - '0'), c = getchar();
        if (flag) d = -d;
    }
    template <typename T> inline void print(const T &x) {
        if (typeid(x) == typeid(int)) return printf("%d", x), void();
        if (typeid(x) == typeid(bool)) return printf("%d", x), void();
        if (typeid(x) == typeid(char)) return printf("%c", x), void();
        if (typeid(x) == typeid(long long)) return printf("%I64d", x), void();
    }
    void flush() {}
}
namespace fastIO_1 {
    inline char read() {
        const int IN_LEN = 1000000;
        static char buf[IN_LEN], *s, *t;
        if (s == t) {
            t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
            if (s == t) return -1;
        }
        return *s++;
    }
    template <class T> inline void read(T &x) {
        bool iosig;
        char c;
        for (iosig = false, c = read(); !isdigit(c); c = read()) {
            if (c == '-') iosig = true; if (c == -1) return;
        }
        for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
        if (iosig) x = -x;
    }
    template <class T> inline T read() {static T c; read(c); return c;}
    const int OUT_LEN = 10000000;
    char obuf[OUT_LEN], *ooh = obuf;
    inline void print(char c) {
        if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
        *ooh++ = c;
    }
    template <class T> inline void print(T x) {
        static int buf[30], cnt;
        if (x == 0) print('0');
        else {
            if (x < 0) print('-'), x = -x;
            for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
            while (cnt) print((char)buf[cnt--]);
        }
    }
    inline void flush() {fwrite(obuf, 1, ooh - obuf, stdout);}
    inline void put(const char *s) {for (; *s; s++) print(*s); print('\n');}
}
using namespace fastIO_1;
struct Edge{
    int u, v, id, nxt;
} g[M]; int first[M], __cnt = -1;
vector<int> T[M];
bool vis[M], ok[M], res[M];
inline void add(int u, int v, int w) {
    g[++__cnt] = (Edge){u, v, w, first[u]}; first[u] = __cnt;
} queue<int> qu;
int main(){
#if (ONLINE_JUDGE)
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, s; read(n); read(m); read(s);
    memset(first, -1, sizeof(first));
    for (int i = 1; i <= m; ++i) {
        int t, u, v; read(t); read(u); read(v);
        if(t == 1) T[u].push_back(v);
        else add(u, v, i), add(v, u, i);
    }
    while(!qu.empty()) qu.pop();
    memset(vis, 0, sizeof(vis));
    memset(ok, 0, sizeof(ok));
    qu.push(s); vis[s] = 1; while(!qu.empty()) {
        int x = qu.front(); qu.pop();
        for(int i = 0; i < T[x].size(); i ++) {
            if(!vis[T[x][i]]) vis[T[x][i]] = 1, qu.push(T[x][i]);
        } for(int i = first[x]; i != -1; i = g[i].nxt) {
            if(!ok[i / 2 + 1]) {
                ok[i / 2 + 1] = 1;
                if(i & 1) res[i / 2 + 1] = 1;
                else res[i / 2 + 1] = 0;
                if(!vis[g[i].v]) vis[g[i].v] = 1, qu.push(g[i].v);
                continue;
            }
        }
    } int cnt = 0;
    for (int i = 1; i <= n; ++i) if (vis[i]) cnt++;
    printf("%d\n", cnt);
    for (int i = 1; i <= __cnt / 2 + 1; ++i) printf(res[i] ? "-" : "+"); puts("");
    while(!qu.empty()) qu.pop();
    memset(vis, 0, sizeof(vis));
    memset(ok, 0, sizeof(ok));
    qu.push(s); vis[s] = 1; while(!qu.empty()) {
        int x = qu.front(); qu.pop();
        for(int i = 0; i < T[x].size(); i ++) {
            if(!vis[T[x][i]]) vis[T[x][i]] = 1, qu.push(T[x][i]);
        } for(int i = first[x]; i != -1; i = g[i].nxt) {
            if(ok[i / 2 + 1]) {
                if(!vis[g[i].v]) vis[g[i].v] = 1, qu.push(g[i].v);
                continue;
            } ok[i / 2 + 1] = 1;
            if(i & 1) res[i / 2 + 1] = 0;
            else res[i / 2 + 1] = 1;
        }
    } cnt = 0;
    for (int i = 1; i <= n; ++i) if (vis[i]) cnt++;
    printf("%d\n", cnt);
    for (int i = 1; i <= __cnt / 2 + 1; ++i) printf(res[i] ? "-" : "+");
    return 0;
}