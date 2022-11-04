#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
char s[MAXN];
int main()
{
    scanf("%s",s);
    int n=strlen(s),l=0,r=n-1;
    while(l<n && s[l]!='[')l++;
    while(l<n && s[l]!=':')l++;
    while(r>=0 && s[r]!=']')r--;
    while(r>=0 && s[r]!=':')r--;
    if(l>=r)printf("-1\n");
    else
    {
        int res=4;
        for(int i=l+1;i<r;i++)
            res+=(s[i]=='|');
        printf("%d\n",res);
    }
    return 0;
}