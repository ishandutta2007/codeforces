#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[100001];
int main(){
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    ll n,k;cin>>n>>k;
    if ((k*(k+1ll))>2ll*n){
        cout<<"NO";
        return 0;
    }
    if (k==1){
        cout<<"YES"<<endl;
        cout<<n;
        return 0;
    }
    if (k==2){
        if (n%2){
            if (n==1) cout<<"NO";
            else cout<<"YES"<<endl<<n/2<<" "<<n/2+1;
        } else {
            if (n==2 || n==4) cout<<"NO";
            else cout<<"YES"<<endl<<n/2-1<<" "<<n/2+1;
        }
        return 0;
    }
    if (k==3){
        if (n%3==0){
            cout<<"YES"<<endl<<n/3-1<<" "<<n/3<<" "<<n/3+1;
        } else if (n%3==1){
           cout<<"YES"<<endl<<n/3-1<<" "<<n/3<<" "<<n/3+2;
        } else if (n>8) cout<<"YES"<<endl<<n/3-1<<" "<<n/3+1<<" "<<n/3+2;
        else cout<<"NO";
        return 0;
    }

    for (int i=1;i<=k;i++) a[i]=i;
    n-=(k*(k+1ll))/2ll;
    int g=n/k;
    for (int i=1;i<=k;i++) a[i]+=g;
    n%=k;
    if (n>=1){
       a[k]+=n-1ll;
       a[k-1]++;
    }
    for (int i=1;i<k;i++) if (a[i]>=a[i+1] || a[i+1]>2*a[i]){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for (int i=1;i<=k;i++) cout<<a[i]<<" ";
    return 0;
}
/**
1 1
2 1
3 2
4 3
5 5

*/