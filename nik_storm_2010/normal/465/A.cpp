#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    char s[1000];
    scanf("%s", s);
    int ans = n;
    for (int i = 0; i < n; i++) if (s[i] == '0')
    {
        ans = i + 1;
        break;
    }
    printf("%d\n", ans);
    return 0;
}