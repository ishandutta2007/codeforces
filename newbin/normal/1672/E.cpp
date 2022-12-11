#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
int ask(int w){
    cout<<"? "<<w<<endl;
    cout.flush();
    int h; cin>>h; return h;
}
int main(){
    int n; cin>>n;
    int l = 1, r = n*2001, res = -1;
    while(l <= r){
        if(ask(mid) == 1) res = mid, r = mid-1;
        else l = mid+1;
    }
    ll ans = res;
    for(int i = 2; i <= n; ++i){
        int w = (ans-1)/i;
        if(w == 0) break;
        int h = ask(w);
        if(h == 0) break;
        ans = min(ans, (ll)w*h);
    }
    cout<<"! "<<ans<<endl;
    return 0;
}