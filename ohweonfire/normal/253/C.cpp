#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>
#include <limits>
#include <stack>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#define ff first
#define ss second
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,m,n) for(int i=m;i<=n;i++)
#define all(i,j) for(i::iterator it=j.begin;it!=j.end;it++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<ll> sll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int d[101][100001];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(d,-1,sizeof(d));
    int a[111];
    int sx,sy,fx,fy;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i],a[i]++;}
    cin>>sx>>sy>>fx>>fy;
    queue<pii>q;
    q.push(make_pair(sx,sy));
    d[sx][sy]=0;
    while(!q.empty())
    {
                      pii u=q.front();
                      q.pop();
                      int x=u.ff,y=u.ss;
                      for(int i=0;i<4;i++)
                      {
                              int xx=x+dx[i],yy=min(a[xx],y+dy[i]);
                              if(xx&&yy&&xx<=n&&yy<=a[xx]&&d[xx][yy]<0)
                              {d[xx][yy]=d[x][y]+1;q.push(make_pair(xx,yy));}
                      }
    }
    cout<<d[fx][fy]<<endl;
    return 0;
}