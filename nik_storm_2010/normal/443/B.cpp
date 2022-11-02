#include <cstdio>
#include <cstring>

using namespace std;
const int N = 500;

int main()
{
    char s[N];
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    int n = strlen(s);
    for (int i = 0; i < k; i++) s[n + i] = '?';
    n += k;
    for (int ans = n; ans >= 0; ans--)
    {
        bool ok = false;
        for (int i = 0; i < n; i++)
        {
            int lim = i + 2 * ans;
            if (lim > n) break;
            bool eq = true;
            for (int j = i; j + ans < lim; j++)
            {
                if (s[j] == '?' || s[j + ans] == '?') continue;
                if (s[j] != s[j + ans]) eq = false;
            }
            if (eq) ok = true;
        }
        if (ok)
        {
            printf("%d\n", 2 * ans);
            return 0;
        }
    }
    return 0;
}