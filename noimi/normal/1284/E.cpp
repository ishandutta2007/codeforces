#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define all(c) begin(c),end(c)
using namespace std;

struct point{
    int x,y;
    bool operator<(const point &r)const{
        int lx = x , ly = y,
        rx = r.x , ry = r.y;
        if(ly == 0){
            if(lx>0) lx=INT_MAX,ly=1;
            else lx=-INT_MAX,ly=-1;
        }
        if(ry == 0){
            if(rx > 0) rx=INT_MAX,ry=1;
            else rx=-INT_MAX,ry=-1;
        }
        if(ly < 0 && ry > 0) return false;
        if(ly > 0 && ry < 0) return true;
        if(ly > 0){
            if(lx >= 0 && rx < 0)return true;
            if(lx <0 && rx >= 0)return false;
            return (ll)ly*rx < (ll)lx*ry;
        }
        else{
            if(lx >= 0 && rx < 0)return false;
            if(lx <0 && rx >= 0)return true;
            return (ll)ly*rx < (ll)lx*ry;
        }
    }
};

using points = vector<point>;

main(){
    ll n; cin>>n;
    points v;
    rep(i,n){
        int x,y; cin>>x>>y;
        v.pb(point{x,y});
    }
    ll ans=n*(n-1)/2*(n-2)/3*(n-3)/4*(n-4);
    rep(i,n){
        int x=v[i].x,y=v[i].y;
        points now;
        rep(j,n){
            if(i!=j)now.pb(point{v[j].x-x,v[j].y-y});
        }
        sort(all(now));
        rep(j,n-1){
            point a={-now[j].x,-now[j].y};
            ll s=lower_bound(all(now),a)-now.begin();
            if(s<=j)s+=n-1;
            s-=j+1;
            ans-=s*(s-1)*(s-2)/6;
        }
    }
    cout<<ans<<endl; 
}