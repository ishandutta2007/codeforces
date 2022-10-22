#include<bits/stdc++.h>
using namespace std;
int n,a[300005],l,g,c[15000005],t=2147483647,tp;
bool f[15000005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)g=__gcd(a[i],g);
    for(int i=1;i<=n;i++)c[a[i]/g]++,l=max(l,a[i]/g);
    for(int i=2;i<=l;i++){
        tp=0;
        if(!f[i]){
            for(int j=i;j<=l;j+=i)f[j]=1,tp+=c[j];
        }
        t=min(t,n-tp);
    }
    if(t==2147483647)cout<<-1;else cout<<t; 
    return 0;
}