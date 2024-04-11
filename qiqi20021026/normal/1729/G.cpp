#include<bits/stdc++.h>

using namespace std;

#define N 600

const int mod=1000000007;
struct dp{
    int x,y;
    bool operator < (const dp &t) const{
        return x<t.x;
    }
    dp operator + (const dp &t) const{
        return {x+t.x,y+t.y};
    }
    dp operator ^ (const dp &t) const{
        if (x<t.x) return (*this);
        if (x>t.x) return t;
        return {x,(y+t.y)%mod};
    }
}f[N],g[N];
int nxt[N];

void solve(){
    int n,m; string a,b;
    cin>>a; n=a.size();
    cin>>b; m=b.size();
    a="0"+a; b="0"+b;
    for (int i=2,j=0;i<=m;++i){
        while (j&&b[i]!=b[j+1]) j=nxt[j];
        nxt[i]=(j+=b[i]==b[j+1]);
    }
    f[0]={n+1,0};
    g[0]={0,1};
    for (int i=1,j=0;i<=n;++i){
        while (j&&b[j+1]!=a[i]) j=nxt[j];
        j+=a[i]==b[j+1];
        if (j==m){
            f[i]=g[i-m]+dp{1,0};
            g[i]=f[i];
            for (int k=i-m+1;k<i;++k){
                g[i]=g[i]^f[k];
            }
            j=nxt[j];
        }
        else{
            f[i]={n+1,0};
            g[i]=g[i-1];
        }
    }
    cout<<g[n].x<<' '<<g[n].y<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();

    return 0;
}