#include <bits/stdc++.h>
using namespace std;

char str[300001];
bool alive[300000];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%s\n",str);
        int n=strlen(str);
        int a=0;
        int b=0;
        int pa=0;
        int pb=0;
        for(int i=0;i<n;i++) {
            if (str[i]=='B') {
                pb++;
            }
            else {
                pa++;
            }
        }
        int ret=0;
        int val=0;
        for(int i=n-1;i>=0;i--) {
            if (str[i]=='B') {
                val++;
            }
            if (str[i]=='A') {
                if (val>0) {
                    val--;
                }
                else {
                    ret++;
                }
            }
        }
        ret+=(pb-pa+ret)%2;
        printf("%d\n",ret);
    }
}