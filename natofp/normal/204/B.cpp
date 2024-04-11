#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> a;
set<int> s;
vector<pair<int,int> > tab;

int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        if(x==y) a[x]++;
        else
        {
            a[x]++;
            a[y]++;
        }
        s.insert(x);
        s.insert(y);
        tab.push_back({x,y});
    }
    int ans=1e9;
    set<int>::iterator it;
    it=s.begin();
    while(it!=s.end())
    {
        int val=*it;
        it++;
        if(a[val]*2<n) continue;
        int down=0;
        int up=0;
        int ok=0;
        for(int i=0;i<n;i++)
        {
            if(tab[i].first==val) down++;
        }
        int ile=(n+1)/2;
        ile-=ok;
        if(down>=ile) {ans=0; continue;}
        ans=min(ans,ile-down);
    }
    if(ans==1e9) cout<<-1;
    else cout<<ans;
    return 0;
}