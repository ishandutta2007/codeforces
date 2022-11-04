#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
char str[MAXN];
int main()
{
    int n;
    scanf("%d%s",&n,str+1);
    for(int i=1;i<=n;i++)
        if(n%i==0)reverse(str+1,str+i+1);
    printf("%s\n",str+1);
    return 0;
}