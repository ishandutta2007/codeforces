#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;

int tab[200007];
bool is[200007];

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
        vector <int> vec;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=1;i<=n;i++)
        {
            cin>>is[i];
            if(!is[i]) vec.push_back(tab[i]);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        int it=0;
        for(int i=1;i<=n;i++)
        {
            if(!is[i]) tab[i]=vec[it++];
            cout<<tab[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}