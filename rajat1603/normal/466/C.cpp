#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<long> a (n+1);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    vector<long long> sums (n+1);
    sums[0] = a[0];
    for (int i=1;i<n;i++) {
        sums[i] = sums[i-1]+a[i];
    }
    if(sums[n-1]%3!= 0){
        printf("0");
        return 0;
    }
    vector<int> cnt (n);
    cnt[0]=(sums[0] == sums[n - 1] / 3);
    for(int i=1;i<n;i++){
        cnt[i] = (2*sums[n-1]==3*sums[i-1]);
    }
    vector<int> rev (n+1);
    rev[n - 1] = cnt[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rev[i] = rev[i + 1] + cnt[i];
    }
    long long count = 0;
    for (int i = 0; i < n - 2; ++i) {
        if (sums[i] == sums[n - 1] / 3) {
            count += rev[i + 2];
        }
    }
    printf("%I64d",count);
}