#include<bits/stdc++.h>
using namespace std;
char s[105];
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    for(int i=1;i*(i+1)/2<=n;i++)
        printf("%c",s[i*(i+1)/2]);
    return 0;
}