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
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
using namespace std;


int64 t[20][4][15][15][3];
int n,T;

int64 cnt(int x,int y,int g,int dg,int up){
    if (t[x][y][g][dg][up]!=-1)
        return t[x][y][g][dg][up];
    if (x==n-1)
        return (g==T && dg==T-1);
    int64& tmp=t[x][y][g][dg][up];
    tmp=0;
    for (int i=0;i<y;i++)
        tmp+=cnt(x+1,i,g+(up==2),dg,1);
    for (int i=y+1;i<4;i++)
        tmp+=cnt(x+1,i,g,dg+(up==1),2);
    return tmp;
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>n>>T;
    setval(t,-1);
    int64 ans=cnt(0,0,0,0,0);
    ans+=cnt(0,1,0,0,0);
    ans+=cnt(0,2,0,0,0);
    ans+=cnt(0,3,0,0,0);
    cout<<ans<<endl;
  return 0;
}