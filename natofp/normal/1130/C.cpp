#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=55;
char plansza[N][N];
bool czy[N][N];
int nr=3;
int n;
queue<pair<int,int> > kolejka;

void zrob(int x,int y)
{
    if(x<1 || x>n || y<1 || y>n) return;
    if(czy[x][y]==true) return;
    if(plansza[x][y]=='1') return;
    czy[x][y]=true;
    plansza[x][y]=(48+nr);
    kolejka.push({x,y});
}

int main()
{
    cin>>n;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>plansza[i][j];
            czy[i][j]=false;
        }
    }
    kolejka.push({x1,y1});
    czy[x1][y1]=true;
    plansza[x1][y1]=(48+nr);
    while(kolejka.empty()==false)
    {
        pair<int,int> a=kolejka.front();
        kolejka.pop();
        int x=a.first;
        int y=a.second;
        zrob(x-1,y);
        zrob(x+1,y);
        zrob(x,y-1);
        zrob(x,y+1);
    }
    if(plansza[x2][y2]=='3') {cout<<0; return 0;}
    nr=4;
    kolejka.push({x2,y2});
    czy[x2][y2]=true;
    plansza[x2][y2]=(48+nr);
    while(kolejka.empty()==false)
    {
        pair<int,int> a=kolejka.front();
        kolejka.pop();
        int x=a.first;
        int y=a.second;
        zrob(x-1,y);
        zrob(x+1,y);
        zrob(x,y-1);
        zrob(x,y+1);
    }
    vector<pair<int,int> > idx1;
    vector<pair<int,int> > idx2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(plansza[i][j]=='3') idx1.push_back({i,j});
            else if(plansza[i][j]=='4') idx2.push_back({i,j});
        }
    }
    int ans=1e9;
    for(int i=0;i<idx1.size();i++)
    {
        for(int j=0;j<idx2.size();j++)
        {
            int x1,y1,x2,y2;
            x1=idx1[i].first;
            y1=idx1[i].second;
            x2=idx2[j].first;
            y2=idx2[j].second;
            ans=min(ans,(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }
    }
    cout<<ans;
    return 0;
}