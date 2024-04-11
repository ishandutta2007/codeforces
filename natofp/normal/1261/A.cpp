#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string s;

void odw(int lo,int hi)
{
    int ile=hi-lo+1;
    for(int i=0;i<ile/2;i++)
    {
        swap(s[lo+i],s[hi-i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        int n,k; cin>>n>>k;
        cin>>s;
        string res;
        int xd=0;
        for(int i=0;i<k-1;i++)
        {
            xd+=2;
            res+="()";
        }
        xd=n-xd;
        for(int i=0;i<xd/2;i++) res+="(";
        for(int i=0;i<xd/2;i++) res+=")";
        vector<pair<int,int> > ans;
        int ile=0;
        for(int i=0;i<n;i++)
        {
            //cout<<i<<" "<<s<<" "<<res<<endl;
            if(s[i]==res[i]) continue;
            char akt=res[i];
            int idx;
            for(int j=i+1;j<n;j++)
            {
                if(s[j]==akt)
                {
                    idx=j; break;
                }
            }
            ans.push_back({i+1,idx+1});
            odw(i,idx);
        }
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }
    }
    return 0;
}