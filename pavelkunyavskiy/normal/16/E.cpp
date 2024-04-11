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


int n;

ld t[1<<18];
int sz[1<<18];
ld a[18][18];


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  cin>>n;
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
        cin>>a[i][j];
    sz[0]=0;
    for (int i=1;i<(1<<18);i++)
        sz[i]=sz[i&(i-1)]+1;
    for (int i=1;i<(1<<18);i++)
        sz[i]=sz[i]*(sz[i]-1)/2;
  t[(1<<n)-1]=1;    
  for (int mask=(1<<n)-1;mask>0;--mask){
    for (int i=0;i<n;i++)
        if ((1<<i) & mask)
            for (int j=i+1;j<n;j++)
                if ((1<<j) & mask)
                    if (i!=j)
                    {
                        t[mask^(1<<j)]+=t[mask]*a[i][j]/sz[mask];
                        t[mask^(1<<i)]+=t[mask]*a[j][i]/sz[mask];
                    }
                    
  }
   
  for (int i=0;i<n;i++){
    cout.precision(7);
    cout<<fixed<<t[(1<<i)]<<" ";
  }
  
  cout<<endl;
  return 0;
}