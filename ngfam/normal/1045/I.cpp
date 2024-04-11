#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100005;

char s[1000005];
int cnt[100];
int a[N];

int main() {
    int n;
    scanf("%d", &n);
    map<int,int> dem;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < 26; j++) cnt[j] = 0;
        for (int j = 0; s[j]; j++)
            cnt[s[j]-'a'] ^= 1;
        int num = 0;
        for (int j = 0; j < 26; j++)
            num = (num << 1) | (cnt[j]);
        dem[num]++;
        a[i] = num;
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        --dem[a[i]];
        res += dem[a[i]];
        for (int j = 0; j < 26; j++)
            res += dem[a[i]^(1<<j)];
    }
    printf("%lld\n", res);
}