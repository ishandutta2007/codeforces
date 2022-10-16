#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
const int N=1e5+5;
int n,L;
ll S;
vector<int> w(N),dubina(N),listovi;
vector<vector<int> > graf(N);
vector<int> po[N];
pair<int,ll> up[N][21];
void dfs(int tr)
{
    po[dubina[tr]].pb(tr);
    for(int i=0;i<graf[tr].size();i++)
    {
        int sl=graf[tr][i];
        if(sl!=up[tr][0].first)
        {
            dubina[sl]=dubina[tr]+1;
            dfs(sl);
        }
    }
}
vector<int> duzina(N);
vector<ll> tezina(N);
ll travel(int tr,int l)
{
    ll put=0;
    if(l>dubina[tr])
        return LLONG_MAX;
    for(int j=19;j>=0;j--)
    {
        if(l-(1<<j)>=0)
        {
            //printf("Usao za %i: %i %i\n",j,l,1<<j);
            put+=up[tr][j].second;
            tr=up[tr][j].first;
            l-=(1<<j);
        }
    }
    return put;
}
int br=0;
void izracunaj(int tr)
{
    //printf("Pozvan za %i\n",tr);
    if(graf[tr].size()==1&&tr!=1)
    {
        //printf("Base case!\n");
        br++;
        duzina[tr]=1;
        tezina[tr]=w[tr];
        if(tezina[tr]>S)
        {
            printf("-1\n");
            exit(0);
        }
        return;
    }
    int koji;
    int maxx=0;
    for(int i=0;i<graf[tr].size();i++)
    {
        int sl=graf[tr][i];
        if(sl!=up[tr][0].first)
        {
            //printf("Sledeci: %i\n",sl);
            ll limit=S-tezina[sl];
            int d=L-duzina[sl];
            //printf("Limit: %lld, duzina;%i\n",limit,d);
            int duz=0;
            int t=sl;
            for(int j=19;j>=0;j--)
            {
                //printf("Gledam za %i\n",j);
                if((1<<j)<=d&&up[t][j].second<=limit)
                {
                    //printf("Usao!\n");
                    d-=(1<<j);
                    duz+=(1<<j);
                    limit-=up[t][j].second;
                    t=up[t][j].first;
                }
            }
            if(duz>maxx)
            {
                maxx=duz;
                koji=sl;
            }
        }
    }
    if(maxx==0)
    {
        duzina[tr]=1;
        tezina[tr]=w[tr];
        br++;
        if(tezina[tr]>S)
        {
            printf("-1\n");
            exit(0);
        }
        return;
    }
    duzina[tr]=duzina[koji]+1;
    tezina[tr]=tezina[koji]+w[tr];
    assert(duzina[tr]<=L&&tezina[tr]<=S);
}
int main()
{
    scanf("%i %i %lld",&n,&L,&S);
    for(int i=0;i<n;i++)
    {
        scanf("%i",&w[i+1]);
    }
    up[1][0]=make_pair(-1,LLONG_MAX);
    for(int i=1;i<n;i++)
    {
        int p;
        scanf("%i",&p);
        graf[p].pb(i+1);
        graf[i+1].pb(p);
        up[i+1][0]=make_pair(p,w[p]);
    }
    for(int j=1;j<20;j++)
    {
        for(int i=1;i<=n;i++)
        {
            pair<int,int> mid=up[i][j-1];
            if(mid.first==-1)
            {
                up[i][j]=up[i][j-1];
            }
            else
            {
                if(up[mid.first][j-1].second==LLONG_MAX)
                {
                    up[i][j]=up[mid.first][j-1];
                }
                else
                    up[i][j]=make_pair(up[mid.first][j-1].first,up[mid.first][j-1].second+up[i][j-1].second);
            }
        }
    }
    dfs(1);
    /*while(true)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        printf("%lld\n",travel(a,b));
    }*/
    for(int i=n;i>=0;i--)
    {
        //printf("\nDubina %i:\n",i);
        for(int j=0;j<po[i].size();j++)
        {
            izracunaj(po[i][j]);
        }
    }
    printf("%i\n",br);
    return 0;
}