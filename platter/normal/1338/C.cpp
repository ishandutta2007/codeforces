#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        long long n;
        scanf("%lld",&n);
        long long ret=0;
        if (n%3==1) {
            n=n/3+1;
            long long val=1;
            int cnt=0;
            while (val<n) {
                val=val*4+1;
                cnt+=2;
            }
            ret+=(1LL<<cnt);
            n-=val/4;
            n--;
            for(int i=cnt-2;i>=0;i-=2) {
                long long val=(n>>i)%4;
                if (val==0) {
                    ret+=(0LL<<i);
                }
                if (val==1) {
                    ret+=(1LL<<i);
                }
                if (val==2) {
                    ret+=(2LL<<i);
                }
                if (val==3) {
                    ret+=(3LL<<i);
                }
            }
        }
        else if (n%3==2) {
            n=n/3+1;
            long long val=1;
            int cnt=0;
            while (val<n) {
                val=val*4+1;
                cnt+=2;
            }
            ret+=2LL*(1LL<<cnt);
            n-=val/4;
            n--;
            for(int i=cnt-2;i>=0;i-=2) {
                long long val=(n>>i)%4;
                if (val==0) {
                    ret+=(0LL<<i);
                }
                if (val==1) {
                    ret+=(2LL<<i);
                }
                if (val==2) {
                    ret+=(3LL<<i);
                }
                if (val==3) {
                    ret+=(1LL<<i);
                }
            }
        }
        else if (n%3==0) {
            n=n/3;
            long long val=1;
            int cnt=0;
            while (val<n) {
                val=val*4+1;
                cnt+=2;
            }
            ret+=3LL*(1LL<<cnt);
            n-=val/4;
            n--;
            for(int i=cnt-2;i>=0;i-=2) {
                long long val=(n>>i)%4;
                if (val==0) {
                    ret+=(0LL<<i);
                }
                if (val==1) {
                    ret+=(3LL<<i);
                }
                if (val==2) {
                    ret+=(1LL<<i);
                }
                if (val==3) {
                    ret+=(2LL<<i);
                }
            }
        }
        printf("%lld\n",ret);
    }
}