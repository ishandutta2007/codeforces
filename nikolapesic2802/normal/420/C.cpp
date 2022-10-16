#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
const int N=3e5+5;
vector<int> Fen(N);
int veci(int x,vector<int>* Sortirano)
{
    int res=(*Sortirano).size()-(lower_bound((*Sortirano).begin(),(*Sortirano).end(),x)-(*Sortirano).begin());
    return res;
}
int main()
{
    int n,p;
    scanf("%i %i",&n,&p);
    vector<vector<int> > graf(n+1);
    vector<int> Sortirano(n);
    map<pair<int,int>,int> broj;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        broj[{a,b}]++;
        broj[{b,a}]++;
        Fen[a]++;
        Fen[b]++;
        Sortirano[a]++;
        Sortirano[b]++;
        if(broj[{a,b}]==1)
        {
            graf[a].pb(b);
            graf[b].pb(a);
        }
    }
    sort(Sortirano.begin(),Sortirano.end());
    /*if(n==3e5)
    {
        printf("%f\n",(double)clock());
        return 0;
    }*/
    ll res=0;
    for(int i=0;i<n;i++)
    {
        int potrebno=p-Fen[i];
        //printf("Za %i potrebno: %i, Fen:%i\n",i+1,potrebno,Fen[i]);
        int tr=veci(potrebno,&Sortirano);
        //printf("Veci: %i\n",tr);
        if(Fen[i]>=potrebno)
        {
            tr--;
            //printf("ODUZEO ZA SEBE!\n");
        }
        for(int j=0;j<graf[i].size();j++)
        {
            int sl=graf[i][j];
            int b=broj[{i,sl}];
           // printf("Gledam za %i broj: %i, Fen: %i\n",sl,b,Fen[sl]);
            if(Fen[sl]>=potrebno&&Fen[sl]<potrebno+b)
            {
                //printf("ODUZEO!\n");
                tr--;
            }
        }
        res+=(ll)tr;
    }
    printf("%lld\n",res/2);
    return 0;
}