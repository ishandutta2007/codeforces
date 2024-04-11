#include <bits/stdc++.h>
using namespace std;

char str[11];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int te=0;te<tc;te++) {
        scanf("%s",str);
        int ret=10;
        for(int bit=0;bit<1024;bit++) {
            bool flag=true;
            for(int i=0;i<10;i++) {
                if (str[i]=='0') {
                    if (bit&(1<<i)) {
                        flag=false;
                    }
                }
                if (str[i]=='1') {
                    if ((bit&(1<<i))==0) {
                        flag=false;
                    }
                }
            }
            if (!flag) {
                continue;
            }
            int z=0;
            int o=0;
            int cnt=0;
            for(int i=0;i<10;i++) {
                cnt++;
                if (i%2==0) {
                    if (bit&(1<<i)) {
                        z++;
                    }
                    if (z>o+5-i/2) {
                        break;
                    }
                    if (o>z+4-i/2) {
                        break;
                    }
                }
                else {
                    if (bit&(1<<i)) {
                        o++;
                    }
                    if (z>o+4-i/2) {
                        break;
                    }
                    if (o>z+4-i/2) {
                        break;
                    }
                }
            }
            ret=min(ret,cnt);
        }
        printf("%d\n",ret);
    }
    return 0;
}