#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int b[maxn], p[maxn];
 
bool ok(int md, int a)
{
    long long res = 0;
    for(int i = 1, j = md; i <= md, j >= 1; i++, j--){
        res += max(0, b[j] - p[i]);
    }
        return res <= a;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     int n,m,t;
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    sort(b+1, b+m+1);
    sort(p + 1, p + n + 1, greater<int>());
    int lo = 0, hi = min(n,m);
    int ans = 0;
    while(hi >= lo){
        int mid = (hi + lo)/2;
        if(ok(mid, t))
        {
            ans = mid;
           // cout << ans << endl;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    long long cost = 0;
    for(int i = 1; i <= ans; i++){
        cost += b[i];
    }
    cout << ans << " "<<max(0LL, cost - t)<<endl;
}