#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<pair<ll,ll>,bool>>irany(n);
        for(int i=0;i<n;i++){
            ll x,y,u,v;;
            cin>>x>>y>>u>>v;
            if(u > x || (u == x && v > y)) irany[i].second=1;
            else irany[i].second=0;
            if (irany[i].second==0) {
                swap(u, x);
                swap(v, y);
            }
            irany[i].first.first=u-x;
            irany[i].first.second=v-y;
        }
        sort(irany.begin(),irany.end(),[](pair<pair<ll,ll>,bool>a,pair<pair<ll,ll>,bool>b){return (a.first.first*b.first.second<a.first.second*b.first.first);});
        ll aktb=0,aktj=0;
        ll ki=0;
        if(irany[0].second) aktj++;
        else aktb++;
        for(int i=1;i<n;i++){
            if(irany[i].first.first*irany[i-1].first.second!=irany[i].first.second*irany[i-1].first.first){
                ki+=aktb*aktj;
                aktb=aktj=0;
            }
            if(irany[i].second) aktj++;
            else aktb++;
            if(i == n-1) ki+=aktb*aktj;
        }
        cout<<ki<<endl;
    }
}