#include <bits/stdc++.h>

using namespace std;
const int N=10005;
const long long mod=998244353;
int main()
{
    int n;
    scanf("%i",&n);
    int cene[n];
    long long poweri[n];
    poweri[0]=1;
    for(int i=0;i<n;i++)
    {
        scanf("%i",&cene[i]);
    }
    for(int i=1;i<n;i++)
    {
        poweri[i]=(poweri[i-1]*(long long)2)%mod;
    }
    int tr=n;
    long long finale=0;
    for(int i=0;i<n;i++)
    {
        //printf("%i:  dsada\n",i+1);
        long long tren;
        if(tr>=2)
        {
            tren=poweri[tr-2];
        }
        else
        {
            tren=1;
        }
        //printf("%I64d\n",tren);
        if(tr>1)
        tren=(tren*(long long)(tr+1))%mod;
        //printf("%I64d\n",tren);
        finale=(finale+tren*(long long)cene[i])%mod;
        tr--;
    }
    printf("%I64d\n",finale);
    return 0;
}