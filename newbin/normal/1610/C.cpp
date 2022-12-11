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
int a[maxn], b[maxn];
int n;
bool check(int lim){
    int cur = 0;
    fors(i,1,n+1){
        if(b[i]>=cur && a[i]>=lim-1-cur) cur++;
        if(cur == lim) return true;
    }return false;
}
int main(){
    int T; cin>>T;
    while(T--){
        scanf("%d", &n);
        fors(i,1,n+1) scanf("%d%d", &a[i], &b[i]);
        int l = 1, r = n, ans = -1;
        while(l <= r){
            if(check(mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}