#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[505];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    if (n%2==1 && k%2==0){
        printf("-1\n"); fflush(stdout); return 0;
    }
    int cur = 0, mx = 1;
    for (int i=1;i<=n;i++){
        a[i] = 1; cur++;
    }
    while(cur%k || mx>cur/k){
        int idx = min_element(a+1, a+n+1)-a;
        a[idx] += 2;
        cur += 2;
        mx = max(mx, a[idx]);
    }
    int x = cur/k, ans = 0;
    for (int i=0;i<x;i++){
        vector<pair<int, int>> v;
        for (int j=1;j<=n;j++) v.emplace_back(a[j], j);
        sort(v.begin() ,v.end(), greater<pair<int, int>>());
        printf("? ");
        for (int j=0;j<k;j++){
            printf("%d ", v[j].second);
            a[v[j].second]--;
        }
        printf("\n");
        fflush(stdout);
        int tmp;
        scanf("%d", &tmp);
        ans ^= tmp;
    }
    for (int i=1;i<=n;i++) assert(a[i]==0);
    printf("! %d\n", ans);
    fflush(stdout);
    return 0;
}