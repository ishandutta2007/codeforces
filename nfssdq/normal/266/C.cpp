/********************************************************************************\
   |--\        ---       /\        |-----------| -----       /-------|           |
   |   \        |       /  \       |               |        /                    |
   |    \       |      /    \      |               |       |                     |
   |     \      |     /      \     |               |        \---\                |
   |      \     |    / ------ \    |-------|       |             \---\           |
   |       \    |   /          \   |               |                  |          |
   |        \   |  /            \  |               |                  /          |
  ---        \------            ------           -----     |---------/           |
                                                                                 |
                          _                                                      |
  **copyrighted by nfssdq(R) :) (:                                               |
                          ^                                                      |
    codeforces = nfssdq                                                          |
    topcoder = nafis007                                                          |
    uva = nfssdq                                                                 |
    spoj = nfssdq                                                                |
    usaco = nfssdq1                                                              |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                           |
    IIT,Jahangirnagar University(41)                                             |
    Sorry for badly written code.  :(                                            |
                                                                                 |
**********************************************************************************/

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
vector<int>vc[1001];
vector<pair<int,pair<int,int> > >vv;
int on[1001];
int col[1001];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=2;x<=a;x++)
    {
        cin>>b>>c;
        vc[b].push_back(c);
        col[c]++;
    }
    memset(on,0,sizeof on);
    for(x=a;x>=1;x--)
    {
        d=0;
        e=0;
        for(y=1;y<=x;y++)
        {
            if(vc[y].size()>d)
            {
                d=vc[y].size();
                e=y;
            }
        }
        swap(vc[e],vc[x]);
        if(vc[x].size()!=0 && x!=e)vv.push_back(make_pair(1,make_pair(x,e)));
    }
    b=0;
    for(x=2;x<=a;x++)
    {
        if(vc[x].size()==0)continue;
        for(y=0;y<vc[x].size();y++)
        {
            d=0;
            e=-1;
            for(z=y;z<vc[x].size();z++)
            {
                if(on[vc[x][y]]==0 && col[vc[x][z]]>d)
                {
                    d=col[vc[x][z]];
                    e=z;
                }
            }
            if(e==-1)continue;
            swap(vc[x][y],vc[x][e]);
            if(b+1!=vc[x][y] && on[vc[x][y]]==0)
            {
                //cout<<b<<vc[x][y]<<endl;
                vv.push_back(make_pair(2,make_pair(b+1,vc[x][y])));
                on[b+1]=1;
                f=vc[x][y];
                for(z=x;z<=a;z++)
                {
                    for(h=0;h<vc[z].size();h++)
                    {
                        if(vc[z][h]==f)
                        {
                            vc[z][h]=b+1;
                            col[b+1]++;
                            col[f]--;
                        }
                        else if(vc[z][h]==b+1)
                        {
                            vc[z][h]=f;
                            col[f]++;
                            col[b+1]--;
                        }
                    }
                }
                b++;
            }
            else if(b+1==vc[x][y])
            {
                on[b+1]=1;
                b++;
            }
        }
    }
    cout<<vv.size()<<endl;
    for(x=0;x<vv.size();x++)cout<<vv[x].xx<<" "<<vv[x].yy.xx<<" "<<vv[x].yy.yy<<endl;
}
/*
vector<int>vc[201];
int ar[201][201];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    memset(ar,127,sizeof ar);
    for(x=0;x<b;x++)
    {
        cin>>c>>d>>e;
        ar[c][d]=e;
        ar[d][c]=e;
    }
    for(x=1;x<=a;x++)
    {
        for(y=1;y<=a;y++)
        {
            for(z=1;z<=a;z++)
            {
                ar[y][z]=max(ar[y][z],ar[y][x]+ar[x][z]);
            }
        }
    }
    double d=99999999.0;
    for(x=1;x<=a;x++)
    {

        for(y=1;y<=a;y++)
        {
            double p=0,q=ar[x][y],r=(p+q)/2;
            while(p<r)
            {
                double tmp[201];
                memset(tmp,127,sizeof tmp);
                double val=0.0;
                for(z=1;z<=a;z++)
                {
                    tmp[z]=min(tmp[z],min((double)ar[x][z]+r,(double)ar[y][z]+(double)ar[x][y]-r));
                    val=max(e,tmp[z]);
                }
                if()
            }

        }
    }
}*/