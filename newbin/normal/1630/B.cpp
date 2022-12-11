#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define mid ((r+l)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1,mid+1,r
#define pb push_back
#define lowbit(x) (x&(-x))
#define all(x) x.begin(),x.end()
using namespace std;
int n, k;
const int maxn = 2e5+5;
int a[maxn];
int cnt[maxn];
void init(){
    cin>>n>>k;
    fors(i,1,n+1) scanf("%d", &a[i]), cnt[i] = 0;
    fors(i,1,n+1) cnt[a[i]]++;
}
int x, y;
bool check(int len){
    int l = 1, r = l+len-1;
    int cur = 0; fors(i,l,r+1) cur += cnt[i];
    if(2*cur-n >= k) {
        x = l; y = r;
        return true;
    }
    while(r < n){
        cur += cnt[++r];
        cur -= cnt[l++];
        if(2*cur-n >= k) {
            x = l, y = r;
            return true;
        }
    }return false;
}
int b[maxn], c[maxn];
void sol(){
    int l = 0, r = n, res = -1;
    while(l <= r){
        if(check(mid)) res = mid, r = mid-1;
        else l = mid+1;
    }assert(res != -1);
    check(res);
    
    #define P pair<int,int>
    vector<P> ans;
    for(int i = 1; i <= n; ++i) b[i] = (a[i]<=y&&a[i]>=x);b[n+1]=0;
    for(int i = n; i > 0; --i) b[i] += b[i+1];
    c[n+1] = 1; for(int i = n; i > 0; --i) c[i] = (n-i+1)<b[i]*2;
    int cur = 0, len = 0;
    l = 1;
    for(int i = 1; i <= n; ++i){
        cur += b[i]-b[i+1]; len++;
        if(c[i+1] && len<2*cur){
            cur = 0; 
            ans.pb(P(l,l+len-1));
            l += len; len = 0;
        }
    }
    cout<<x<<" "<<y<<endl;
    while(ans.size() > k){
        int t = ans.size();
        ans[t-2].second = ans[t-1].second; ans.pop_back();
    }
    for(auto p:ans) printf("%d %d\n", p.first, p.second);
}
int main(){
    int T; cin>>T;
    while(T--){
        init();sol();
    }
    return 0;
}