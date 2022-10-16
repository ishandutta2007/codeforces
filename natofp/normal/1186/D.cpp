#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<double> a;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        double x; cin>>x;
        a.push_back(x);
    }
    long long minsum=0;
    long long maxsum=0;
    for(int i=0;i<n;i++)
    {
        maxsum+=ceil(a[i]);
    }
    //cout<<maxsum<<endl;
    for(int i=0;i<n;i++)
    {
        if(maxsum==0)
        {
            if(ceil(a[i])==0) cout<<0<<"\n";
            else cout<<ceil(a[i])<<"\n";
        }
        else
        {
            if(floor(a[i])!=ceil(a[i]))
            {
                if(floor(a[i])==0) cout<<0<<"\n";
                else cout<<floor(a[i])<<"\n";
                maxsum--;
                //cout<<"XD"<<endl;
            }
            else
            {
                if(ceil(a[i])==0) cout<<0<<"\n";
                else cout<<ceil(a[i])<<"\n";
            }
        }
    }
    return 0;
}