#include <bits/stdc++.h>
using namespace std;
int a[107];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,sum=0;
        cin>>n>>x;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) sum+=a[i];
        if(sum==x) {cout<<"NO\n"; continue;}
        int psum=0;
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            psum+=a[i];
            if(psum==x) swap(a[i],a[i+1]);
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}