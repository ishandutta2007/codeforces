#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    ll a[100000],b[50000];
    ll ans=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int it=n-1;
    int m=0;
    while(it>0){
        if(a[it]==a[it-1]){
            b[m]=a[it];
            m++;
            it-=2;
        }
        else
        if(a[it]-1==a[it-1]){
            b[m]=a[it]-1;
            m++;
            it-=2;
        }
        else
            it--;
    }
    for(int i=0;i<m;i+=2)
        ans+=b[i]*b[i+1];
    cout<<ans;
}