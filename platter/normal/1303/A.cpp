#include <cstdio>
#include <cstring>
 
char str[101];
 
int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        scanf("%s\n",str);
        int n=strlen(str);
        bool flag=false;
        int ret=0;
        int cnt=0;
        for(int i=0;i<n;i++) {
            if (str[i]=='1') {
                flag=true;
                ret+=cnt;
                cnt=0;
            }
            if (flag&&str[i]=='0') {
                cnt++;
            }
        }
        printf("%d\n",ret);
    }
}