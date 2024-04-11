#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int a[5], b[5];
string s;

int main() {
   // fi, fo;
    scanf("%d%d%d%d", &a[1], &a[2] ,&a[3], &a[4]);
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++) b[s[i] - 48]++;
    long long res = 0;
    for(int i = 1; i <= 4; i++) res += 1ll * a[i] * b[i];
    cout <<res;
    return 0;
}