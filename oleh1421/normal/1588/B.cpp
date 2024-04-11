//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=10100;
ll get(int l,int r){
    if (l==r) return 0;
    cout<<"? "<<l<<" "<<r<<endl;
    ll ans;cin>>ans;
    if (ans==-1) exit(0);
    return ans;
}
ll calc(ll x){
    ll y=0ll;
    for (ll j=30;j>=0;j--){
        if ((y+(1ll<<j))*(y+(1ll<<j)-1ll)/2ll<=x) y+=(1<<j);
    }
    if ((y)*(y-1ll)/2ll<x) return 1000000001;
    return y;
}
void solve(){
    int n;cin>>n;
    int l=1,r=n;
    ll tot=get(1,n);
    while (true){
        int mid=(l+r)/2;
        ll cur=get(1,mid);
        if (cur==0) l=mid;
        else if (cur==tot) r=mid;
        else {

            if (mid-calc(cur)+1>=1 && get(1,mid-calc(cur)+1)==0){
//                cout<<"AAAAAAA "<<mid<<endl;
                int i=mid-calc(cur)+1;
                int k=r;
                for (int j=30;j>=0;j--){
                    if (k-(1<<j)>=i && get(k-(1<<j),n)==0) k-=(1<<j);
                }
                ll x=0ll;
                ll l=k-i+1;
                for (int j=30;j>=0;j--){
                    if (x+(1ll<<j)<=l/2 && (x+(1ll<<j))*(x+(1ll<<j)-1ll)/2ll+(l-x-(1ll<<j))*(l-x-(1ll<<j)-1ll)/2ll>=tot) x+=(1ll<<j);
                }
                x=l-x;
                if (get(i,i+x-1)!=x*(x-1ll)/2ll) x=l-x;
                cout<<"! "<<i<<" "<<i+x<<" "<<k<<endl;
                return;
            } else {
//                cout<<"OOOOO "<<mid<<endl;

                cur=get(mid,n);
                int k=mid+calc(cur)-1;
                int i=l;
                for (int j=30;j>=0;j--){
                    if (i+(1<<j)<=k && get(1,i+(1<<j))==0) i+=(1<<j);
                }
                ll x=0ll;
                ll l=k-i+1;
                for (int j=30;j>=0;j--){
                    if (x+(1ll<<j)<=l/2 && (x+(1ll<<j))*(x+(1ll<<j)-1ll)/2ll+(l-x-(1ll<<j))*(l-x-(1ll<<j)-1ll)/2ll>=tot) x+=(1ll<<j);
                }
                x=l-x;
                if (get(i,i+x-1)!=x*(x-1ll)/2ll) x=l-x;
                cout<<"! "<<i<<" "<<i+x<<" "<<k<<endl;

                return;
            }

        }

    }



}
int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout<<calc(11)<<endl;
    int tt;cin>>tt;
    while (tt--){
        solve();
    }




    return 0;
}
//5
//3 2 1 5 4
/**
100000000 3
0 0 0 1 1
**/