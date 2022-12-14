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
#define mod 1000000009
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())

using namespace std;

LL gt[26];
char ar[401][401];
LL ac[401][401];
char pp[401];
main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    LL a,b,c,d,e,f,g,h,x,y,z;
    a=0;
    /*for(x=1;x<=400;x++)
    {
        for(y=1;y<=400;y++)
        {
            for(z=1;z<=400;z++)
            {
                for(c=1;c<=10;c++)a++;
            }
        }
    }
    cout<<a<<endl;
    return 0;*/

    cin>>a>>b>>c;
    for(x=1;x<=a;x++)
    {
        scanf("%s",pp);
        for(y=1;y<=b;y++)ar[x][y]=pp[y-1];
    }
    for(x=1;x<=a;x++)
    {
        for(y=1;y<=b;y++)
        {
            d=0;
            if(ar[x][y]=='a')d++;
            ac[x][y]=ac[x-1][y]+ac[x][y-1]-ac[x-1][y-1]+d;
        }
    }
    LL sum=0;
    for(x=1;x<=a;x++)
    {
        for(y=x+1;y<=a;y++)
        {
            int p=b;
            memset(gt,0,sizeof gt);
            for(z=b;z>=1;z--)
            {
                while(ac[y][p]-ac[x-1][p]-ac[y][z-1]+ac[x-1][z-1]>c && p>z)
                {
                    if(ar[x][p]==ar[y][p])gt[ar[x][p]-'a']--;
                    p--;
                }
                if(ar[x][z]==ar[y][z])
                {
                    sum+=gt[ar[x][z]-'a'];
                    gt[ar[x][z]-'a']++;
                }
                //cout<<x<<" "<<y<<" "<<sum<<" "<<p<<" "<<z<<endl;
            }
        }
    }
    cout<<sum<<endl;
}