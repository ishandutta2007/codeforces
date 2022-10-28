#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int maxn=200007;
int t;
int n,a[maxn],b[maxn],d[maxn];
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=0;i<2*n;++i) cin>>a[i];
        sort(a,a+2*n,greater<int>());
        for (int i=0;i<n;++i){
            if (a[i*2]!=a[i*2+1]){
                cout<<"NO\n";
                goto cont;
            }
            b[i]=a[i*2];
        }
        for (int i=1;i<n;++i){
            if (b[i-1]==b[i]||(b[i-1]-b[i])%(2*(n-i))){
                cout<<"NO\n";
                goto cont;
            }
            d[i]=(b[i-1]-b[i])/2/(n-i);
        }
        for (int i=1;i<n;++i){
            b[n-1]-=2*i*d[i];
        }
        if (b[n-1]<=0||b[n-1]%(2*n)) cout<<"NO\n";
        else cout<<"YES\n";
 
        cont:;
    }
    return 0;
}