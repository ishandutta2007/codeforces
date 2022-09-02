#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

int dx[25];
int dy[25];
int dcnt;

int val[450][450];
int d;

int solve(int x,int y){
    if (x*x + y*y > d*d){
//      cerr<<x <<" "<<y <<" WIN"<<endl;
        return 2;
    }
    int& res= val[x+210][y+210];
    if (res != 0)
        return res;
    for (int i=0;i<dcnt;i++)
        if (solve(x+dx[i],y+dy[i]) == 1){
//          cerr<<x<<" "<<y<<"  WIN"<<endl;
            return res=2;
        }
//  cerr<<x<<" "<<y<<" LOSE"<<endl;
    res=1;
    return 1;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int x,y;
    cin>>x >> y>> dcnt>> d;
    for (int i=0;i<dcnt;i++)
        cin>>dx[i]>>dy[i];
    int tmp=solve(x,y);
    if (tmp == 1)
        printf("Dasha\n");
    else
        printf("Anton\n");
    return 0;
}