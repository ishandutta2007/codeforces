#include <bits/stdc++.h>

using namespace std;
long long mod=1000000007;
long long bs[1004]={0};

int main()
{
    int t=1;
    for (int z=0;z<t;z++){
        long long n, x, pos;
        long long ans=1;
        scanf("%lld %lld %lld", &n, &x, &pos);
        for (long long i=0;i<n;i++) bs[i] += (i);
        long long left=0, right=n;
        long long small=0, big=0;
        while (left<right){
            //printf("%lld %lld\n", left, right);
            long long middle = (left+right)/2;
            if (bs[middle]<=pos) {
                left = middle+1;
                small += 1;
            }
            else {
                right=middle;
                big += 1;
            }
        }
        small -= 1;
        for (long long i=0;i<big;i++) ans= (ans*(n-x-i))%mod;
        for (long long i=0;i<small;i++) ans= (ans*(x-1-i))%mod;
        for (long long i=n-big-small-1;i>=1;i--) ans = (ans*i)%mod;
        printf("%lld", ans);
    }
    return 0;
}