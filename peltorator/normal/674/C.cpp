#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>
 
#define sz(a) (int)((a).size())
 
using namespace std;
 
mt19937 rnd(239);
 
typedef long long ll;
typedef double ld;

/** Interface */
 
inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
 
/** Read */
 
static const int buf_size = 4096;
 
inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}
 
inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
    return c;
}
 
template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}
 
/** Write */
 
static int write_pos = 0;
static char write_buf[buf_size];
 
inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}
 
template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;
 
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}
 
inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}
 
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
 
 
const ld INF = 1e18;
 
vector<ll> t, pref;
vector<vector<ld> > dp;
vector<ld> rev, pref2;
 
ld find(int l, int r)
{
    return pref2[r] - pref2[l] - (ld)pref[l] * (rev[r] - rev[l]);
}
 
void divide(int k, int l, int r, int ml, int mr)
{
    int mid = (r + l) / 2;
    ld best = INF;
    int m = -1;
    for (int i = ml; i < min(mid, mr); i++)
    {
        ld cur = dp[k - 1][i] + find(i, mid);
        if (cur < best)
        {
            best = cur;
            m = i;
        }
    }
    dp[k][mid] = best;
    if (l + 1 == r)
        return;
    divide(k, l, mid, ml, min(m + 1, mr));
    divide(k, mid, r, max(m, ml), mr);
}
 
int solve()
{
    ios::sync_with_stdio(0);
    int n = readInt();
    int k = readInt();
   // cin >> k;
    t.assign(n, 0);
    for (int i = 0; i < n; i++)
        t[i] = readInt();
    rev.assign(n + 1, 0);
    pref.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + t[i];
    for (int i = 0; i < n; i++)
        rev[i + 1] = rev[i] + (ld)1 / (ld)t[i];
    pref2.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref2[i + 1] = pref2[i] + (ld)pref[i + 1] / (ld)t[i];
    dp.assign(k + 1, vector<ld>(n + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
        divide(i, 0, n + 1, 0, n + 1);
    cout.precision(30);
    cout << dp[k][n] << endl;
    return 1;
}
 
int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cerr << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}