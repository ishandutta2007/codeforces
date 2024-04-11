#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int SZ=7000010;
const ll mod=998244353;
const int L=20;
const ll inv2=(mod+1)/2;
int a[N];
int TOT=1;
int t[SZ][2];
int cnt[SZ];
void clr(){
    for (int i=0;i<=TOT;i++){
        t[i][0]=t[i][1]=cnt[i]=0;
    }
    TOT=1;
}
void add(int x){
    int v=1;
    cnt[v]++;
    for (int i=16;i>=0;i--){
        int cur=(x>>i)%2;
        if (!t[v][cur]) t[v][cur]=++TOT;
        v=t[v][cur];
        cnt[v]++;
    }
}
int get(int x){
    int v=1;
    int res=0;
    for (int i=16;i>=0;i--){
        int cur=(x>>i)%2;
        if (t[v][cur^1]) {
            v=t[v][cur^1];
            res^=(1<<i);
        } else {
            v=t[v][cur];
        }
    }
    return res;
}
void solve(){
    int l,r;cin>>l>>r;
    for (int i=1;i<=r-l+1;i++) cin>>a[i];
    clr();
    for (int i=1;i<=r-l+1;i++){
        add(a[i]);
    }
    for (int i=1;i<=r-l+1;i++){
        int x=a[i]^l;
        int mx=get(x);
        int mn=get(((1<<17)-1)^x)^((1<<17)-1);
        if (mn==l && mx==r){
            cout<<x<<endl;
            return;
        }
    }



}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//2


//
//1 2

/**

**/