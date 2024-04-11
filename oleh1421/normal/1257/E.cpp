#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
//#define int long long
int used[300001];
int cnt3[300001];
int suf[300001];
int minx[300001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k1,k2,k3;cin>>k1>>k2>>k3;
    int n=k1+k2+k3;
    for (int i=1;i<=k1;i++){
        int x;cin>>x;
        used[x]=1;
    }
    for (int i=1;i<=k2;i++){
        int x;cin>>x;
        used[x]=2;
    }
    for (int i=1;i<=k3;i++){
        int x;cin>>x;
        used[x]=3;
    }
    cnt3[n+1]=suf[n+1]=minx[n+1]=0;
    cnt3[n]=(used[n]==3);
    suf[n]=(used[n]==2)-(used[n]==3);
    minx[n]=min(0,suf[n]);
    for (int i=n-1;i>=1;i--){
        cnt3[i]=cnt3[i+1]+(used[i]==3);
        suf[i]=suf[i+1]+(used[i]==2)-(used[i]==3);
        minx[i]=min(minx[i+1],suf[i]);
    }
    int res=n+n+n;
    int sum=0;
    for (int i=0;i<=n;i++){
        if (i) sum+=(used[i]!=1);
        used[i]=1;
        int cur=sum+k1-i+sum+minx[i+1]+cnt3[i+1];
        res=min(res,cur);
    }
    cout<<res;
    return 0;
}