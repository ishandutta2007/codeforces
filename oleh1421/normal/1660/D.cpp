#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;
int a[N];
int ans=0;
int L,R;
void upd_ans(int l,int r){
    int z=1;
    int cn=0;
    for (int i=l;i<=r;i++){
        if (a[i]<0) z=-z;
        else if (a[i]==0) z=0;
        if (abs(a[i])==2) cn++;
    }
    if (z<=0) return;
    if (cn>ans){
        L=l,R=r;
        ans=cn;
    }
}

void upd(int l,int r){
    upd_ans(l,r);
    for (int i=l;i<r;i++){
        if (a[i]<0){
            upd_ans(i+1,r);
            break;
        }
    }
    for (int i=r;i>l;i--){
        if (a[i]<0){
            upd_ans(l,i-1);
            break;
        }
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ans=0;
    L=1,R=0;
    int last=0;
    for (int i=1;i<=n;i++){
        if (a[i]==0){
            upd(last+1,i-1);
            last=i;
        }
    }
    upd(last+1,n);
    cout<<L-1<<" "<<n-R<<endl;



}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}