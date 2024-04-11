#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int tab[100007];
int cut[100007];
int last[100007];
vector <int> cuts[100007];
set <pair<int,int> > kolejka;

int c(int a)
{
    return a*a;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,k,ans=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=1;i<=n;i++)
        {
            cut[i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(tab[i]!=1)
            {
                kolejka.insert({c(tab[i])-c(tab[i]/2)-c(tab[i]/2+tab[i]%2),i});
               // cout<<c(tab[i])<<" "<<c(tab[i]/2+tab[i]%2)+c(tab[i]/2)<<endl;
            }
            last[i]=c(tab[i]);
        }
        for(int i=0;i<k-n;i++)
        {
            pair<int,int> pr=*--kolejka.end();
            kolejka.erase(pr);
            cut[pr.nd]++;
            int x=cut[pr.nd];
            int a1=c(tab[pr.nd]/x)*((x-tab[pr.nd]%x))+c(tab[pr.nd]/x+1)*(tab[pr.nd]%x);
            last[pr.nd]=a1;
            if(cut[pr.nd]+1<=tab[pr.nd])
            {
                x++;
                int a2=c(tab[pr.nd]/x)*((x-tab[pr.nd]%x))+c(tab[pr.nd]/x+1)*(tab[pr.nd]%x);
                kolejka.insert({a1-a2,pr.nd});
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans+=last[i];
            //cout<<last[i]<<" ";
        }
        //cout<<endl;
        cout<<ans<<endl;
    }

    return 0;
}