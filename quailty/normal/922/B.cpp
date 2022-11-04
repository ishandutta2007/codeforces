#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,res=0;
    scanf("%d",&n);
    for(int a=1;a<=n;a++)
        for(int b=a;b<=n;b++)
        {
            int c=a^b;
            res+=(c>=b && c<=n && c<a+b);
        }
    return 0*printf("%d\n",res);
}