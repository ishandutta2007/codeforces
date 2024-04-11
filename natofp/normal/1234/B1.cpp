#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

unordered_map<int,int> xd;
int ans[222222];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin>>n>>k;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    int ile=0;
    int wsk=0;
    for(int i=0;i<n;i++)
    {
        int akt=a[i];
        if(xd[akt]==0)
        {
            xd[akt]=1;
            if(ile<k)
            {
                ans[++ile]=akt;
            }
            else
            {
                wsk++;
                ans[wsk+k]=akt;
                xd[ans[wsk]]=0;
            }
        }
    }
    cout<<ile<<endl;
    for(int i=wsk+ile;i>wsk;i--) cout<<ans[i]<<" ";
    return 0;
}