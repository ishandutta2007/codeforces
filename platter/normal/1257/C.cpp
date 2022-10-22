#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int c;
    scanf("%d\n", &c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n", &n);
        int arr[200001];
        int check[200001];
        for(int i=0;i<n;i++) {
            scanf("%d ", &arr[i]);
            check[arr[i]]=-1;
        }
        int mini=1000000000;
        for(int i=0;i<n;i++) {
            if (check[arr[i]]==-1) {
                check[arr[i]]=i;
            }
            else {
                mini=min(mini,i-check[arr[i]]+1);
                check[arr[i]]=i;
            }
        }
        if (mini==1000000000) {
            printf("-1\n");
        }
        else {
            printf("%d\n", mini);
        }
    }
    return 0;
}