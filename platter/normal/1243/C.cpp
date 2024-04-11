#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    long long n;
    scanf("%lld",&n);
    int flag=0;
    long long mini=n;
    for(long long i=2;i*i<=n;i++) {
        if (n%i==0) {
            flag+=1;
            mini=min(mini,i);
        }
        while (n%i==0) {
            n/=i;
        }
        if (flag==2) {
            printf("1");
            return 0;
        }
    }
    if (n!=1) {
        if (flag==1) {
            printf("1");
            return 0;
        }
        mini=min(mini,n);
    }
    printf("%lld",mini);
    return 0;
}