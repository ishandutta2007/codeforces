#include <bits/stdc++.h>

using namespace std;

bool prime[200007];
vector <pair<int,int> >czynniki[200007];
vector <int> pierwsze;
pair<int,int> ile[200007];
int times[200007];


int main()
{
    for(int i=2;i<=200000;i++)
    {
        if(!prime[i])
        {
            pierwsze.push_back(i);
            czynniki[i].push_back(make_pair(i,1));
            for(int j=2*i;j<=200000;j+=i)
            {
                prime[j]=1;
                int a=j,ile=0;
                while(a%i==0)
                {
                    ile++;
                    a/=i;
                }
                czynniki[j].push_back(make_pair(i,ile));
            }
        }
    }
    int n;
    cin>>n;
    int tab[n];
    for(int i=0;i<n;i++) cin>>tab[i];
    int p,d;
    for(int i=0;i<=200000;i++)
    {
        ile[i].first=1000000006;
        ile[i].second=1000000007;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<czynniki[tab[i]].size();j++)
        {
            p=czynniki[tab[i]][j].first;
            times[p]++;
            d=czynniki[tab[i]][j].second;
            if(d<=ile[p].first)
            {
                ile[p].second=ile[p].first;
                ile[p].first=d;
            }
            else if(d<=ile[p].second) ile[p].second=d;
        }
    }
    long long res=1;
    for(int i=2;i<=200000;i++)
    {
        if(times[i]==n-1) res*=(long long)pow((long long)i,(long long)ile[i].first);
        else if(times[i]==n) res*=(long long)pow((long long)i,(long long)ile[i].second);
    }
    cout<<res;
    return 0;
}