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
char pp[12];
int dp[27][27];
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    f=0;
    g=0;
    for(x=0;x<a;x++)
    {
        scanf("%s",pp);
        b=pp[strlen(pp)-1]-'a';
        c=pp[0]-'a';
        for(y=0;y<26;y++)
        {
            if(dp[y][c]>0)dp[y][b]=max(dp[y][b],(int)strlen(pp)+dp[y][c]);
            if(y==b)f=max(f,dp[y][b]);
        }
        dp[c][b]=max(dp[c][b],(int)strlen(pp));
        if(c==b)f=max(f,dp[c][b]);
    }
    cout<<f<<endl;

}