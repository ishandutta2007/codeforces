#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n; cin>>n;
    vector<int> odd;
    vector<int> even;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        if(x%2==0) even.push_back(x);
        else odd.push_back(x);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    int ans=1e9;
    int k=odd.size();
    k=min(k,(int(even.size())));
    int sum=0;
    for(int i=0;i<even.size();i++) sum+=even[i];
    for(int i=0;i<odd.size();i++) sum+=odd[i];
    int res=0;
    for(int i=odd.size()-1;i>=(int)odd.size()-k;i--)
    {

        res+=odd[i];
    }
    for(int i=even.size()-1;i>=(int)even.size()-k;i--)
    {

        res+=even[i];
    }
    if(odd.size()==even.size()) ;
    else if(odd.size()>even.size())
    {
        res+=odd[odd.size()-1-k];
    }
    else res+=even[even.size()-1-k];
    cout<<sum-res;
    return 0;
}