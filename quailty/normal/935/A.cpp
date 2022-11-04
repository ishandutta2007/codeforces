#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,res=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        res+=(n%i==0);
    return 0*printf("%d\n",res);
}