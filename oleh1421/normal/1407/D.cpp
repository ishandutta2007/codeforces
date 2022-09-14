#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=300010;
int h[N];
int a[N];
int b[N];
int dp[N];
struct SegTree{
    int t[N*4];
    void build(int v,int l,int r){
        if (l>r) return;
        t[v]=1000000001;
        if (l==r) return;
        int m=(l+r)/2;
        build(v+v,l,m);
        build(v+v+1,m+1,r);
    }
    void upd(int v,int l,int r,int pos,int x){
        if (l==r){
            t[v]=x;
            return;
        }
        int m=(l+r)/2;
        if (pos<=m) upd(v+v,l,m,pos,x);
        else upd(v+v+1,m+1,r,pos,x);
        t[v]=min(t[v+v],t[v+v+1]);
    }
    int get(int v,int l,int r,int L,int R){
        if (L>r || R<l) return 1000000001;
        if (l>=L && r<=R) return t[v];
        int m=(l+r)/2;
        return min(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
    }
};
SegTree Ta,Tb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++){
        a[i]=0;
        for (int j=i-1;j>0;j=a[j]){
            if (h[j]>=h[i]){
                a[i]=j;
                break;
            }
        }
        b[i]=0;
        for (int j=i-1;j>0;j=b[j]){
            if (h[j]<=h[i]){
                b[i]=j;
                break;
            }
        }
//        cout<<a[i]<<" "<<b[i]<<endl;
    }

    Ta.build(1,1,n);
    Tb.build(1,1,n);
    vector<int>st1;
    vector<int>st2;
    dp[1]=0;
    st1.push_back(1);
    st2.push_back(1);
    Ta.upd(1,1,n,1,0);
    Tb.upd(1,1,n,1,0);
    for (int i=2;i<=n;i++){
        dp[i]=dp[i-1]+1;
        dp[i]=min(dp[i],Ta.get(1,1,n,max(a[i],1),n)+1);
        dp[i]=min(dp[i],Tb.get(1,1,n,max(b[i],1),n)+1);
        while (!st1.empty() && h[st1.back()]<=h[i]) {
            Ta.upd(1,1,n,st1.back(),1000000001);
            st1.pop_back();
        }
        st1.push_back(i);
        Ta.upd(1,1,n,i,dp[i]);
        while (!st2.empty() && h[st2.back()]>=h[i]) {
            Tb.upd(1,1,n,st2.back(),1000000001);
            st2.pop_back();
        }
        st2.push_back(i);
        Tb.upd(1,1,n,i,dp[i]);
//        cout<<i<<" "<<dp[i]<<endl;

    }
    cout<<dp[n]<<endl;
    return 0;
}