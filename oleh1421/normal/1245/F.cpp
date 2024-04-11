
/*#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=1000000007ll;
int cnt[20001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l,r;cin>>l>>r;
    int cnt=0;
    for (int i=l;i<=r;i++){
        for (int j=l;j<=r;j++){
            if (i&j) continue;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define int long long
const long long mod=1000000007ll;
ll dp00[300];
ll dp01[300];
ll dp10[300];
ll dp11[300];
ll f(int x,int y){
    if (x==-1 || y==-1) return 0ll;
    ///a<=x
    ///b<=y
    vector<int>v;
    vector<int>u;
    while (x){
        v.push_back(x%2);
        x/=2;
    }
    while (y){
        u.push_back(y%2);
        y/=2;
    }
    while (v.size()<u.size()) v.push_back(0);
    while (v.size()>u.size()) u.push_back(0);
    v.push_back(0);
    u.push_back(0);
    int n=(int)v.size();
    ll res=1ll;
    ///0 - <=
    ///1 - >
    if (v[0]==0 && u[0]==0){
        dp00[0]=1;
        dp10[0]=1;
        dp01[0]=1;
        dp11[0]=0;
    } else if (v[0]==1 && u[0]==0){
        dp00[0]=2;
        dp10[0]=0;
        dp11[0]=0;
        dp01[0]=1;
    } else if (v[0]==0 && u[0]==1){
        dp00[0]=2;
        dp10[0]=1;
        dp11[0]=0;
        dp01[0]=0;
    } else {
        dp00[0]=3;
        dp10[0]=0;
        dp11[0]=0;
        dp01[0]=0;
    }
    for (int i=1;i<n;i++){
       // cout<<v[i]<<" "<<u[i]<<endl;
        if (v[i]==0 && u[i]==0){
            dp00[i]=dp00[i-1];
            dp10[i]=dp00[i-1]+dp10[i-1]+dp10[i-1];
            dp01[i]=dp00[i-1]+dp01[i-1]+dp01[i-1];
            dp11[i]=dp11[i-1]*3ll+dp10[i-1]+dp01[i-1];
        } else if (v[i]==1 && u[i]==0){
            dp00[i]=dp00[i-1]+dp10[i-1]+dp00[i-1];
            dp10[i]=dp10[i-1];
            dp11[i]=dp11[i-1];
            dp01[i]=(dp00[i-1]+dp10[i-1]+dp01[i-1]+dp11[i-1])+dp01[i-1]+dp11[i-1]+dp01[i-1];
        } else if (v[i]==0 && u[i]==1){
            dp00[i]=dp00[i-1]+dp01[i-1]+dp00[i-1];
            dp10[i]=(dp00[i-1]+dp10[i-1]+dp01[i-1]+dp11[i-1])+dp10[i-1]+dp11[i-1]+dp10[i-1];
            dp11[i]=dp11[i-1];
            dp01[i]=dp01[i-1];
        } else {
            dp00[i]=dp00[i-1]+dp10[i-1]+dp00[i-1]+dp01[i-1]+(dp00[i-1]+dp10[i-1]+dp01[i-1]+dp11[i-1]);
            dp10[i]=dp10[i-1]+dp11[i-1];
            dp11[i]=0;
            dp01[i]=dp01[i-1]+dp11[i-1];
        }
       // cout<<i<<" "<<dp00[i]<<" "<<dp01[i]<<" "<<dp10[i]<<" "<<dp11[i]<<endl;

    }
    return dp00[n-1];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int l,r;cin>>l>>r;
        cout<<f(r,r)-f(r,l-1)*2ll+f(l-1,l-1)<<endl;
    }

    return 0;
}