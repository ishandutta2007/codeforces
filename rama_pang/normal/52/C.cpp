#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N,arr[200005],M, segtree[800005], lazy[800005];

void build (ll node, ll tl, ll tr){
    if (tl==tr){
        segtree[node]=arr[tl];
        return;
    }
    ll mid=(tl+tr)/2;
    build(node*2, tl, mid);
    build(node*2 +1, mid+1, tr);
    segtree[node]=min(segtree[node*2], segtree[node*2 +1]);
    return;
}
void update (ll node, ll tl, ll tr, ll le, ll ri, ll val){
    if (lazy[node]!=0){
        segtree[node]+=lazy[node];
        if (tl!=tr){
            lazy[node*2]+= lazy[node];
            lazy[node*2 +1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if (tr<le or tl>ri or tl>tr) return;
    if (le<=tl and tr<=ri){
        segtree[node]+=val;
        if (tl!=tr){
            lazy[node*2]+= val;
            lazy[node*2 +1]+= val;
        }
        return;
    }
    ll mid=(tl+tr)/2;
    update(node*2, tl, mid, le, ri, val);
    update(node*2 +1, mid+1, tr, le, ri, val);
    segtree[node]=min(segtree[node*2], segtree[node*2 +1]);
    return;
}
ll query (ll node, ll tl, ll tr, ll le, ll ri){
    if (tr<le or tl>ri or tl>tr) return 8e18;
    if (lazy[node]!=0){
        segtree[node]+=lazy[node];
        if (tl!=tr){
            lazy[node*2]+= lazy[node];
            lazy[node*2 +1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if (le<=tl and tr<=ri){
        return segtree[node];
    }
    ll mid=(tl+tr)/2;
    ll p1=query(node*2, tl, mid, le, ri);
    ll p2=query(node*2 +1, mid+1, tr, le, ri);
    return min(p1,p2);   
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>N;
    for (ll i=0; i<N; i++){
        if (i==0){
            cin >> arr[N];
        } else{
            cin >> arr[i];
        }
    }
    for (ll i=0; i<=4*N ; i++){
        segtree[i]=8e18;
    }
    build(1,1,N);
    cin>>M;
    while (M--){
        ll a,b,c;
        c= 0;
        string d;
        cin>>a>>b;
        getline(cin,d);
        // cout << ">>>>>>>>"<<d.size()<<endl;
        if (d.size()>0){
            // c=0;
            ll neg=1;
            for (ll i=1; i<d.size(); i++){
                if (d[i]=='-') neg= -1;
                else c= c*10 + d[i]-'0'; 
            }
            c= neg*c;
        }

        if (a==0) a=N;
        if (b==0) b=N;
        // cout << "+++++++++++++++"<<a<< " " << b<< " " << c << endl;
        if (d.size()==0){
            if (a>b){
                cout << min(query(1,1,N,a,N),query(1,1,N,1,b)) << "\n";
            } else{
                cout << query(1,1,N,a,b) << "\n";
            }
            //query
        } else{
            if (a>b){
                update(1,1,N,a,N,c);
                update(1,1,N,1,b,c);
            } else{
                update(1,1,N,a,b,c);
            }
            //update by c
        }
    }
}