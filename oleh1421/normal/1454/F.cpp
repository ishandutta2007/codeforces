//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int pref[N];
int suf[N];
map<int,int>cnt;
int a[N];
int t[N*4];
void build(int v,int l,int r){
    if (l==r){
        t[v]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=min(t[v+v],t[v+v+1]);
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 1000000001;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return min(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    int n;cin>>n;
    cnt.clear();
    for (int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    pref[0]=0;
    for (int i=1;i<=n;i++) pref[i]=max(pref[i-1],a[i]);
    suf[n+1]=0;
    for (int i=n;i>=1;i--) suf[i]=max(suf[i+1],a[i]);
    build(1,1,n);
    for (auto cur:cnt){
        if (cur.second<3) continue;
        int L=upper_bound(pref+1,pref+n+1,cur.first)-pref-1;
        int R=n+1;
        for (int i=20;i>=0;i--){
            if (R<=(1<<i)) continue;
            if (suf[R-(1<<i)]<=cur.first) R-=(1<<i);
        }

        if (L<1 || R>n) continue;
        if (L>R){
            int timer=0;
            for (int i=1;i<=n;i++){
                if (a[i]==cur.first) timer++;
                if (timer==2){
                    cout<<"YES\n";
                    cout<<i-1<<" "<<1<<" "<<n-i<<endl;
                    return;
                }
            }
        } else {

            if (get(1,1,n,L+1,R-1)==cur.first && pref[L]==cur.first && suf[R]==cur.first){
                cout<<"YES\n";
                cout<<L<<" "<<R-L-1<<" "<<n-R+1<<endl;
                return;
            } else if (get(1,1,n,L,R-1)==cur.first && pref[L-1]==cur.first && suf[R]==cur.first){
                cout<<"YES\n";
                cout<<L-1<<" "<<R-L<<" "<<n-R+1<<endl;
                return;
            } else if (get(1,1,n,L+1,R)==cur.first && suf[R+1]==cur.first && pref[L]==cur.first){
                cout<<"YES\n";
                cout<<L<<" "<<R-L<<" "<<n-R<<endl;
                return;
            }
        }

    }
    cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/*
1
5
1 2 3 2 2
*/