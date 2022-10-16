#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=3e5+5;
int pozycja[nax];
int a[nax];
vector<pair<int,int> > ruchy;

void zamien(int idx1,int idx2)
{
    int val1=a[idx1];
    int val2=a[idx2];
    swap(a[idx1],a[idx2]);
    swap(pozycja[val1],pozycja[val2]);
    ruchy.push_back({min(idx1,idx2),max(idx1,idx2)});
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        pozycja[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<" "<<ruchy.size()<<endl;
        int poz=pozycja[i];
        if(poz==i) continue;
        if(abs(i-poz)*2>=n)
        {
            zamien(i,poz);
            continue;
        }
        else
        {
            if(i<=n/2 && poz<=n/2)
            {
                zamien(poz,n);
                zamien(i,n);
                continue;
            }
            else if(i<=n/2 && poz>n/2)
            {
                int akt=poz;
                zamien(akt,1);
                zamien(1,n);
                zamien(i,n);
                zamien(1,akt);
                continue;
            }
            else if(i>n/2 && poz>n/2)
            {
                 zamien(1,poz);
                 zamien(1,i);
                 continue;
            }
        }
    }
    cout<<ruchy.size()<<endl;
    for(int i=0;i<ruchy.size();i++)
    {
        cout<<ruchy[i].first<<" "<<ruchy[i].second<<"\n";
    }
    return 0;
}