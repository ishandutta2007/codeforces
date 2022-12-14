#include<cstdio>
#include<cstring>

char s[10005];
int n, boo, boo1, boo2, boo3;

int main()
{    
    gets(s);
    n = strlen(s);
    boo = 1;
    if (n < 5)
        boo = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            boo1 = 1;
        if (s[i] >= 'A' && s[i] <= 'Z')
            boo2 = 1;
        if (s[i] >= '0' && s[i] <= '9')
            boo3 = 1;
    }
    if (boo1+boo2+boo3!=3)
        boo = 0;
    if (boo)
        puts("Correct");
    else
        puts("Too weak");
}