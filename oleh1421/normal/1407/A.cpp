#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
void solve(){
    int n;cin>>n;
    int cnt0=0;
    int cnt1=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        cnt0+=(x==0);
        cnt1+=(x==1);
    }
    if (cnt0>=n/2){
        cout<<n/2<<endl;
        for (int i=1;i<=n/2;i++) cout<<"0 ";
        cout<<endl;
    } else {
        int sz=n/2;
        if (sz%2) sz++;
        cout<<sz<<endl;
        for (int i=1;i<=sz;i++) cout<<"1 ";
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}