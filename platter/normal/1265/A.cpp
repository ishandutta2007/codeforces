#include <cstdio>
#include <cstring>

int main(void) {
    int c;
    scanf("%d\n",&c);
    char str[100001];
    int arr[100001];
    for(int t=0;t<c;t++) {
        gets(str);
        int n=strlen(str);
        for(int i=0;i<n;i++) {
            if (str[i]=='?') {
                arr[i]=0;
            }
            if (str[i]=='a') {
                arr[i]=1;
            }
            if (str[i]=='b') {
                arr[i]=2;
            }
            if (str[i]=='c') {
                arr[i]=3;
            }
        }
        if (arr[0]==0) {
            if (arr[1]==1) {
                arr[0]=2;
            }
            else {
                arr[0]=1;
            }
        }
        bool check[4];
        bool flag=true;
        for(int i=1;i<n-1;i++) {
            check[1]=false;
            check[2]=false;
            check[3]=false;
            check[arr[i-1]]=true;
            check[arr[i+1]]=true;
            if (arr[i]==0) {
                for(int j=1;j<=3;j++) {
                    if (!check[j]) {
                        arr[i]=j;
                        break;
                    }
                }
            }
            if (arr[i]==arr[i-1]||arr[i]==arr[i+1]) {
                printf("-1\n");
                flag=false;
                break;
            }
        }
        if (arr[n-1]==0) {
            if (arr[n-2]==1) {
                arr[n-1]=2;
            }
            else {
                arr[n-1]=1;
            }
        }
        if (flag) {
            for(int i=0;i<n;i++) {
                if (arr[i]==1) {
                    printf("a");
                }
                if (arr[i]==2) {
                    printf("b");
                }
                if (arr[i]==3) {
                    printf("c");
                }
            }
            printf("\n");
        }
    }
    return 0;
}