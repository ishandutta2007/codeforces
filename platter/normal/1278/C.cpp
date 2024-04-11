#include <cstdio>
#include <algorithm>
using namespace std;

int arr[200000];
int lsum[100001];
int rsum[100001];
int ldis[200001];
int rdis[200001];

int main(void) {
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n",&n);
        int one=0;
        int two=0;
        for(int i=0;i<2*n;i++) {
            scanf("%d ",&arr[i]);
            if (arr[i]==1) {
                one+=1;
            }
            else {
                two+=1;
            }
        }
        lsum[0]=0;
        for(int i=n-1;i>=0;i--) {
            if (arr[i]==1) {
                lsum[n-i]=lsum[n-i-1]+1;
            }
            if (arr[i]==2) {
                lsum[n-i]=lsum[n-i-1]-1;
            }
        }
        rsum[0]=0;
        for(int i=n;i<2*n;i++) {
            if (arr[i]==1) {
                rsum[i-n+1]=rsum[i-n]+1;
            }
            if (arr[i]==2) {
                rsum[i-n+1]=rsum[i-n]-1;
            }
        }
        int diff=one-two;
        for(int i=0;i<=2*n;i++) {
            ldis[i]=-1;
            rdis[i]=-1;
        }
        for(int i=n;i>=0;i--) {
            ldis[lsum[i]+n]=n-i;
        }
        for(int i=n;i>=0;i--) {
            rdis[rsum[i]+n]=n+i-1;
        }
        int mini=1e9;
        for(int i=0;i<=2*n;i++) {
            if (ldis[i]!=-1) {
                if (2*n+diff-i>=0&&diff-i<=0) {
                    if (rdis[2*n+diff-i]!=-1) {
                        mini=min(mini,rdis[2*n+diff-i]-ldis[i]+1);
                    }
                }
            }
        }
        printf("%d\n",mini);
    }
    return 0;
}