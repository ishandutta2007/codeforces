#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int tc;
    scanf("%d\n",&tc);
    for(int t=0;t<tc;t++) {
        int n,k;
        scanf("%d %d\n",&n,&k);
        priority_queue<int,vector<int>,greater<int>> a;
        priority_queue<int> b;
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            a.push(x);
        }
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            b.push(x);
        }
        for(int i=0;i<k;i++) {
            int mini=a.top();
            int maxi=b.top();
            if (mini>maxi) {
                break;
            }
            a.pop();
            b.pop();
            b.push(mini);
            a.push(maxi);
        }
        int sum=0;
        for(int i=0;i<n;i++) {
            sum+=a.top();
            a.pop();
        }
        printf("%d\n",sum);
    }
}