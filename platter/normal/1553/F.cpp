#include <bits/stdc++.h>
using namespace std;

long long arr[200000];
const int sq=500;
long long vec[300001];
long long psum[300001];
const int MAX=300000;
int ct[300001];

int main() {
    int n;
    scanf("%d",&n);
    //n=200000;
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        //arr[i]=i+1;
    }
    long long ret=0;
    long long sum=0;
    for(int ind=0;ind<n;ind+=sq) {
        int en=min(n-1,ind+sq-1);
        for(int i=ind;i<=en;i++) {
            ct[arr[i]]++;
            int val=floor(sqrt(arr[i]));
            int prev=1;
            for(int x=1;x<=val;x++) {
                int cnt=vec[x]-vec[x-1];
                ret+=1LL*(arr[i]%x+x%arr[i])*cnt;
            }
            prev=val;
            for(int x=val;x>=1;x--) {
                int cnt=vec[arr[i]/x]-vec[prev];
                long long got=psum[arr[i]/x]-psum[prev];
                prev=arr[i]/x;
                ret+=got;
                ret+=arr[i]*cnt-x*got;
            }
            for(int x=arr[i];x<=MAX;x+=arr[i]) {
                int cnt=vec[min(MAX,(int)x+(int)arr[i]-1)]-vec[x-1];
                long long got=psum[min(MAX,(int)x+(int)arr[i]-1)]-psum[x-1];
                ret+=cnt*arr[i];
                ret+=got-(x/arr[i])*cnt*arr[i];
            }
            for(int j=ind;j<i;j++) {
                ret+=arr[j]%arr[i]+arr[i]%arr[j];
            }
            sum+=ret;
            printf("%lld ",ret);
        }
        for(int i=1;i<=MAX;i++) {
            vec[i]=vec[i-1]+ct[i];
            psum[i]=psum[i-1]+1LL*ct[i]*i;
        }
    }
    //printf("%lld",sum);
}