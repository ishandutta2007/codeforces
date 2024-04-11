#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,n,m,i,j,k,t,x,y,z,res=0;
vector <ll> mons;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (k=1;k<=t;k++)
    {
        cin>>n>>m;
            res=0;
            mons.clear();
        for (i=1;i<=n;i++) {cin>>x; mons.push_back(x);}
        sort(mons.begin(),mons.end());
        for (i=0;i<mons.size()-1;) if ((mons[i]==mons[i+1])) mons.erase(mons.begin()+i); else i++;
        n=mons.size();
        for (i=0;i<n;i++)
        {
            x=((mons[i]-1)/m)+1;
            y=n-i;
            if (x<y) z=x; else z=y;
            if (res<z) res=z;
        }
        cout<<res<<endl;
    }
}