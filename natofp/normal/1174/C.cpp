#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=1e5+5;
vector<bool> czy(nax,true);
vector<int> dzielnik(nax,0);
unordered_map<int,int> xd;
void pre()
{
    for(int i=2;i<nax;i++)
    {
        if(czy[i]==false) continue;
        else
        {
            for(int j=i*2;j<nax;j+=i)
            {
                czy[j]=false;
            }
            for(int j=i;j<nax;j+=i)
            {
                dzielnik[j]=i;
            }
        }
    }
}

int main()
{
    int n; cin>>n;
    pre();
    vector<int> lista;
    int ile=1;
    for(int i=1;i<=n;i++)
    {
        if(czy[i]==true) {lista.push_back(i);
        xd[i]=ile;
        ile++;}
    }
    for(int i=2;i<=n;i++)
    {
        int t=dzielnik[i];
        cout<<xd[t]-1<<" ";
    }
    return 0;
}