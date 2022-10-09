#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
//..

ll n,m,a,b,x,y,z,ans,g[3010*3010],h[3010][3010],f[3010][3010];
deque<ll> q;

int main(){
    cin>>n>>m>>a>>b;
    cin>>g[0]>>x>>y>>z;
    for(ll i=1; i<=n*m; i++) g[i]=(g[i-1]*x+y)%z;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++) h[i][j]=g[(i-1)*m+j-1];
    }
    //H
    for(ll i=1; i<=n; i++){
        while(!q.empty()) q.pop_front();
        for(ll j=1; j<=m; j++){
            while(!q.empty()&&h[i][q.back()]>=h[i][j]) q.pop_back();
            if(!q.empty()&&q.front()+b-1<j) q.pop_front();
            q.push_back(j);
            f[i][j]=h[i][q.front()];
        }
    }
    //fh
    for(ll j=1; j<=m; j++){
        while(!q.empty()) q.pop_front();
        for(ll i=1; i<=n; i++){
            while(!q.empty()&&f[q.back()][j]>=f[i][j]) q.pop_back();
            if(!q.empty()&&q.front()+a-1<i) q.pop_front();
            q.push_back(i);
            if(i>=a&&j>=b) ans+=f[q.front()][j];
            //
        }
    }
    cout<<ans<<endl;
    return 0;
}