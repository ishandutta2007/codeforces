#include<bits/stdc++.h>
using namespace std;
char str[105];
int main()
{
    scanf("%s",str);
    int n=strlen(str),res=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                res+=(str[i]=='Q' && str[j]=='A' && str[k]=='Q');
    return 0*printf("%d\n",res);
}