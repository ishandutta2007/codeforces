#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 1000010

using namespace std;

long long n, m, l1, l2, res, lcm, gcd, mul;
string s1, s2;
int sl[N][26];

int main() {
    //fi, fo;
    scanf("%I64d %I64d", &n, &m);
    cin >> s1 >> s2;
    l1 = s1.size(), l2 = s2.size();
    gcd = __gcd(l1, l2);
    lcm = l1 * l2 / gcd;
    mul = n * l1 / lcm;
    for(int i = 0; i < (int)s1.size(); i++) sl[i % gcd][s1[i] - 'a']++;
    for(int i = 0; i < (int)s2.size(); i++)
        res += 1ll * l1 / gcd - sl[i % gcd][s2[i] - 'a'];
    cout << res * mul;
    return 0;
}