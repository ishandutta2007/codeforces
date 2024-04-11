#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
int main()
{
    scanf("%s",s+1);
    s[0]='a';
    int res=0;
    for(int i=1;s[i];i++)
    {
        int d=abs(s[i]-s[i-1]);
        res+=min(d,26-d);
    }
    printf("%d\n",res);
    return 0;
}