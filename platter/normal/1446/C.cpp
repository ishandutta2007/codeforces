#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(void) {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int ret=n;
    for(int i=0;i<v.size();i++) {
        int l=(v[i]|1)-1;
        int r=(v[i]|1);
        int sum=upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l);
        int val=0;
        for(int j=1;j<30;j++) {
            int mid=(l|(1<<j));
            l=mid-(1<<j);
            r=mid+(1<<j)-1;
            int value=upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l)-sum;
            sum+=value;
            if (value>1) {
                val+=value-1;
            }
        }
        ret=min(ret,val);
    }
    printf("%d",ret);
}