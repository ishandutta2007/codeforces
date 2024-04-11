#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1005];
int main()
{
    gets(s);
    int mask=0;
    for(int i=0;s[i];i++)
        if(s[i]>='a' && s[i]<='z')
            mask|=1<<(s[i]-'a');
    printf("%d",__builtin_popcount(mask));
    return 0;
}