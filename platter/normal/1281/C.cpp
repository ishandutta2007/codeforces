#include <cstdio>
#include <cstring>
 
int s[10000055];
int mod=1000000007;
 
int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int x;
        char str[501];
        scanf("%d\n",&x);
        gets(str);
        int n=strlen(str);
        int nc=n;
        for(int i=0;i<n;i++) {
            s[i]=str[i]-'0';
        }
        int ind=0;
        while (n<=x+10000) {
            int num=s[ind];
            for(int i=0;i<num-1;i++) {
                for(int j=ind+1;j<n;j++) {
                    s[n+i*(n-ind-1)+j-ind-1]=s[j];
                }
            }
            n+=(n-ind-1)*(num-1);
            ind+=1;
        }
        long long val=nc;
        for(int i=1;i<=x;i++) {
            val+=(val-i)*(s[i-1]-1);
            val%=mod;
            while (val<0) {
                val+=mod;
            }
        }
        printf("%lld\n",val);
    }
    return 0;
}