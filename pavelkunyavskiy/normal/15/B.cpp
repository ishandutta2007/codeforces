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

void solve(){
    int n,m,x1,y1,x2,y2;
    scanf("%d %d %d %d %d %d",&n,&m,&x1,&y1,&x2,&y2);
    int64 dx=abs(x2-x1);
    int64 dy=abs(y2-y1);
    int64 ans=n*1ll*m;
    ans-=(n-dx)*1ll*(m-dy);
    ans-=(n-dx)*1ll*(m-dy);
    ans+=(max(n-2*dx,0ll))*1ll*(max(m-2*dy,0ll));
    cout<<ans<<endl;
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int t;
  scanf("%d",&t);
  for (int i=0;i<t;i++)
    solve();
  return 0;
}