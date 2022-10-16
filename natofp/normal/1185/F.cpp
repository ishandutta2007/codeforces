#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=(1<<9)+5;
int n,m;
int full_mask=(1<<9)-1;
int osoby[nax];
vector<pair<int,int> > pizza[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    memset(osoby,0,sizeof osoby);
    for(int i=1;i<=n;i++)
    {
        int f; cin>>f;
        int mask_akt=0;
        for(int j=0;j<f;j++)
        {
            int x; cin>>x;
            mask_akt|=(1<<(x-1));
        }
        int odw=full_mask&(~mask_akt);
        int s=odw;
        while(odw>0)
        {
            osoby[odw|mask_akt]++;
            odw=(odw-1)&s;
        }
        osoby[odw|mask_akt]++;
    }
    for(int i=1;i<=m;i++)
    {
        //cout<<i<<endl;
        int mask_akt=0;
        int c; cin>>c;
        int f; cin>>f;
        for(int j=0;j<f;j++)
        {
            int x; cin>>x;
            mask_akt|=(1<<(x-1));
        }
        pizza[mask_akt].push_back({c,i});
    }
    for(int i=0;i<=full_mask;i++)
    {
        sort(pizza[i].begin(),pizza[i].end());
    }
    int max_osoby=0;
    int min_cost=2e9+1;
    int idx1,idx2;
    for(int i=1;i<=full_mask;i++)
    {
        for(int j=i;j<=full_mask;j++)
        {
            int maska=(i|j);
            if(i==j)
            {
                maska=i;
            }
            if(i!=j && pizza[i].size()>=1 && pizza[j].size()>=1)
            {
                int ile=osoby[maska];
                int cost=pizza[i][0].first+pizza[j][0].first;
                if(ile>max_osoby)
                {
                    max_osoby=ile;
                    min_cost=cost;
                    idx1=pizza[i][0].second;
                    idx2=pizza[j][0].second;
                    continue;
                }
                else if(ile==max_osoby)
                {
                    if(cost<min_cost)
                    {
                        max_osoby=ile;
                        min_cost=cost;
                        idx1=pizza[i][0].second;
                        idx2=pizza[j][0].second;
                        continue;
                    }
                }
            }
            else if(i==j)
            {
                if(pizza[i].size()>=2)
                {
                    int ile=osoby[maska];
                    int cost=pizza[i][0].first+pizza[i][1].first;
                    if(ile>max_osoby)
                    {
                        max_osoby=ile;
                        min_cost=cost;
                        idx1=pizza[i][0].second;
                        idx2=pizza[i][1].second;
                        continue;
                    }
                    else if(ile==max_osoby)
                    {
                        if(cost<min_cost)
                        {
                            max_osoby=ile;
                            min_cost=cost;
                            idx1=pizza[i][0].second;
                            idx2=pizza[i][1].second;
                            continue;
                        }
                    }
                }
            }
        }
    }
    cout<<idx1<<" "<<idx2<<endl;
    return 0;
}