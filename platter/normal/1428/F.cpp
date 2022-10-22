#include <cstdio>
#include <algorithm>
using namespace std;

int arr[500000];
int n;
long long cnt[500001];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%1d",&arr[i]);
    }
    int row=0;
    int mx=0;
    long long val=0;
    long long ret=0;
    for(int i=0;i<n;i++) {
        if (arr[i]==0) {
            row=0;
            cnt[0]++;
        }
        else {
            row++;
            if (row>mx) {
                cnt[row]=cnt[mx]-1;
                val+=cnt[row]*row;
                val-=(cnt[mx]-1)*mx;
                cnt[mx]=1;
            }
            cnt[row]+=cnt[row-1]-(row!=1);
            val+=(cnt[row-1]-(row!=1))*row;
            val-=(cnt[row-1]-(row!=1))*(row-1);
            cnt[row-1]=(row!=1);
            cnt[row]++;
            val+=row;
            mx=max(mx,row);
        }
        ret+=val;
    }
    printf("%lld",ret);
}