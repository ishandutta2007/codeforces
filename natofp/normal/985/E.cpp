#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int MAX=1000*500+3;

vector<int> prefix(MAX,0);
vector<int> dp(MAX,0);
int suma(int l,int r)
{
    if(l>r) return 0;
    if(l==0) return prefix[r];
    else return prefix[r]-prefix[l-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int n,k,d;
    cin>>n>>k>>d;
    vector <int> a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int l=0;

    dp[0]=1;
    prefix[0]=1;
    for(int i=0;i<n;i++)
    {
         while(l<i && a[i]-a[l]>d) {l++;}
         if(suma(l,i-k+1)!=0) {dp[i+1]=1; prefix[i+1]=prefix[i]+1;}
         else {dp[i+1]=0; prefix[i+1]=prefix[i];}

    }

    if(dp[n]) cout<<"YES";
    else cout<<"NO";

    return 0;
}