#include<bits/stdc++.h>
using namespace std;
int a[10001],b[10001],c[10001],q[1001],f[1001];
int main(){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>q[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    cin>>a[i]>>b[i]>>c[i];
    int big=1;
    for(int i=2;i<=n;i++){
        if(q[i]>q[big]) big=i;
    }
    for(int i=1;i<=n;i++) f[i]=1000100;
    for(int i=1;i<=m;i++){
        if(q[a[i]]<=q[b[i]]) continue;
        else f[b[i]]=min(f[b[i]],c[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i!=big&&f[i]==1000100){
            cout<<"-1";
            return 0;
        }
        else if(i==big)
        continue;
        ans+=f[i];
    }
    cout<<ans;
}