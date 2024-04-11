#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=105;
int a[nax];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        vector<int> b;
        for(int j=1;j<i;j++) b.push_back(a[j]);
        sort(b.begin(),b.end());
        int sum=0;
        for(int j=0;j<b.size();j++) sum+=b[j];
        int sz=b.size()-1;
        int ile=0;
        while(sum>m-a[i])
        {
            ile++;
            sum-=b[sz];
            sz--;
        }
        cout<<ile<<" ";
    }
    return 0;
}