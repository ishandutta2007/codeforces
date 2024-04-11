#include <bits/stdc++.h>
using namespace std;

char str[6];
int pow10[5]={1,10,100,1000,10000};

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d\n",&n);
        vector<int> ret;
        for(int i=0;n!=0;i++) {
            if (n%10!=0) {
                ret.push_back(pow10[i]*(n%10));
            }
            n/=10;
        }
        printf("%d\n",ret.size());
        for(int i=0;i<ret.size();i++) {
            printf("%d ",ret[i]);
        }
        printf("\n");
    }
}