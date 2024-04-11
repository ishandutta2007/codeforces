//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=200010;
const ll mod=1000000007ll;
const int A=1000100;
int ask(int l,int r){
    if (l==r) return -1;
    cout<<"? "<<l<<" "<<r<<endl;
    int ans;cin>>ans;
    return ans;
}
void solve(){
    int n;cin>>n;
    int l=1,r=n;
    while (l<r){
        int mid=(l+r)/2;
        int x=ask(l,r);
        if (x<=mid){
            int y=ask(l,mid);
            if (x==y) r=mid;
            else l=mid+1;
        } else {
            int y=ask(mid+1,r);
            if (x==y) l=mid+1;
            else r=mid;
        }
    }
    cout<<"! "<<l<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}