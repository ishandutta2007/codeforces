#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
char s[MAXN];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    bool isok=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]>'a')
        {
            isok=1;
            s[i]--;
        }
        else if(isok)
            break;
    }
    if(!isok)s[n-1]='z';
    printf("%s",s);
    return 0;
}