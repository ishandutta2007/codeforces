#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    scanf("%d\n",&n);
    int end[500000];
    int arr[500000];
    scanf("%d ",&arr[0]);
    end[0]=1;
    for(int i=1;i<n;i++) {
        scanf("%d ",&arr[i]);
        if (arr[i-1]<arr[i]) {
            end[i]=end[i-1]+1;
        }
        else {
            end[i]=1;
        }
    }
    int st[500000];
    st[n-1]=1;
    for(int i=n-2;i>=0;i--) {
        if (arr[i]<arr[i+1]) {
            st[i]=st[i+1]+1;
        }
        else {
            st[i]=1;
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++) {
        maxi=max(maxi,end[i]);
    }
    for(int i=0;i<n-2;i++) {
        if (arr[i]<arr[i+2]) {
            maxi=max(maxi,end[i]+st[i+2]);
        }
    }
    printf("%d",maxi);
    return 0;
}