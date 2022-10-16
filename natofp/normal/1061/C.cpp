#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int mod=1000000007;

vector<int> dzielniki(int n)
{
    vector<int> ans;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans.push_back(i);
            if(i*i!=n) ans.push_back(n/i);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<long long int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        int t=a[i-1];
        vector<int> czynniki=dzielniki(t);
        for(int j=czynniki.size()-1;j>=0;j--)
        {
            if(czynniki[j]>i) continue;
            int k=czynniki[j];
            dp[k]+=dp[k-1];
            dp[k]%=mod;
        }
    }
    long long int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=dp[i];
        sum%=mod;
    }
    cout<<sum;
    return 0;
}