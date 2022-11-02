#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2000;
const int ALPHA = 256;

int cnt[ALPHA];
bool used[ALPHA];

int main()
{
    char s1[N], s2[N];
    scanf("%s", s1);
    scanf("%s", s2);
    int d1 = strlen(s1), d2 = strlen(s2);
    for (int i = 0; i < d1; i++) cnt[s1[i]]++, used[s1[i]] = true;
    int ans = 0;
    for (int i = 0; i < d2; i++)
    {
        if (!used[s2[i]])
        {
            puts("-1");
            return 0;
        }
        if (cnt[s2[i]] != 0) ans++, cnt[s2[i]]--;
    }
    printf("%d\n", ans);
    return 0;
}