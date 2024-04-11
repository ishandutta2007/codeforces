#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
char s[maxn],t[maxn];
int main()
{
    scanf("%s%s",s,t);
    int l=strlen(s),a=l-1;
    while(s[a]=='z')
    {
        s[a]='a';
        a--;
    }
    s[a]++;
    if(strcmp(s,t)==0)
        puts("No such string");
    else
        printf("%s\n",s);
    return 0;
}