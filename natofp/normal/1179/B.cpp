#include <iostream>
#include <bits/stdc++.h>

using namespace std;



set<pair<int,int> > xd;
pair<int,int> last;


void debug(int a,int b)
{
    pair<int,int> akt={a,b};
    pair<int,int> lol={a-last.first,b-last.second};
    if(xd.count(lol)>=1)
    {
        cout<<"XD"<<endl;
        cout<<akt.first<<" "<<akt.second<<endl;
        cout<<last.first<<" "<<last.second<<endl;
        cout<<lol.first<<" "<<lol.second<<endl;
        cout<<"XD"<<endl;
    }
    last=akt;
    xd.insert(lol);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n/2;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<i<<" "<<j<<"\n";
            //debug(i,j);
            cout<<n-i+1<<" "<<m-j+1<<"\n";
            //debug(n-i+1,m-j+1);
        }
    }
    if(n%2==1)
    {
        for(int j=1;j<=m/2;j++)
        {
            cout<<(n+1)/2<<" "<<j<<"\n";
            //debug((n+1)/2,j);
            cout<<(n+1)/2<<" "<<m-j+1<<"\n";
            //debug((n+1)/2,m-j+1);
        }
        if(m%2==1)
        {
            cout<<(n+1)/2<<" "<<(m+1)/2<<"\n";
            //debug((n+1)/2,(m+1)/2);
        }
    }
    return 0;
}