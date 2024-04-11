#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
vector<vector<int> > graf;
vector<int> sol;
void solve(int tr)
{
    for(auto p:graf[tr])
    {
        if(sol[p]==0)
            solve(p);
        if(sol[p]==-1)
        {
            sol[tr]=1;
            return;
        }
    }
    sol[tr]=-1;
}
int main()
{
    int n;
    scanf("%i",&n);
    vector<int> niz(n);
    graf.resize(n);
    sol.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+niz[i];j<n;j+=niz[i])
        {
            if(niz[i]<niz[j])
            {
                //printf("Od %i do %i\n",i,j);
                graf[i].pb(j);
            }
        }
        for(int j=i-niz[i];j>=0;j-=niz[i])
        {
            if(niz[i]<niz[j])
            {
                //printf("Od %i do %i\n",i,j);
                graf[i].pb(j);
            }
        }
    }
    for(int i=0;i<n;i++)
        if(sol[i]==0)
            solve(i);
    for(int i=0;i<n;i++)
    {
        if(sol[i]==-1)
        {
            printf("B");
        }
        else
        {
            printf("A");
        }
    }
    return 0;
}