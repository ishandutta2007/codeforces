#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[1001000];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    for (int i=0;i<n;i++) a[i] -= i;
    priority_queue<int> pq;
    ll ans=0;
    pq.push(a[0]);
    for (int i=1;i<n;i++){
        pq.push(a[i]);
        int r = pq.top();
        pq.pop();
        pq.push(a[i]);
        ans += r-a[i];
    }
    printf("%lld\n", ans);
    return 0;
}