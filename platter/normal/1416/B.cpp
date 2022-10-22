#include <bits/stdc++.h>
using namespace std;

int arr[10001];
typedef pair<int,int> P;
typedef pair<P,int> Pi;
vector<Pi> ret;

int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++) {
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        if (sum%n!=0) {
            printf("-1\n");
            continue;
        }
        ret.clear();
        for(int i=2;i<=n;i++) {
            int val=i-(arr[i]%i);
            val%=i;
            ret.push_back(Pi(P(1,i),val));
            arr[1]-=val;
            arr[i]+=val;
            ret.push_back(Pi(P(i,1),arr[i]/i));
            arr[1]+=arr[i];
            arr[i]=0;
        }
        for(int i=2;i<=n;i++) {
            ret.push_back(Pi(P(1,i),sum/n));
        }
        printf("%d\n",ret.size());
        for(int i=0;i<ret.size();i++) {
            printf("%d %d %d\n",ret[i].first.first,ret[i].first.second,ret[i].second);
        }
    }
}