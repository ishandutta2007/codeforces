#include <cstdio>
#include <cstring>

using namespace std;
const int N = 500;

int main()
{
    int n;
    scanf("%d", &n);
    char s[N];
    scanf("%s", &s);
    int k1 = 0, k2 = 0;
    for (int i = 0; i < strlen(s); i++) if (s[i] == 'x') k1++; else k2++;
    int balance = k1 - k2;
    if (balance < 0) printf("%d\n", (-balance) >> 1); else printf("%d\n", balance >> 1);
    for (int i = 0; i < strlen(s); i++)
    {
        if (balance == 0) break;
        if (balance < 0)
        {
            if (s[i] == 'X') balance += 2;
            s[i] = 'x';
        }
        else
        {
            if (s[i] == 'x') balance -= 2;
            s[i] = 'X';
        }
    }
    printf("%s\n", s);
    return 0;
}