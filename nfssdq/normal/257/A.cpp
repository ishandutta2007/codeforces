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
    cin>>a>>b>>c;
    for(x=0;x<a;x++)cin>>ar[x];
    sort(ar,ar+a);
    b-=c-1;
    d=0;
    e=0;
    if(b<=1)goto p;
    for(x=a-1;x>=0;x--)
    {
        d++;
        if(e+ar[x]>=b)
        {
            e+=ar[x];
            break;
        }
        else
        {
            e+=ar[x]-1;
        }
    }
    if(e<b)d=-1;
    p:cout<<d<<endl;
}