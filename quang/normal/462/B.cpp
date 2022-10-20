#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int n, k;
int sl[26];
string s;

int main() {
    //fi, fo;
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++) sl[s[i] - 'A']++;
    sort(sl, sl + 26, greater<int>());
    long long res = 0;
    int d = 0;
    while(k > 0) {
        int x = sl[d++];
        if(x >= k)
            res += 1ll * k * k, k = 0;
        else
            res += 1ll * x * x, k -= x;
    }
    cout << res;
    return 0;
}