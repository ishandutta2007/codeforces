#include <bits/stdc++.h>
using namespace std;

long long arr[200000];
multiset<long long> s;

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,x;
        scanf("%d %d",&n,&x);
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
            s.insert(arr[i]);
        }
        sort(arr,arr+n);
        int ret=n;
        for(int i=0;i<n;i++) {
            if (s.find(arr[i])==s.end()) {
                ret--;
                continue;
            }
            if (s.find(arr[i]*x)!=s.end()) {
                s.erase(s.find(arr[i]*x));
                ret--;
            }
            s.erase(s.find(arr[i]));
        }
        printf("%d\n",ret);
    }
    return 0;
}