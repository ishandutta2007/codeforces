#include <bits/stdc++.h>
using namespace std;

int arr[1000000];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d\n",&n,&k);
        int ret=n;
        int sum=0;
        for(int i=0;i<n;i++) {
            scanf("%1d",&arr[i]);
        }
        for(int i=0;i<n;i++) {
            sum+=arr[i];
        }
        ret=sum;
        for(int i=0;i<k;i++) {
            vector<int> v;
            for(int j=i;j<n;j+=k) {
                if (arr[j]==1) {
                    v.push_back(-1);
                }
                else {
                    v.push_back(1);
                }
            }
            int val=0;
            for(int j=0;j<v.size();j++) {
                val=min(v[j],val+v[j]);
                ret=min(ret,sum+val);
            }
        }
        printf("%d\n",ret);
    }
}