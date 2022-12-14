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
int on[1000001];
char pp[1000001];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%s",pp);
    a=strlen(pp);
    b=0;
    c=0;
    for(x=0;x<a;x++)
    {
        if(pp[x]=='x')b++;
        else c++;
    }
    if(b>c)for(x=c+1;x<=b;x++)printf("x");
    else for(x=b+1;x<=c;x++)printf("y");
    cout<<endl;
}