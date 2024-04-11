#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll MOD=1e9+993,X[200001],ha[200001],hb[200001],n;
ll hash_substra(int l, int r){
    ll x=ha[r+1]-ha[l];
    if(x<0)
        x+=MOD;
    return (x*X[n-l])%MOD;
}
ll hash_substrb(int l, int r){
    ll x=hb[r+1]-hb[l];
    if(x<0)
        x+=MOD;
    return (x*X[n-l])%MOD;
}
bool fun(int la, int ra, int lb, int rb){
    if(hash_substra(la, ra) == hash_substrb(lb, rb))
        return 1;
    int ma=(la+ra)/2;
    int mb=(lb+rb)/2;
    if((ra-la+1)%2==0)
        return (fun(la,ma,lb,mb) && fun(ma+1,ra,mb+1,rb)) || (fun(ma+1,ra,lb,mb) && fun(la,ma,mb+1,rb));
    return 0;
}
int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    ios::sync_with_stdio(false);
    string a, b;
    cin>>a>>b;
    n=a.length();
    X[0]=1;
    for(int i=1;i<=n;i++)
        X[i]=(X[i-1]*31)%MOD;
    ha[0]=0,hb[0]=0;
    for(int i=1;i<=n;i++)
        ha[i]=(ha[i-1]+X[i-1]*(a[i-1]-'a'+1))%MOD,hb[i]=(hb[i-1]+X[i-1]*(b[i-1]-'a'+1))%MOD;
    if(fun(0, n-1, 0, n-1))
        cout<<"YES";
    else
        cout<<"NO";
}