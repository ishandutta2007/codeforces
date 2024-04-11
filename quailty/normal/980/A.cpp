#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
char str[MAXN];
int main()
{
    scanf("%s",str);
    int n=strlen(str),k=0;
    for(int i=0;i<n;i++)
        k+=(str[i]=='o');
    if(k==0 || n%k==0)printf("YES\n");
    else printf("NO\n");
    return 0;
}