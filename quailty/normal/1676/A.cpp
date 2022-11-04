#include<bits/stdc++.h>
using namespace std;
int solve()
{
    char s[7];
    scanf("%s",s);
    if(s[0]+s[1]+s[2]==s[3]+s[4]+s[5])printf("YES\n");
    else printf("NO\n");
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}