#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int p[500001];
int cnt[4];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    int cur=1;
    cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
    int l=0;
    for (int i=1;i<=n/2 && cur<=3;i++){
        l++;
        cnt[cur]++;
        if (p[i]>p[i+1] && (cur==1 || cnt[cur]>cnt[1])) cur++;
    }
    if (cur<=3){
        cout<<"0 0 0\n";
        return;
    }
    for (int i=n/2;i>=l;i--){
        if (p[i]>p[i+1]){
            cout<<cnt[1]<<" "<<cnt[2]<<" "<<i-cnt[1]-cnt[2]<<endl;
            return;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}