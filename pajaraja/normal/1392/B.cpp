#include<bits/stdc++.h>
#define MAXN 200007
using namespace std;
int n,a[MAXN];
long long k;
void op()
{
    int mx=-1000000000;
    for(int i=0;i<n;i++) mx=max(mx,a[i]);
    for(int i=0;i<n;i++) a[i]=mx-a[i];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>a[i];
        op();
        if(k%2==0) op();
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
}