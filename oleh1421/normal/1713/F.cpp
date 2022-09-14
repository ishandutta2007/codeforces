#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = (1<<20);
const ll mod=998244353;
const ll inf=1e18;
int b[N];
int a[N];
int a1[N];
int lg[N];
vector<int>conv(vector<int>a){
    int k=lg[a.size()];
    for (int i=0;i<k;i++){
        for (int j=0;j<(1<<k);j++){
            if (j&(1<<i)) a[j]^=a[j^(1<<i)];
        }
    }
    return a;
}
vector<int>get(vector<int>a,vector<int>b){
//    cout<<a.size()<<" "<<b.size()<<endl;
//    for (int i:a) cout<<i<<" ";
//    cout<<endl;
//    for (int i:b) cout<<i<<" ";
//    cout<<endl;
    int cntA=0,cntB=0;
    for (int i:a) cntA+=(i==-1);
    for (int i:b) cntB+=(i==-1);
    if (cntA>cntB){
        return conv(get(b,a));
    }
    if (!cntA) return a;
    int k=lg[a.size()];
    auto dp=a;
    for (int i=0;i<k-1;i++){
        for (int j=(1<<(k-1));j<(1<<k);j++){
            if (j&(1<<i)) dp[j]^=dp[j^(1<<i)];

        }
    }
    vector<int>a1((1<<(k-1)),-1);
    vector<int>b1((1<<(k-1)),-1);
    for (int i=0;i<(1<<(k-1));i++) a1[i]=a[i];
    for (int i=(1<<(k-1));i<(1<<k);i++){
        if (b[i]!=-1){
            b1[i-(1<<(k-1))]=dp[i]^b[i];
        }
    }
    a1=get(a1,b1);
    for (int i=0;i<(1<<(k-1));i++) a[i]=a1[i];
//    cout<<a.size()<<endl;
    return a;
}
void solve(){
    int n;cin>>n;
    int k=0;
    while ((1<<k)<n) k++;
    vector<int>a((1<<k),-1),b((1<<k),-1);
    for (int i=1;i<=n;i++){
        cin>>a[(1<<k)-i];
    }
    for (int i=n;i<(1<<k);i++){
        b[i]=0;
    }
    auto ans=get(a,b);
    ans=conv(ans);
    for (int i=n-1;i>=0;i--) cout<<ans[i]<<" ";
    cout<<endl;
//    0...n-1
//    0...(1<<k)-n-1

}
int main()
{
    for (int i=0;(1<<i)<N;i++) lg[(1<<i)]=i;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}