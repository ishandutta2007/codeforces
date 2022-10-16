#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<pair<int,int> > blokady;

int ile=0;
int n,m;
void wykoncz()
{
    while(blokady.size()>0)
    {
        int x=blokady[blokady.size()-1].first;
        int y=blokady[blokady.size()-1].second;
        blokady.pop_back();
        if(a[x-1]>=a[y-1])
        {
            cout<<x<<endl;
            fflush(stdout);
        }
        else
        {
            cout<<y<<endl;
            fflush(stdout);
        }
        a[x-1]=-1;
        a[y-1]=-1;
        ile+=2;
        int c; cin>>c;
    }
    while(ile<2*n)
    {
        int naj=-1;
        int idx=-1;
        for(int i=0;i<2*n;i++)
        {
            if(a[i]>naj) {naj=a[i]; idx=i;}
        }
        a[idx]=-1;
        cout<<idx+1<<endl;
        fflush(stdout);
        ile++;
        if(ile<2*n)
        {
            int c; cin>>c;
            a[c-1]=-1;
            ile++;
        }
    }

}

int main()
{

    cin>>n>>m;
    for(int i=0;i<2*n;i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        int x,y; cin>>x>>y;
        blokady.push_back(make_pair(x,y));
    }
    int t; cin>>t;
    if(t==1) wykoncz();
    else
    {
        while(1)
        {
        int c; cin>>c;
        a[c-1]=-1;
        ile++;
        bool xd=false;
        for(int i=0;i<blokady.size();i++)
        {
            if(c==blokady[i].first)
            {
                cout<<blokady[i].second<<endl;
                fflush(stdout);
                a[blokady[i].second-1]=-1;
                
                ile++;
                blokady.erase(blokady.begin()+i);
                xd=true;
            }
            else if(c==blokady[i].second)
            {
                cout<<blokady[i].first<<endl;
                fflush(stdout);
                a[blokady[i].first-1]=-1;
                
                blokady.erase(blokady.begin()+i);
                ile++;
                xd=true;
            }
        }
        if(xd==false) break;
        }
        wykoncz();
    }
    return 0;
}