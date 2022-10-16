#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2005;
char p[nax][nax];
char ma[nax][nax];
int n,m;
vector<pair<int,int> > pos[26];

struct snake
{
    int x1,y1,x2,y2;
};

snake xd[26];

void debug()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cout<<ma[i][j];
        cout<<endl;
    }
}

bool ok(int idx)
{
    sort(pos[idx].begin(),pos[idx].end());
    if(pos[idx].size()==1)
    {
        snake nowy;
        nowy.x1=nowy.x2=pos[idx][0].first;
        nowy.y2=nowy.y2=pos[idx][0].second;
    }
    pair<int,int> first,last;
    first=pos[idx][0];
    last=pos[idx].back();
    if(first.first!=last.first && first.second!=last.second)
    {
        return false;
    }
    snake nowy;
    nowy.x1=first.first;
    nowy.y1=first.second;
    nowy.x2=last.first;
    nowy.y2=last.second;
    xd[idx]=nowy;
    return true;
}

void rysuj(int idx)
{
    snake akt=xd[idx];
    int x1,x2,y1,y2;
    x1=akt.x1;
    x2=akt.x2;
    y1=akt.y1;
    y2=akt.y2;
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1;j<=y2;j++)
        {
            ma[i][j]=('a'+idx);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        for(int i=0;i<26;i++) pos[i].clear();
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>p[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(p[i][j]!='.')
                {
                    pos[p[i][j]-'a'].push_back({i,j});
                }
            }
        }
        bool xxx=true;
        for(int i=0;i<26;i++)
        {
            if(pos[i].size()>=1)
            {
                xxx=ok(i);
                if(xxx==false)
                {
                    cout<<"NO"<<"\n";
                    break;
                }
            }

        }
        if(xxx==false) continue;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                ma[i][j]='.';
            }
        }
        for(int i=0;i<26;i++)
        {
            if(pos[i].size()==0) continue;
            rysuj(i);
        }
        for(int i=1;i<=n;i++)
        {
            if(xxx==false) break;
            for(int j=1;j<=m;j++)
            {
                if(p[i][j]!=ma[i][j])
                {
                    xxx=false;
                    cout<<"NO"<<"\n";
                    break;
                }
            }
        }
        if(xxx==false) continue;
        cout<<"YES"<<"\n";
        int ile=0;
        int last=-1;
        for(int i=0;i<26;i++)
        {
            if(pos[i].size()>=1)
            {
                ile++;
                last=i;
            }
        }
        cout<<last+1<<"\n";
        for(int i=0;i<26;i++)
        {
            if(pos[i].size()>=1)
            {
                snake akt=xd[i];
                cout<<akt.x1<<" "<<akt.y1<<" "<<akt.x2<<" "<<akt.y2<<"\n";
            }
            else if(i<last)
            {
                cout<<xd[last].x1<<" "<<xd[last].y1<<" "<<xd[last].x2<<" "<<xd[last].y2<<"\n";
            }
        }
    }
    return 0;
}