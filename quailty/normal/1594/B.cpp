#include<bits/stdc++.h>
using namespace std;
const int Mod=1000000007;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k,res=0,t=1;
        scanf("%d%d",&n,&k);
        while(k)
        {
            if(k&1)res=(res+t)%Mod;
            t=1LL*t*n%Mod;
            k>>=1;
        }
        printf("%d\n",res);
    }
    return 0;
}