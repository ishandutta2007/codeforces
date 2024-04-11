#include <bits/stdc++.h>
using namespace std;

int arr[50];

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d\n",&n,&k);
        vector<int> v;
        for(int i=1;i*i<=n;i++) {
            if (n%i==0) {
                v.push_back(i);
                if (i*i!=n) {
                    v.push_back(n/i);
                }
            }
        }
        int ret=0;
        for(int i=0;i<v.size();i++) {
            if (v[i]<=k) {
                ret=max(ret,v[i]);
            }
        }
        printf("%d\n",n/ret);
    }
}