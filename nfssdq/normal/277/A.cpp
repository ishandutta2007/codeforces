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
*********************************************************************************/

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
vector<int>vc[101],vl[101];
int on[101][101];
vector<int>vp[101];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    for(x=1;x<=a;x++)
    {
        cin>>c;
        for(y=0;y<c;y++)
        {
            cin>>d;
            vc[x].push_back(d);
            vl[d].push_back(x);
        }
    }
    for(x=1;x<=a;x++)
    {
        queue<int>q;
        for(y=0;y<vc[x].size();y++)
        {
            q.push(vc[x][y]);
            on[x][vc[x][y]]=1;
        }
        while(!q.empty())
        {
            c=q.front();
            q.pop();
            for(y=0;y<vl[c].size();y++)
            {
                for(z=0;z<vc[vl[c][y]].size();z++)
                {
                    if(on[x][vc[vl[c][y]][z]]==0)
                    {
                        on[x][vc[vl[c][y]][z]]=1;
                        q.push(vc[vl[c][y]][z]);
                    }
                }
            }
        }
    }
    d=0;
    h=0;
    int p=0;
    for(x=1;x<=a;x++)
    {
        f=0;
        h=0;
        for(y=0;y<d;y++)
        {
            g=0;
            //cout<<y<<" "<<d<<" "<<x<<" "<<vp[y].size()<<endl;
            for(z=1;z<=b;z++)g+=on[x][z];
            if(g==0)h++;
            if(vp[y].size()==0 && g==0)f++;
            else if(vp[y].size()>0 && on[x][vp[y][0]]==1)f++;
            if(f!=0)break;
        }
        if(f==0)
        {
            for(z=1;z<=b;z++)
            {
                if(on[x][z]==1)vp[d].push_back(z);
                //g+=on[x][z];
            }
            d++;
        }
        g=0;
        for(y=1;y<=b;y++)g+=on[x][y];
        if(g==0)p++;
       // cout<<p<<" "<<h<<endl;
    }

    //for(x=0;x<d;x++)
    {
        //for(y=0;y<vp[x].size();y++)cout<<vp[x][y]<<" ";
        //cout<<endl;
    }
    if(p==0 && d>0)cout<<d-1<<endl;
    else if(p>0 && d==1)cout<<p<<endl;
    else if(p>0 && d>1)cout<<p+d-2<<endl;

}