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
    Everything happens after running this code is solely your responsibilty.     |
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
#define vi vector<int>
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define mdd map<int,int>
#define pii pair<int,int>
#define ULL unsigned long long
#define pll pair<long long,long long>
#define vsort(v) sort(v.begin(),v.end())

int ar[51];
int main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a>>b;
    /*c=a;
    d=b;
    e=0;
    for(x=1;x<=c;x++)
    {
        if(d>1)
        {
            d-=2;
            e++;
        }
        else if(d==1)
        {
            d--;
        }
        else
        {
            e+=(c-x);
            break;
        }
    }
    e+=d;
    d=a;
    c=b;
    f=0;
    for(x=1;x<=c;x++)
    {
        if(d>1)
        {
            d-=2;
            f++;
        }
        else if(d==1)
        {
            d--;
        }
        else
        {
            f+=(c-x);
            break;
        }
    }
    f+=d;
    if(f>e)e=f;
    d=(a+b-1-e);
    cout<<e<<" "<<d<<endl;*/
    c=min(a,b);
    d=(a+b-1)-c;
    cout<<d<<" "<<c<<endl;
}