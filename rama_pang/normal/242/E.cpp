#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

ll N,arr[100005],lazy[410005];
int segtree[410005][70];
int digits[410005][70];
void build (ll n, ll tl, ll tr){
    if (tl==tr){
        ll l=arr[tl],cnt=0;
        while (l>0){
            segtree[n][++cnt]= (l&1);
            l/=2;
        }
        return;
    }
    ll c=(tl+tr)/2;
    build(n*2,tl,c);
    build(n*2 +1,c+1,tr);
    for (ll i=0; i<=65; i++){
        segtree[n][i]=segtree[n*2][i] + segtree[n*2 +1][i];
    }
}
void upd (ll n, ll tl, ll tr, ll le, ll ri, ll val){
    if (lazy[n]!=0){
        ll l=lazy[n], cnt=0;
        while (l>0){
            cnt++;
            if (l&1) segtree[n][cnt]= tr-tl+1-segtree[n][cnt];
            l/=2;
        }
        // for (int i=1; i<=65; i++){
        //     if (lazy[n]&(1<<(i-1))) segtree[n][i]=tr-tl+1-segtree[n][i];
        // }
        if (tl!=tr){
            lazy[n*2]^=lazy[n]; lazy[n*2 +1]^=lazy[n];
        }
        lazy[n]=0;
    }
    if (tr<le or tl>ri or tl>tr) return;
    if (le<=tl and tr<=ri){
        lazy[n]=val;
        ll l=lazy[n], cnt=0;
        while (l>0){
            cnt++;
            if (l&1) segtree[n][cnt]= tr-tl+1-segtree[n][cnt];
            l/=2;
        }
        // for (int i=1; i<=65; i++){
        //     if (lazy[n]&(1<<(i-1)))segtree[n][i]=tr-tl+1-segtree[n][i];
        // }
        if (tl!=tr){
            lazy[n*2]^=lazy[n]; lazy[n*2 +1]^=lazy[n];
        }
        lazy[n]=0;
    } else{
        ll c=(tl+tr)/2;
        upd(n*2,tl,c,le,ri,val);
        upd(n*2 +1,c+1,tr,le,ri,val);
        for (ll i=0; i<=65; i++){
            segtree[n][i]=segtree[n*2][i] + segtree[n*2 +1][i];
        }
    }
}
ll query (ll n, ll tl, ll tr, ll le, ll ri){

    if (lazy[n]!=0){
        ll l=lazy[n], cnt=0;
        while (l>0){
            cnt++;
            if (l&1) segtree[n][cnt]= tr-tl+1-segtree[n][cnt];
            l/=2;
        }
        // for (int i=1; i<=65; i++){
        //     if (lazy[n]&(1<<(i-1)))segtree[n][i]=tr-tl+1-segtree[n][i];
        // }
        if (tl!=tr){
            lazy[n*2]^=lazy[n]; lazy[n*2 +1]^=lazy[n];
        }
        lazy[n]=0;
    }   
    if (tr<le or tl>ri or tl>tr) return 0;    
    if (le<=tl and tr<=ri){
        ll res=0;
        for (ll i=65; i>=1; i--){
            res*=2;
            res+= segtree[n][i];
            // res+= segtree[n][i]<<(ll)(i-1ll);
        }
        return res;
    }
    ll c=(tl+tr)/2;
    ll k= query(n*2, tl,c,le,ri)+query(n*2 +1,c+1,tr,le,ri);
    return k;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>N;
    for (ll i=1; i<=N; i++) cin >> arr[i];
    build(1,1,N);
    ll M; cin >> M;
    while (M--){
        ll t,a,b,c; cin >> t;
        if (t==1){
            cin>>a>>b;
            // cout << "===========" << endl;
            cout << query(1,1,N,a,b) << endl;
            
            // cout << endl;
        } else{
            cin>>a>>b>>c;
            upd(1,1,N,a,b,c);
        }

        // cout << "=================" << endl;
        // for (int i=1; i<=N; i++){
        //     cout << query(1,1,N,i,i) << " ";
        // }
        // cout << endl;
    }
}