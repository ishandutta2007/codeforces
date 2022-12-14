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
#define LL long long

char pp[101],ps[101];
queue<string>vv;
int main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    scanf("%d",&a);
    for(int r=0;r<a;r++)
    {
        scanf("%s",pp);
        b=0;
        string s="";
        for(x=0;x<strlen(pp);x++)
        {
            s+=pp[x];
            if(pp[x]==':')
            {
                if(x!=0)vv.push(s);
                if(x!=0)b++;
                s="";
            }
        }
        d=strlen(pp);
        if(pp[d-1]!=':'){vv.push(s);b++;}
        c=8-b;
        for(y=0;y<b;y++)
        {
            string ss="";
            ss=vv.front();
            vv.pop();
            e=5;
            if(y==b-1 && ss[0]!=':')e=4;
            for(z=0;z<e-ss.length();z++)cout<<"0";
            e=ss.length();
            if(y==b-1 && c==0 && ss[0]==':')e--;
            for(z=0;z<e;z++)cout<<ss[z];
            if(ss[0]==':')
            {
                e=c;
                if(y==b-1)e--;
                for(z=0;z<e;z++)cout<<"0000:";
                if(y==b-1 && c!=0)cout<<"0000";
            }
        }
        cout<<endl;
    }
    return 0;
}
//1000000000
//999999999