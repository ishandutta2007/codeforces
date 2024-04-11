#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=1000010;
const ll mod=1000000007;
int win[N*4];
int t[N*4];
void upd(int v,int l,int r,int L,int R,int x){
    if (l==L && r==R){
        win[v]=x;
        if (x==1) t[v]=t[v+v+1];
        else if (x==0) t[v]=t[v+v];
        else t[v]=t[v+v]+t[v+v+1];
        return;
    }
    int m=(l+r)/2;
    if (m<L) upd(v+v+1,m+1,r,L,R,x);
    else upd(v+v,l,m,L,R,x);
    if (win[v]==1) t[v]=t[v+v+1];
    else if (win[v]==0) t[v]=t[v+v];
    else t[v]=t[v+v]+t[v+v+1];
}
int l[N],r[N];
void solve(){
    for (int i=0;i<N*4;i++){
        win[i]=1;
        t[i]=1;
    }
    int k;cin>>k;
    string s;cin>>s;
    int ind=0;
    for (int i=0;i<k;i++){
        for (int j=0;j<(1<<k);j+=(1<<(i+1))){
            l[ind]=j;
            r[ind]=j+(1<<(i+1))-1;
            ind++;
        }
    }
    for (int i=0;i<s.size();i++){
        int x=s[i]-'0';
        if (s[i]=='?') x=-1;
        upd(1,0,(1<<k)-1,l[i],r[i],x);
    }
    int q;cin>>q;
    for (int it=1;it<=q;it++){
        int p;cin>>p;
        p--;
        char c;cin>>c;
        int x=c-'0';
        if (c=='?') x=-1;
        upd(1,0,(1<<k)-1,l[p],r[p],x);
        cout<<t[1]<<endl;
    }
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