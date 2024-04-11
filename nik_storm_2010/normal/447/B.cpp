#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
const int N = 1e5;
const int ALPHA = 256;

char s[N];
int cost[ALPHA];

int main()
{
    scanf("%s", &s);
    int d = strlen(s);
    int k;
    scanf("%d", &k);
    for (char it = 'a'; it <= 'z'; it++) scanf("%d", &cost[it]);
    char add = 'a';
    for (int it = 'b'; it <= 'z'; it++) if (cost[it] > cost[add]) add = it;
    for (int i = d; i < d + k; i++) s[i] = add;
    ll ans = 0;
    for (int i = 0; i < d + k; i++) ans += (i + 1LL) * cost[s[i]];
    printf("%I64d\n", ans);
    return 0;
}