#include <cstdio>
#include <cstring>

using namespace std;
const int N = 200000;

bool bad(char c)
{
    return (c == 'A' || c == 'H' || c == 'I' || c == 'M' || c == 'O' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y') ? false : true;
}

int main()
{
    char s[N];
    scanf("%s", &s);
    int l = 0, r = strlen(s) - 1;
    while (l <= r)
    {
        if (s[l] != s[r] || bad(s[l]) || bad(s[r]))
        {
            puts("NO");
            return 0;
        }
        l++, r--;
    }
    puts("YES");
    return 0;
}