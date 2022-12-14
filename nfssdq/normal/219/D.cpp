#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <locale>
#include <vector>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <functional>

using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX/2
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())
vector<int>vc[200001],vv[200001];
int ar[200001],pnt[200001],vis[200001],fin[200001];
void dfs(int id,int pr)
{
    int a,b,c,d,e,f,g,h,x,y,z;
    pnt[id]=pr;
    vis[id]=1;
    for(x=0;x<vc[id].size();x++)
    {
        if(vis[vc[id][x]]==0)
        {
            //cout<<id<<" "<<vc[id][x]<<" "<<vv[id][x]<<endl;
            dfs(vc[id][x],id);
            ar[id]+=vv[id][x]+ar[vc[id][x]];
        }
    }
}
int vis2[200001];
void dfs2(int id,int pr)
{
    int a,b,c,d,e,f,g,h,x,y,z;
    vis2[id]=1;
    fin[id]=fin[pnt[id]];
    for(x=0;x<vc[id].size();x++)
    {
        if(vc[id][x]==pnt[id])
        {
            if(vv[id][x]==0)fin[id]--;
            else fin[id]++;
        }
    }
    //cout<<id<<" "<<fin[id]<<" "<<ar[id]<<endl;
    for(x=0;x<vc[id].size();x++)
    {
        if(vis2[vc[id][x]]==0)dfs2(vc[id][x],id);
    }
}
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=0;x<a-1;x++)
    {
        cin>>b>>c;
        vc[b].push_back(c);
        vv[b].push_back(0);
        vc[c].push_back(b);
        vv[c].push_back(1);
    }
    vc[1].push_back(0);
    vv[1].push_back(0);
    vis[0]=1;
    dfs(1,0);
    fin[0]=ar[1]+1;
    vis2[0]=1;
    dfs2(1,0);
    c=99999999;
    for(x=1;x<=a;x++)
        c=min(c,fin[x]);
    cout<<c<<endl;
    b=0;
    //for(x=1;x<=a;x++)cout<<fin[x]<<" "<<ar[x]<<endl;
    for(x=1;x<=a;x++)
    {
        if(fin[x]==c)
        {
            if(b!=0)cout<<" ";
            printf("%d",x);
            b++;
        }
    }
    cout<<endl;
}