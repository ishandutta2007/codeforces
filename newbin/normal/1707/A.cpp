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
int main(){
    ios::sync_with_stdio(false);
    int T; cin>>T;
    while(T--){
        int n, q;
        cin>>n>>q;
        vector<int> a(n);
        fors(i,0,n) cin>>a[i];
        int l = 0, r = n, ans = -1;
        auto check = [&](int lim)->bool{
            vector<int> vis(n);
            int cnt = 0;
            for(int i = n-1; i >= 0; --i) if(a[i] <= q) vis[i] = 1, cnt++;
            for(int i = n-1; i >= 0; --i){
                if(!vis[i] && cnt < lim) cnt++, vis[i] = 1;
            }
            int cur = q;
            fors(i,0,n){
                if(!vis[i]) continue;
                if(a[i]>cur) cur--;
                if(cur<0) return false;
            }return true;
        };
        while(l <= r){
            if(check(mid)) ans = mid, l = mid+1;
            else r = mid-1;
        }
        vector<int> vis(n); int cnt = 0;
        for(int i = n-1; i >= 0; --i) if(a[i] <= q) vis[i] = 1, cnt++;
        for(int i = n-1; i >= 0; --i){
            if(!vis[i] && cnt < ans) cnt++, vis[i] = 1;
        }
        fors(i,0,n) cout<<vis[i]; cout<<"\n";
    }
    return 0;
}