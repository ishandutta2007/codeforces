#include <bits/stdc++.h>
using namespace std;
int a[100007];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        for(int i=0;i<n;i++) cin>>a[i];
        bool fas=false;
        for(int i=0;i<n;i++) if(a[i]==x) {cout<<1<<endl; fas=true;}
        if(fas) continue;
        sort(a,a+n);
        cout<<max((x+a[n-1]-1)/a[n-1],2)<<endl;
    }
}