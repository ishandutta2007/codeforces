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

set<pair<int,int> > a,b;
int x[1000];
int y[1000];
int ans[1000];
int n;

bool check(){
	b=a;
	x[n]=x[0];
	y[n]=y[0];
//	for (int i=0;i<n;i++)
//		cerr<<"("<<x[i]<<" , "<<y[i]<<" ) ";
//	cerr<<endl;
	memset(ans,-1,sizeof(ans));
	for (int i=0;i<n;i+=2){
		int len=abs(x[i]-x[i+1])+abs(y[i]-y[i+1])+abs(y[i+2]-y[i+1])+abs(x[i+2]-x[i+1]);
		set<pair<int,int> >::iterator iter=b.lower_bound(mp(len,-1));
	//	cerr<<len<<" "<<iter->second<<endl;
		if (iter==b.end() || iter->first!=len)
			return false;
		ans[(i+1)%n]=iter->second+1;
		b.erase(iter);
	}
	return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	for (int i=0;i<m;i++)
		{
			int tmp;
			cin>>tmp;
			a.insert(mp(tmp,i));
		}
	for (int i=0;i<n;i++){
		rotate(x,x+1,x+n);
		rotate(y,y+1,y+n);
		if (check()){
			printf("YES\n");
			//cerr<<n-i-1<<endl;
			rotate(ans,ans+n-i-1,ans+n);
			for (int i=0;i<n;i++)
				printf("%d ",ans[i]);
			printf("\n");
			return 0;
		}
	}
	printf("NO\n");
    return 0;
}