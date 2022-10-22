#include <cstdio>
#include <cstring>

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n", &n);
        char str[51];
        int length[50];
        int zero=0;
        int one=0;
        for(int i=0;i<n;i++) {
            gets(str);
            length[i]=strlen(str);
            for(int j=0;j<length[i];j++) {
                if (str[j]=='0')
                zero+=1;
                if (str[j]=='1')
                one+=1;
            }
        }
        int len1=0;
        int len2=0;
        for(int i=0;i<n;i++) {
            if (length[i]%2==0) {
                len2+=1;
            }
            if (length[i]%2==1) {
                len1+=1;
            }
        }
        if (zero%2==0) {
            printf("%d\n",n);
        }
        else {
            if (len1==0) {
                printf("%d\n", n-1);
            }
            else {
                printf("%d\n", n);
            }
        }
    }
    return 0;
}