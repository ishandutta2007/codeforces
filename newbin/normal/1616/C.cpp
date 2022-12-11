#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> a(n);
        fors(i,0,n) cin>>a[i];
        int ans = n;
        if(n == 1) ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int dx = j-i;
                int dy = a[j]-a[i];
                int cnt = 2;
                for(int k = 0; k < n; ++k){
                    if(k == i || k == j) continue;
                    int x = k-i;
                    int y = a[k]-a[i];
                    if((ll)x*dy == (ll)y*dx) cnt++;
                }
                ans = min(ans, n-cnt);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}