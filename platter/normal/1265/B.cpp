#include <cstdio>
#include <algorithm>
using namespace std;
 
int main(void) {
    int c;
    scanf("%d\n",&c);
    int arr[200001];
    int pos[200001];
    int  check[200001];
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++) {
            scanf("%d ",&arr[i]);
            pos[arr[i]]=i;
        }
        scanf("\n");
        for(int i=1;i<=n;i++) {
            check[i]=0;
        }
        int l=pos[1];
        int r=pos[1];
        check[1]=1;
        int maxi=1;
        for(int i=2;i<=n;i++) {
            int goal=pos[i];
            while (goal<l) {
                l-=1;
                maxi=max(arr[l],maxi);
            }
            while (goal>r) {
                r+=1;
                maxi=max(arr[r],maxi);
            }
            if (i==maxi) {
                check[i]=1;
            }
        }
        for(int i=1;i<=n;i++) {
            printf("%d",check[i]);
        }
        printf("\n");
    }
    return 0;
}