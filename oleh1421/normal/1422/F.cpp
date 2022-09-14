#include<bits/stdc++.h>
typedef long long ll;

using namespace std;
#define endl '\n'
const ll mod=1000000007ll;
const int N=200010;
const int SZ=10000010;
int a[N];
bool used[N];
vector<int>small_primes;
vector<int>big_primes;
int t[N*2][88];
int x[88][N/2];
int mx_pw;
void build(int v,int l,int r){
    if (l==r){
        for (int i=0;i<86;i++){
            t[v][i]=x[i][l];
        }
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    for (int i=0;i<86;i++){
        t[v][i]=max(t[v+v][i],t[v+v+1][i]);
    }
}
int sol[100];
void get_mx(int v,int l,int r,int L,int R){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        for (int i=0;i<86;i++){
            sol[i]=max(sol[i],t[v][i]);
        }
        return;
    }
    int m=(l+r)/2;
    get_mx(v+v,l,m,L,R);
    get_mx(v+v+1,m+1,r,L,R);
}
struct node{
    int L,R;
    ll mult;
    node(){
        L=R=0;
        mult=1ll;
    }
};
node T[SZ];
int TOT=1;
int copy_v(int v){
    TOT++;
    T[TOT]=T[v];
    return TOT;
}
void upd(int v,int l,int r,int pos,ll x){
    if (l==r){
        T[v].mult=x;
        return;
    }
    int m=(l+r)/2;
    if (pos<=m){
        T[v].L=copy_v(T[v].L);
        upd(T[v].L,l,m,pos,x);
    } else {
        T[v].R=copy_v(T[v].R);
        upd(T[v].R,m+1,r,pos,x);
    }
    T[v].mult=(T[T[v].L].mult*T[T[v].R].mult)%mod;

}
ll get(int v,int l,int r,int L,int R){
    if (!v || l>R || r<L) return 1ll;
    if (l>=L && r<=R) return T[v].mult;
    int m=(l+r)/2;
    return (get(T[v].L,l,m,L,R)*get(T[v].R,m+1,r,L,R))%mod;
}
int root[N];
int last[N];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=2;i<N;i++) used[i]=true;
    for (int i=2;i*i<N;i++){
        if (used[i]){

            for (int j=i*i;j<N;j+=i) used[j]=false;
        }
    }
    for (ll i=2;i<N;i++){
        if (!used[i]) continue;
        if (i*i<N) small_primes.push_back(i);
        else big_primes.push_back(i);
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<small_primes.size();j++){
            x[j][i]=1;
            int p=small_primes[j];
            while (a[i]%p==0){
                a[i]/=p;
                x[j][i]*=p;
            }
        }
    }

//    cout<<small_primes.size()<<" "<<big_primes.size()<<endl;
    build(1,1,n);
    root[0]=1;
    for (int i=1;i<=n;i++){
        root[i]=copy_v(root[i-1]);
        if (last[a[i]]){
            upd(root[i],1,n,last[a[i]],1ll);
        }
        last[a[i]]=i;
        upd(root[i],1,n,i,a[i]);
    }
    int tt;cin>>tt;
    ll last=0;
    while (tt--){
        int x,y;cin>>x>>y;
        int l=(x+last)%n+1;
        int r=(y+last)%n+1;
        if (l>r) swap(l,r);
        last=1ll;

        for (int i=0;i<small_primes.size();i++){
            sol[i]=1ll;
        }
        get_mx(1,1,n,l,r);
        for (int i=0;i<small_primes.size();i++){
            last*=sol[i]*1ll;
            last%=mod;
        }
        last*=(get(root[r],1,n,l,r)*1ll);
        last%=mod;
        cout<<last<<endl;

    }
    return 0;
}
///try to solve I
///try to solve B(Two sets)
/*
)()(()
*/