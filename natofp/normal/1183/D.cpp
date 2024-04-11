#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;
int ile[nax];
bool czy[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(ile,0,sizeof ile);
    memset(czy,0,sizeof czy);
    int q; cin>>q;
    vector<int> a;
    while(q--)
    {
        int n; cin>>n;
        a.clear();
        for(int i=0;i<n;i++)
        {
            int x; cin>>x;
            ile[x]++;
            if(czy[x]==false)
            {
                a.push_back(x);
            }
            czy[x]=true;
        }
        vector<int> ziomki;
        for(int i=0;i<a.size();i++)
        {
            int val=a[i];
            ziomki.push_back(ile[val]);
            ile[val]=0;
            czy[val]=false;
        }
        sort(ziomki.begin(),ziomki.end());
        reverse(ziomki.begin(),ziomki.end());
        int last=1e9;
        int res=0;
        for(int i=0;i<ziomki.size();i++)
        {
            int akt=ziomki[i];
            akt=min(last-1,akt);
            akt=max(0,akt);
            res+=akt;
            last=akt;
        }
        cout<<res<<"\n";
    }
    return 0;
}