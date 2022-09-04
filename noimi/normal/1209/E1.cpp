#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 1100000
ll MOD=1e9+7;
struct UnionFind{
    vector<int> par,sizes;
    UnionFind(int n):par(n+1),sizes(n+1,1){
        rep2(i,1,n)par[i]=i;
    }
    int find(int x){
        return (x==par[x]?x:par[x]=find(par[x]));
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return ;
        if(sizes[x]<sizes[y]){
            swap(x,y);
        }
        par[y]=x;
        sizes[x]+=sizes[y];
    }
    bool same(int x,int y) {return (find(x)==find(y));}
    int size(int x) {return sizes[find(x)];}
};
int gcd(int x,int y){
    if(x==0)return y;
    else{
        return gcd(y%x,x);
    }
}
main(){
    int T=in();
    rep(iii,T){
        vector<vec> row;
        int n=in(),m=in();
        row.resize(n+m+1);
        vector<pair<int,pii>> v;
        int mm=m;
        if(m<n){m=n;}
        rep(i,n)rep(j,m){
            int now;
            if(j>=mm){
                now=0;
            }
            else now=in();
            row[j].pb(now);
            v.pb({-now,{i,j}});
        }
        sort(all(v));
        vec used(m+1);
        int r=0;
        vec a;
        rep(i,m*n){
            if(!used[v[i].second.second]){
                used[v[i].second.second]=1;
                r++;
                a.pb(v[i].second.second);
            }
            if(r==n)break;
        }
        vector<vec> mat;
        mat.resize(n);
        rep(i,n)rep(j,n){
            mat[i].pb(row[a[j]][i]);
        }
        /*
        rep(i,n){
            rep(j,n)cout<<mat[i][j]<<" ";
            cout<<endl;
        }
        */
        int t=pow(n,n-1);
        int M=0;
        //cout<<t<<" "<<"u"<<endl;
        rep(i,t){
            vector<vec> newmat;
            newmat.resize(n);
            int tt=i;
            rep(j,n){
                int k=tt%n;
                tt/=n;
                //cout<<k<<endl;
                rep(i,n){
                    newmat[(i+k)%n].pb(mat[i][j]);
                }
            }
            /*
            rep(i,n){
                rep(j,n)cout<<newmat[i][j]<<" ";
                cout<<endl;
            }
            */
            int tmp=0;
            rep(i,n){
                int MM=0;
                rep(j,n){
                    MM=max(newmat[i][j],MM);
                }
                tmp+=MM;
            }
            M=max(M,tmp);
        }
        cout<<M<<endl;
    }
}