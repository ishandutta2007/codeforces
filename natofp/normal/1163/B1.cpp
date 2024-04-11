#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    int * a=new int[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    const int nax=11;
    int t[nax];
    memset(t,0,sizeof t);
    int res=1;
    t[a[1]]++;
    for(int i=2;i<=n;i++)
    {
        t[a[i]]++;
        vector<int> xd;
        for(int j=1;j<=10;j++)
        {
            xd.push_back(t[j]);
        }
        sort(xd.begin(),xd.end());
        int k=0;
        while(xd[k]==0) k++;
        if(k==9) {res=i; continue;}
        if(xd[k]==1 && xd[k+1]==xd[9])
        {
            res=i;
        }
        if(xd[9]-1==xd[8] && xd[9]-1==xd[k]) res=i;
    }
    cout<<res;
    return 0;
}