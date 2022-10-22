#include <bits/stdc++.h>
using namespace std;

int zero[300000];
vector<int> v[300000];

int main(void) {
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<300000;i++) {
        zero[i]=n;
    }
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);
        for(int j=2;j*j<=x;j++) {
            int cnt=0;
            while (x%j==0) {
                x/=j;
                cnt++;
            }
            if (cnt!=0) {
                zero[j]--;
                v[j].push_back(cnt);
            }
        }
        if (x!=1) {
            zero[x]--;
            v[x].push_back(1);
        }
    }
    long long ret=1;
    for(int i=2;i<=200000;i++) {
        if (zero[i]<2) {
            sort(v[i].begin(),v[i].end());
            for(int j=0;j<v[i][1-zero[i]];j++) {
                ret*=i;
            }
        }
    }
    printf("%lld",ret);
}