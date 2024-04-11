
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;
 
template <typename T>
inline T sqr(T n) {
    return n * n;
}
 
int cnt[26];
vector <int> pos[MAXN];
char s[MAXN];
int n;
long long sum[MAXN], ans;
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
 
    for (int i = 0; i < 26; i++) {
        scanf("%d", &cnt[i]);
    }
 
    getchar();
    gets(s + 1);
    n = strlen(s + 1);
 
    for (int i = 1; i <= n; i++) {
        sum[i] = cnt[s[i] - 'a'];
        sum[i] += sum[i - 1];
 
        pos[s[i] - 'a'].push_back(i);
    }
 
    for (int cc = 0; cc < 26; cc++) {
        map <long long, int> Map;
 
        for (size_t i = 0; i < pos[cc].size(); i++) {
            int p = pos[cc][i];
            ans += Map[sum[p - 1]];
            Map[sum[p]]++;
        }
 
        Map.clear();
    }
 
    printf("%I64d\n", ans);
}