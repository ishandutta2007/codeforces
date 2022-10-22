#include <cstdio>
#include <cstring>

int main(void) {
    char str[102];
    scanf("%s",str);
    int n=strlen(str);
    int one=0;
    for(int i=0;i<n;i++) {
        if (str[i]=='1') {
            one+=1;
        }
    }
    int ret=(n+1)/2;
    if (n%2==1&&one==1)
    ret--;
    if (one==0)
    ret=0;
    printf("%d",ret);
    return 0;
}