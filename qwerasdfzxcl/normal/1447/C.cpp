#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<ll, int> a[200200];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        ll w;
        scanf("%d %lld", &n, &w);
        ll w0=w;
        for (int i=0;i<n;i++) {
            scanf("%lld", &a[i].first);
            a[i].second=i;
        }
        sort(a, a+n);
        vector<int> ans;
        for (int i=n-1;i>=0;i--){
            if (w>=a[i].first){
                ans.push_back(a[i].second);
                w -= a[i].first;
            }
        }
        sort(ans.begin(), ans.end());
        if (w>(w0)/2) printf("-1\n");
        else{
            printf("%d\n", ans.size());
            for (int x:ans) printf("%d ", x+1);
            printf("\n");
        }
    }
    return 0;
}