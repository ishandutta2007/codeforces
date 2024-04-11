#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=500055;
const ll mod=1000000007;
const ll inf=1e18;
int a[N];
struct SegTree{
    int pref[N*4];
    int suf[N*4];
    int sum[N*4];
    int val[N];
    void upd(int v,int l,int r,int pos,int x){
        if (l==r){
            pref[v]=suf[v]=sum[v]=val[l]=x;
            return;
        }
        int m=(l+r)/2;
        if (pos<=m) upd(v+v,l,m,pos,x);
        else upd(v+v+1,m+1,r,pos,x);
        sum[v]=sum[v+v]+sum[v+v+1];
        pref[v]=max(pref[v+v],sum[v+v]+pref[v+v+1]);
        suf[v]=max(suf[v+v+1],sum[v+v+1]+suf[v+v]);
//        cout<<"SEG "<<v<<" "<<sum[v]<<" "<<pref[v]<<" "<<suf[v]<<endl;
    }
    pair<int,int> get_pref(int v,int l,int r,int L){
        if (l>=L) return {pref[v],sum[v]};
        int m=(l+r)/2;
        if (m<L) return get_pref(v+v+1,m+1,r,L);
        auto A=get_pref(v+v,l,m,L);
        auto B=get_pref(v+v+1,m+1,r,L);
        A.first=max(A.first,A.second+B.first);
        A.second+=B.second;
        return A;
    }
    pair<int,int>get_suf(int v,int l,int r,int R){
        if (r<=R) return {suf[v],sum[v]};
        int m=(l+r)/2;
        if (R<=m) return get_suf(v+v,l,m,R);
        auto A=get_suf(v+v+1,m+1,r,R);
        auto B=get_suf(v+v,l,m,R);
        A.first=max(A.first,A.second+B.first);
        A.second+=B.second;

        return A;
    }

};
SegTree T1,T2;
vector<int>g[N];
int ans[N];
void solve(){
//    srand(time(NULL));
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        g[a[i]].push_back(i);
    }
    for (int i=1;i<=n;i++){
        T1.upd(1,1,n,i,1);
        T2.upd(1,1,n,i,-1);
    }
//    cout<<T2.get_pref(1,1,n,3).first<<endl;
    for (int i=1;i<=n;i++){
        for (int j:g[i]){
            T2.upd(1,1,n,j,1);
//            cout<<"OK "<<j<<endl;
        }
        for (int j:g[i]){
            int val1=T1.get_pref(1,1,n,j).first+T1.get_suf(1,1,n,j).first-T1.val[j];
            int val2=T2.get_pref(1,1,n,j).first+T2.get_suf(1,1,n,j).first-T2.val[j];
//            if (j==n-3) cout<<T1.get_suf(1,1,n,j).first<<" "<<T1.val[n-2]<<" "<<T1.val[n-1]<<" "<<T1.val[n]<<endl;
            ans[j]=max(val1/2,(val2-1)/2);
        }
        for (int j:g[i]){
            T1.upd(1,1,n,j,-1);
        }
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
////    cout<<endl;
//    for (int i=1;i<=n;i++){
//        int mx=0;
//        for (int l=1;l<=i;l++){
//            for (int r=i;r<=n;r++){
//                vector<int>v;
//                for (int j=l;j<=r;j++) v.push_back(a[j]);
//                sort(v.begin(),v.end());
//                int L=-1,R=-1;
//                for (int j=0;j<v.size();j++){
//                    if (v[j]==a[i]){
//                        if (L==-1) L=j;
//                        R=j;
//                    }
//                }
//                int m=v.size()/2;
//                mx=max(mx,abs(L-m));
//                mx=max(mx,abs(R-m));
//            }
//        }
//        cout<<mx<<" ";
//    }
//    cout<<endl;
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
//7
//3 6 5 6 2 1 3
//1 1 1 1 -1 -1 1
//3 1 1 1
/**
18
6 18 17 5 18 11 13 1 17 3 18 12 8 16 8 6 8 9


-1 1 1 -1 1 1 1 -1 1 -1 1 1 1 1 1 -1 1 1
**/
//k*d-d=2
//d*(k-2)=2
//k>1
//d=2