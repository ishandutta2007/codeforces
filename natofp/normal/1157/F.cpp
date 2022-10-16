#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n; cin>>n;
    vector<int> res;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    const int nax=2e5+5;
    int t[nax];
    memset(t,0,sizeof t);
    for(int i=0;i<n;i++)
    {
        t[a[i]]++;
    }
    int start,meta;
    bool ok;
    for(int i=1;i<nax;i++)
    {
        ok = false;
        if(t[i]>=1)
        {
            start=i;
            int j=i+1;
            while(t[j]>=2) j++;
            meta=j;
            i=j-1;
            ok = true;
        }
        if(ok)
        {
            vector<int> alt;
            for(int j=0;j<t[start];j++) alt.push_back(start);
            for(int k=start+1;k<meta;k++)
            {
                for(int j=0;j<t[k]-1;j++) alt.push_back(k);
            }
            for(int j=0;j<t[meta];j++) alt.push_back(meta);
            for(int k=meta-1;k>start;k--) alt.push_back(k);
            if(alt.size()>res.size()) res=alt;
        }

    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    return 0;
}