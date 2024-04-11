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

int64 c[100][100];
int64 x[100][100];



ld t[100][100][100];
int a[100];

const int maxn=51;

void precalc(){
	for (int i=0;i<maxn;i++)
		for (int j=0;j<maxn;j++){
			if (i<j)
				c[i][j]=0;
			else if (i==j || j==0)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	for (int i=0;i<maxn;i++)
		for (int j=0;j<maxn;j++){
			if (j==0){
				if (i==0)
					x[i][j]=1;
				else
					x[i][j]=0;
				continue;
			}
			for (int k=0;k<=i;k++)
				x[i][j]+=x[i-k][j-1];
		}
}

ld pows(int a,int b){
	if (a==0)
		return 1;
	return pow(ld(b),ld(a));
}

ld prob(int n,int a,int j){
	if (n==0)
		{
			if (a==0)
				return 1;
			return 0;
		}
	return (pows(n-a,j-1)*c[n][a]/pows(n,j));/*x[n][j]*/;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
	precalc();
	t[0][0][0]=1;
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=m;i++)	
		cin>>a[i];
	for (int i=0;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int ans=0;ans<=n;ans++)
				for (int last=0;last<=i;last++){
				  //  cerr<<i<<" "<<j<<" "<<last<<" "<<prob(i,last,j)<<endl;
//					cerr<<i<<" "<<j<<" "<<ans<<" "<<last<<endl;
					int v=last/a[j]+!!(last%a[j]);
//					cerr<<v<<endl;
					if (v>ans)
						continue;
					if (v<ans){
						t[i][j][ans]+=prob(i,last,j)*t[i-last][j-1][ans];
						continue;
					}
					if (v==ans){
						ld p=prob(i,last,j);

						for (int lans=0;lans<=ans;lans++)
							t[i][j][ans]+=p*t[i-last][j-1][lans];
					}
				}
//	return 0;
	ld ansm=0;
	for (int ans=0;ans<=n;++ans){
		ansm+=t[n][m][ans]*ans;
//		cerr<<t[n][m][ans]<<endl;
	}
	cout.precision(15);
	cout<<fixed<<ansm<<endl;
    return 0;
}