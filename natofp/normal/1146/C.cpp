#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int res=0;
        int n; cin>>n;
        int akt=1;
        for(int i=0;i<9;i++)
        {
            if(akt>n) break;
            vector<int> a;
            vector<int> b;
            for(int j=1;j<=n;j++)
            {
                if(j&akt) a.push_back(j);
                else b.push_back(j);
            }
            cout<<a.size()<<" "<<b.size()<<" ";
            for(int k=0;k<a.size();k++) cout<<a[k]<<" ";
            for(int k=0;k<b.size();k++) cout<<b[k]<<" ";
            cout<<endl;
            fflush(stdout);
            int wyn; cin>>wyn;
            res=max(res,wyn);
            akt*=2;
        }
        cout<<"-1"<<" "<<res<<endl;
        fflush(stdout);
    }
    return 0;
}