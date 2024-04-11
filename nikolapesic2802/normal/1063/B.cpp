#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
const int N=2005;
int visited[N][N];
int cnt;
int L,R,n,m;
queue<pair<pair<int,int> ,pair<int,int> > > q;
void update(int x,int y,int l,int r)
{
    if(x>=0&&x<n&&y>=0&&y<m&&(visited[x][y]==0||visited[x][y]==2))
    {
        if(y>0&&visited[x][y-1]==0)
        {
            q.push({{x,y-1},{l+1,r}});
            visited[x][y-1]=2;
        }
        if(y<m-1&&visited[x][y+1]==0)
        {
            q.push({{x,y+1},{l,r+1}});
            visited[x][y+1]=2;
        }
        visited[x][y]=1;
        if(l<=L&&r<=R)
        {
            cnt++;
        }
        update(x-1,y,l,r);
        update(x+1,y,l,r);
    }
}
int main()
{
    int sx,sy;
    scanf("%i %i %i %i %i %i",&n,&m,&sx,&sy,&L,&R);
    sx--;
    sy--;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        for(int j=0;j<m;j++)
            if(s[j]=='*')
                visited[i][j]=1;
    }
    visited[sx][sy]=2;
    q.push({{sx,sy},{0,0}});
    while(!q.empty())
    {
        pair<pair<int,int> ,pair<int,int> > p=q.front();
        q.pop();
        update(p.first.first,p.first.second,p.second.first,p.second.second);
    }
    printf("%i\n",cnt);
    return 0;
}