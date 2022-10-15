#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,t,t1,u,v,a,b;
long long MOD=998244353;
int main() {
    cin>>t;
    for (t1=0;t1<t;t1++) {
        u=1;
        cin>>n>>m;
        for (i=1;i<=n-m;i++) {
            cin>>v;
            if (v==-1) u*=i+m;
            else if (v==0) u*=m+1;
            u%=MOD;
        }
        for (i=1;i<=m;i++) {
            cin>>v; if (v>0) u=0; else u*=i;
            u%=MOD;
        }
        cout<<u<<endl;
    }
}