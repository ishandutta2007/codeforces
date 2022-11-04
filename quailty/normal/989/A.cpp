#include<bits/stdc++.h>
using namespace std;
char str[105];
int main()
{
    scanf("%s",str+1);
    int n=strlen(str+1);
    for(int i=1;i<=n;i++)
    {
        int vis=0;
        for(int j=0;j<3;j++)
            if(str[i-1]=='A'+j
            || str[i]=='A'+j
            || str[i+1]=='A'+j)
                vis|=(1<<j);
        if(vis==7)return 0*printf("Yes\n");
    }
    return 0*printf("No\n");
}