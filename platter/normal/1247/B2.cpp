#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int n,k,d;
        scanf("%d %d %d\n", &n, &k, &d);
        int check[1000001];
        for(int i=1;i<=k;i++) {
            check[i]=0;
        }
        int arr[200000];
        for(int i=0;i<n;i++) {
            scanf("%d ", &arr[i]);
        }
        scanf("\n");
        int count=0;
        int mini=1000000000;
        for(int i=0;i<d;i++) {
            if (check[arr[i]]==0) {
                check[arr[i]]=1;
                count+=1;
            }
            else {
                check[arr[i]]+=1;
            }
        }
        mini=min(mini,count);
        for(int i=d;i<n;i++) {
            if (check[arr[i-d]]==1) {
                count-=1;
            }
            check[arr[i-d]]-=1;
            if (check[arr[i]]==0) {
                count+=1;
            }
            check[arr[i]]+=1;
            mini=min(mini,count);
        }
        printf("%d\n", mini);
    }
    return 0;
}