#include <cstdio>
#include <cstring>

long long fib[100001];
long long div=1000000007;

void fibmake() {
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<=100000;i++) {
        fib[i]=(fib[i-1]+fib[i-2])%div;
    }
}

int main(void) {
    fibmake();
    char str[100001];
    gets(str);
    int n=strlen(str);
    int row=1;
    char prev=str[0];
    if (prev=='m'||prev=='w') {
        printf("0");
        return 0;
    }
    long long ret=1;
    for(int i=1;i<n;i++) {
        if (str[i]=='m'||str[i]=='w') {
            printf("0");
            return 0;
        }
        if (str[i]==prev) {
            row+=1;
        }
        else if (prev=='n'||prev=='u') {
            ret=(ret*fib[row])%div;
            prev=str[i];
            row=1;
        }
        else {
            row=1;
            prev=str[i];
        }
    }
    if (prev=='n'||prev=='u') {
        ret=(ret*fib[row])%div;
    }
    printf("%lld",ret);
    return 0;
}