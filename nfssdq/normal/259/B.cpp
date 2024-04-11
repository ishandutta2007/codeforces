
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <locale>
#include <iterator>
#include <valarray>
#include <complex>
using namespace std;
#define xx first
#define yy second
int pp[3][3];
int on(int v)
{
    int a,b,c,d,e,f,x,y,z;
    for(x=0;x<3;x++)
    {
        a=0;
        for(y=0;y<3;y++)a+=pp[x][y];
        if(a!=v)return 0;
        a=0;
        for(y=0;y<3;y++)a+=pp[y][x];
        if(a!=v)return 0;
    }
    a=0;
    for(x=0;x<3;x++)a+=pp[x][x];
    if(a!=v)return 0;
    a=0;
    for(x=0;x<3;x++)a+=pp[x][2-x];
    if(a!=v)return 0;
    return 1;
}
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)cin>>pp[x][y];
    }
    for(x=3;x<=300000;x++)
    {
        pp[0][0]=x-pp[0][1]-pp[0][2];
        pp[1][1]=x-pp[1][0]-pp[1][2];
        pp[2][2]=x-pp[2][0]-pp[2][1];
        if(on(x)!=0)
        {
            for(y=0;y<3;y++)
            {
                for(z=0;z<3;z++)
                {
                    cout<<pp[y][z];
                    if(z==2)cout<<endl;
                    else cout<<" ";
                }
            }
            break;
        }
    }
}