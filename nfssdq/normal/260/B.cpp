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
#define LL long long
map<string,int>mp;
char pp[100001];
int mnt[13]={31,28,31,30,31,30,31,31,30,31,30,31};
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%s",pp);
    b=strlen(pp);
    for(x=0;x<=b-10;x++)
    {
        if(pp[x]!='-' && pp[x+1]!='-' && pp[x+2]=='-' && pp[x+3]!='-' && pp[x+4]!='-' && pp[x+5]=='-'
           && pp[x+6]!='-' && pp[x+7]!='-' && pp[x+8]!='-' && pp[x+9]!='-')
        {
            c=(pp[x]-'0')*10+pp[x+1]-'0';
            d=(pp[x+3]-'0')*10+pp[x+4]-'0';
            e=(pp[x+6]-'0')*1000+(pp[x+7]-'0')*100+(pp[x+8]-'0')*10+pp[x+9]-'0';
            string s="";
            for(y=x;y<x+10;y++)s+=pp[y];
            if(d>=1 && d<=12 && mnt[d-1]>=c && c>0 && e>2012 && e<2016)
            {
                mp[s]++;
            }
        }
    }
    map<string,int>::iterator it,ip;
    c=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if((*it).yy>c)
        {
            c=(*it).yy;
            ip=it;
        }
    }
    cout<<(*ip).xx<<endl;

}