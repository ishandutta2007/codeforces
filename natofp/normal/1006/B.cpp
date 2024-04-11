#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ile[2222];

int main()
{
    memset(ile,0,sizeof ile);
    int n,k; cin>>n>>k;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int * b=new int[n];
    for(int i=0;i<n;i++) b[i]=a[i];
    sort(b,b+n);
    for(int i=n-1;i>=n-k;i--) ile[b[i]]++;
    vector<int> res;
    int ans=0;
    int akt=0;
    for(int i=0;i<n;i++)
    {
        akt++;
        if(ile[a[i]]>0)
        {
            ans+=a[i];
            res.push_back(akt);
            akt=0;
            ile[a[i]]--;
        }
    }
    cout<<ans<<endl;
    int suma=0;
    for(int i=0;i<res.size()-1;i++)
    {
        cout<<res[i]<<" ";
        suma+=res[i];
    }
    cout<<max(n-suma,res[k-1]);

    return 0;
}