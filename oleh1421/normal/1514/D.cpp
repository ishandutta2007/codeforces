#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=500010;
const ll mod=1000000007;
const int K=600;
int a[N];
int l[N],r[N],ans[N];
bool cmp(int i,int j){
    if (l[i]/K<l[j]/K) return true;
    if (l[i]/K>l[j]/K) return false;
    return (r[i]<r[j]);
}
int cnt[N];
int cnt1[N];
int MX=0;
void add(int x){
    cnt1[cnt[x]]--;
    cnt[x]++;
    cnt1[cnt[x]]++;
    MX=max(MX,cnt[x]);
}
void del(int x){
    cnt1[cnt[x]]--;
    cnt[x]--;
    cnt1[cnt[x]]++;
    if (cnt1[MX]==0) MX--;
}
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int it=1;it<=q;it++) cin>>l[it]>>r[it];
    vector<int>Q;
    for (int i=1;i<=q;i++) Q.push_back(i);
    sort(Q.begin(),Q.end(),cmp);
    int L=1,R=0;
    cnt1[0]=n;
    for (int i=0;i<q;i++){
        while (R<r[Q[i]]){
            add(a[++R]);
        }
        while (L>l[Q[i]]){
            add(a[--L]);
        }
        while (R>r[Q[i]]){
            del(a[R--]);
        }
        while (L<l[Q[i]]){
            del(a[L++]);
        }
        ans[Q[i]]=MX;
    }




    for (int i=1;i<=q;i++){
        cout<<max(1,2*ans[i]-(r[i]-l[i]+1))<<endl;
    }
}
int32_t main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
///C=MEX(A)^B + MEX(B)^A
///MEX(C)=MEX(A)^MEX(B)
///A - DONE
//a b c
//a b c d

//0 1 2 3

//0 1 2 3
//0 1 2 3
//
//1+1+1+1+

/**
1 3
0.0 0.1 0.5 0.2
**/