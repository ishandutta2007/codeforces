#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
int L[N],R[N];
void solve(){

    int n,l,r;cin>>n>>l>>r;
    for (int i=0;i<=n;i++) L[i]=R[i]=0;
    for (int i=1;i<=n;i++){
        int c;cin>>c;
        if (i<=l){
            L[c]++;
        } else {
            R[c]++;
        }
    }
    for (int i=1;i<=n;i++){
        int cur=min(L[i],R[i]);
        L[i]-=cur;
        R[i]-=cur;
        l-=cur;
        r-=cur;
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        while (l>r && L[i]>=2){
            l-=2;
            L[i]-=2;
            ans++;
        }
        while (r>l && R[i]>=2){
            r-=2;
            R[i]-=2;
            ans++;
        }

    }

    ans+=(r+l)/2+abs(r-l)/2;
    cout<<ans<<endl;



}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;

    while (tt--){
        solve();
    }
    return 0;
}
/**
1
4 0 4
4 4 4 3



**/