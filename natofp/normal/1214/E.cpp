#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<pair<int,int> > a;
vector<pair<int,int> > ans;

const int nax=1e5+5;
vector<int> top[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        a.push_back({x,i});
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        top[i+1].push_back(a[i].second*2);
        if(i>0) ans.push_back({top[i].back(),top[i+1].back()});
    }
    int last=n;
    for(int i=1;i<=n;i++)
    {
        int dis=a[i-1].first;
        int idx=a[i-1].second*2-1;
        int odl=abs(last-i);
        //cout<<i<<" "<<dis<<" "<<odl<<endl;
        if(dis<=odl)
        {
            int kupka;
            if(last>=i)
            kupka=i+dis-1;
            else kupka=i-dis+1;
            ans.push_back({idx,top[kupka][0]});
            if(top[kupka].size()==1) top[kupka].push_back(idx);
            last=kupka;
        }
        else if(dis>odl)
        {
            //cout<<"XD"<<i<<endl;
            dis-=odl;
            if(dis==top[last].size())
            {
                top[last].push_back(idx);
                ans.push_back({top[last][dis-1],top[last][dis]});
            }
            else ans.push_back({idx,top[last][dis-1]});
        }
        //cout<<last<<endl;
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}