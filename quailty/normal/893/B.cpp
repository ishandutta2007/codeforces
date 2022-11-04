#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int res=1;
    for(int i=1;i<=n;i++)if(n%i==0)
    {
        bool isok=0;
        for(int j=0;j<12;j++)
            isok|=(i==((1<<j)-1)*(1<<(j-1)));
        if(isok)res=i;
    }
    printf("%d\n",res);
    return 0;
}