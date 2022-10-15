#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,x,y,res=0;
char a[2005][2005];
bool mapp[2005][2005];
struct A
{
    int n,m,l,r;
};
deque <A> q;
void bf(int n,int m,int l,int r,bool b)
{
    if(a[n][m]=='.' and !mapp[n][m] and l<=x and r<=y)
    {
        mapp[n][m]=true;
        if(b) q.push_back(A{n,m,l,r});
        else q.push_front(A{n,m,l,r});
    }
}
int main ()
{
    cin>>n>>m>>r>>c>>x>>y;
    r--;
    c--;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            mapp[i][j]=false;
        }
    }
    q.push_front(A{r,c,0,0});
    mapp[r][c]=true;
    while(q.size()>0)
    {
        A b=q.front();
        q.pop_front();
        res++;
        bf(b.n+1,b.m,b.l,b.r,false);
        bf(b.n-1,b.m,b.l,b.r,false);
        bf(b.n,b.m+1,b.l,b.r+1,true);
        bf(b.n,b.m-1,b.l+1,b.r,true);
    }
    cout<<res<<endl;
}