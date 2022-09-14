#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int x[300001];
int n,r;
void solve(){
    ll x,y;cin>>x>>y;
    if (x-y==1ll) cout<<"NO\n";
    else cout<<"YES\n";
}
int main()
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
/*
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int x[100001];
int y[100001];
int minx[100001];
int maxx[100001];
int n,k;
int f(int l,int r,int j){
    int l1=l+(k-l%k+j%k)%k;
    int r1=r-(k+r%k-j%k)%k;
    return (r1-l1)/k+(l1-l>0)+(r-r1>0);
}
int main()
{
    //freopen("monument.in","r",stdin);
    //freopen("monument.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i],x[i]++,y[i]++;
    for (int i=1;i<=n;i++){
        int nxt=i+1;
        if (nxt>n) nxt=1;
        if (x[i]==x[nxt]){
            for (int j=min(y[i],y[nxt]);j<max(y[i],y[nxt]);j++){
                if (!minx[j] || minx[j]>x[i]) minx[j]=x[i];
                if (maxx[j]<x[i]) maxx[j]=x[i];
            }
        }
    }
    ll sum=0ll;
        //cout<<i<<endl;
    vector<int>v;
    for (int j=0;j<=100000;j++){
        if (!minx[j]) continue;
        if ((maxx[j]-minx[j])<k) sum++;
        else if ((maxx[j]-minx[j])%k==0) v.push_back(minx[j]%k),sum+=(maxx[j]-minx[j])/k;
        else

        cur+=f(minx[j],maxx[j],j);
    }
    cout<<sum;
    return 0;
}

*/