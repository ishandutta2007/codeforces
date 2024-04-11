#include <bits/stdc++.h>
using namespace std;

int n;
long long w;
long long arr[200000];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d %lld",&n,&w);
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
        }
        bool flag=false;
        vector<int> v;
        long long sum=0;
        for(int i=0;i<n;i++) {
            if (arr[i]>w) {
                continue;
            }
            if (arr[i]>=(w+1)/2) {
                printf("1\n%d\n",i+1);
                flag=true;
                break;
            }
            sum+=arr[i];
            v.push_back(i);
            if (sum>=(w+1)/2) {
                printf("%d\n",v.size());
                for(int j=0;j<v.size();j++) {
                    printf("%d ",v[j]+1);
                }
                printf("\n");
                flag=true;
                break;
            }
        }
        if (!flag) {
            printf("-1\n");
        }
    }
}