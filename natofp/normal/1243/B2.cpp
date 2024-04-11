#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int ile[26];

string ss,tt;



int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        cin>>ss>>tt;
        for(int i=0;i<26;i++) ile[i]=0;
        for(int i=0;i<n;i++)
        {
            ile[ss[i]-'a']++;
            ile[tt[i]-'a']++;
        }
        bool ok = true;
        for(int i=0;i<26;i++)
        {
            if(ile[i]%2!=0)
            {
                cout<<"No"<<endl;
                ok = false; break;
            }
        }
        if(ok == false)
        {
            continue;
        }
        cout<<"Yes"<<endl;
        vector<pair<int,int> > ans;
        for(int i=0;i<n;i++)
        {
            if(ss[i]==tt[i]) continue;
            for(int j=i+1;j<n;j++)
            {
                if(tt[j]==ss[i])
                {
                    ans.push_back({j,j});
                    swap(tt[j],ss[j]);
                    break;
                }
            }
            for(int j=i+1;j<n;j++)
            {
                if(ss[j]==ss[i])
                {
                    ans.push_back({j,i});
                    swap(ss[j],tt[i]);
                    break;
                }
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
        }

    }
    return 0;
}