#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;
int x[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        int n, r; scanf("%d%d", &n, &r);
        for(int i = 1; i <= n; ++i) scanf("%d", &x[i]);
        sort(x+1,x+1+n);
        n = unique(x+1,x+1+n)-x-1;
        int ans = n;
        for(int i = 2; i <= n; ++i){
            ans = min(ans, max((x[i-1]+r-1)/r , (n-i+1)) );
        }printf("%d\n", ans);
    }
}