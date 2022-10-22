#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int deg[100000];

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        long long ret=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
            ret+=arr[i];
            deg[i]=0;
        }
        for(int i=1;i<n;i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            u--;
            v--;
            deg[u]++;
            deg[v]++;
        }
        vector<int> v;
        for(int i=0;i<n;i++) {
            for(int j=1;j<deg[i];j++) {
                v.push_back(arr[i]);
            }
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i=1;i<n;i++) {
            printf("%lld ",ret);
            if (i!=n-1) {
                ret+=v[i-1];
            }
        }
        printf("\n");
    }
}