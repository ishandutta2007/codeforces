#include <bits/stdc++.h>
using namespace std;

int bit[20];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);
        for(int j=0;j<20;j++) {
            if (x&(1<<j)) {
                bit[j]++;
            }
        }
    }
    long long ret=0;
    for(int i=0;i<n;i++) {
        int val=0;
        for(int j=0;j<20;j++) {
            if (bit[j]>i) {
                val+=(1<<j);
            }
        }
        ret+=1LL*val*val;
    }
    printf("%lld",ret);
}