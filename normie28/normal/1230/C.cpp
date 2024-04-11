#include <iostream>
#include <vector>
using namespace std;
#define ll long long
ll a,b,n,m,i,j,num[8],maxx=0,used[22];
struct edge {ll x; ll y;};
vector <edge> all; edge h;
const edge dom[22]={{0,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{2,2},{2,3},{2,4},{2,5},{2,6},{3,3},{3,4},{3,5},{3,6},{4,4},{4,5},{4,6},{5,5},{5,6},{6,6}};
void check() { ll sum=0;
    for (ll ii=1;ii<=21;ii++) used[ii]=0;
    for (ll ii=0;ii<all.size();ii++) {for (ll jj=1;jj<=21;jj++) 
    if (((dom[jj].x==num[all[ii].x])and(dom[jj].y==num[all[ii].y]))or((dom[jj].x==num[all[ii].y])and(dom[jj].y==num[all[ii].x])))
    if (!used[jj]) used[jj]=1;
    }
    for (ll ii=1;ii<=21;ii++) sum+=used[ii];
    if (maxx<sum) maxx=sum;
}
void tri(ll no)
{
    if (no==n) check();
    else for (ll ii=1;ii<=6;ii++) {num[no+1]=ii; tri(no+1); num[no+1]=0;}
}
int main()
{
	maxx=0;
    cin>>n>>m;
    for (i=1;i<=m;i++) {cin>>h.x>>h.y; all.push_back(h);}
    tri(0);
    cout<<maxx;
}