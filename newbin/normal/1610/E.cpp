#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 2e5+5;
int a[maxn]; int n;
int main(){
    int T; cin>>T;
    while(T--){
        scanf("%d", &n);
        fors(i,1,n+1)
            scanf("%d", &a[i]);
        int ans = 0;
        fors(i,1,n+1){
            int j = i; while(j+1<=n&&a[j+1] == a[i]) j++;
            int cur = a[i];
            int p = j; int res = j-i;
            while(p <= n){
                res++;
                p = lower_bound(a+p+1,a+1+n,2*a[p]-a[i])-a;
            }
            i = j; ans = max(ans, res);
        }
        ans = n-ans;
        cout<<ans<<endl;
    }
    return 0;
}