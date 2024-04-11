#include <cstdio>

using namespace std;
const int N = 2e3;

int n, p;
char s[N];

bool check(int x)
{
    for (int i = x; i < n; i++)
    {
        bool ok = false;
        for (int j = 'a'; j < p; j++)
        {
            s[i] = j;
            if (i > 0 && s[i] == s[i - 1]) continue;
            if (i > 1 && s[i] == s[i - 2]) continue;
            ok = true;
            break;
        }
        if (!ok) return false;
    }
    printf("%s\n", s);
    return true;
}

int main()
{
    scanf("%d %d", &n, &p);
    p += 'a';
    scanf("%s", s);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = s[i] + 1; j < p; j++)
        {
            s[i] = j;
            if (i > 0 && s[i] == s[i - 1]) continue;
            if (i > 1 && s[i] == s[i - 2]) continue;
            bool ok = check(i + 1);
            if (ok) return 0;
        }
    }
    puts("NO");
    return 0;
}