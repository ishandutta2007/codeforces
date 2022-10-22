#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n",&n);
        char str[101];
        scanf("%s\n",str);
        bool flag=false;
        int row=0;
        int ret=0;
        for(int i=0;i<n;i++) {
            if (str[i]=='A') {
                if (flag) {
                    ret=max(row,ret);
                }
                row=0;
                flag=true;
            }
            else {
                row+=1;
            }
        }
        if (flag) {
            ret=max(row,ret);
        }
        printf("%d\n",ret);
    }
    return 0;
}