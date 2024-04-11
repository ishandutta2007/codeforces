#include <cstdio>
#include <cstring>
 
int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        char str[300001];
        gets(str);
        int n=strlen(str);
        int odd[300001];
        int even[300001];
        int oddn=0;
        int evenn=0;
        for(int i=0;i<n;i++) {
            if (str[i]%2==0) {
                even[evenn]=str[i]-'0';
                evenn+=1;
            }
            if (str[i]%2==1) {
                odd[oddn]=str[i]-'0';
                oddn+=1;
            }
        }
        int check[5];
        int index[6];
        int size=0;
        int prev=-1;
        for (int i=0;i<evenn;i++) {
            if (even[i]>prev) {
                check[size]=even[i];
                prev=even[i];
                index[size]=i;
                size+=1;
            }
        }
        index[size]=evenn;
        int arr[300000][6];
        for(int i=0;i<oddn;i++) {
            for(int j=0;j<6;j++) {
                arr[i][j]=0;
            }
        }
        int s[6];
        for (int i=0;i<6;i++) {
            s[i]=0;
        }
        int now=0;
        for(int i=0;i<oddn;i++) {
            int pass=0;
            for(int j=now;j<size;j++) {
                if (odd[i]<check[j]) {
                    arr[s[j]][j]=odd[i];
                    s[j]+=1;
                    pass=1;
                    now=j;
                    break;
                }
            }
            if (pass==0) {
                arr[s[size]][size]=odd[i];
                s[size]+=1;
                now=size;
            }
        }
        for(int i=0;i<size;i++) {
            for(int j=0;j<s[i];j++) {
                printf("%d",arr[j][i]);
            }
            for(int j=index[i];j<index[i+1];j++) {
                printf("%d",even[j]);
            }
        }
        for(int i=0;i<s[size];i++) {
            printf("%d",arr[i][size]);
        }
        printf("\n");
    }
    return 0;
}