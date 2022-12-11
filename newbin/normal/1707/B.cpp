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
void sol(){
    int n; cin>>n;
    vector<int> a(n);
    fors(i,0,n) cin>>a[i];
    int zero = 0;
    vector<int> b;
    fors(i,1,n){
        if(a[i] == a[i-1]) zero++;
        else b.pb(a[i]-a[i-1]);
    }sort(all(b)); a = b;
    for(int i = 0; i < n-2; ++i){
        if(a.size() == 0) break;
        b.clear();
        if(zero) b.pb(a[0]), zero--;
        for(int j = 1; j < a.size(); ++j){
            if(a[j] == a[j-1]) zero++;
            else b.pb(a[j]-a[j-1]);
        }
        a = b; sort(all(a));
    }
    if(a.size() == 0) cout<<0<<"\n";
    else cout<<a[0]<<endl;
}
int main(){
    // freopen("1.in" , "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin>>T;
    while(T--){
        sol();
    }
    return 0;
}