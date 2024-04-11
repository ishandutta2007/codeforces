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

int n,n9;
int64 kol(int64 ost,int64 n){
	int64 ans=n/9;
	if (n%9>=ost && ost!=0)
		ans++;
	return ans;
}


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  scanf("%d",&n);
  int64 ans=0;
  n9=n%9;
  for (int64 i=1;i<=n;i++)
  {
  	for (int64 j=0;j<=8;j++){
  		int pr=(i%9*j)%9;
  		ans+=(kol(pr,n)-1)*kol(j,n/i);
  		ans+=kol(pr,n)*(kol(j,n)-kol(j,n/i));
  		//cerr<<i<<" "<<j<<" "<<ans<<endl;
  	}
  }
  cout<<ans<<endl;
  return 0;
}