#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> dzielniki(int n)
{
    vector<int> ans;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0) ans.push_back(i);
        if(i*i!=n && n%i==0)
        {
            ans.push_back(n/i);
        }
    }
    return ans;
}

int main()
{
    int n; cin>>n;
    vector<int> a=dzielniki(n);
    vector<long long int> ans;
    for(int i=0;i<a.size();i++)
    {
        long long int d=a[i];
        long long int x=n/d;
        long long int w=0;
        w+=n/d;
        w+=d*(x)*(x-1)/2;
        ans.push_back(w);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}