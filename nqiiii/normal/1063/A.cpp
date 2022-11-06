#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
int cnt[26], id[26];
vector<int> v;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        char c = getchar();
        while (!isgraph(c)) c = getchar();
        ++cnt[c - 'a'];
    }
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < cnt[i]; ++j)
            printf("%c", i + 'a');
}