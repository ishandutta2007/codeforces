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

const int modul=1000000007;

int c[1010][1010];

inline void norm(int &a){
	if (a>=modul) a-=modul;
}

int t[110][1010];
int x[110];
int y[110];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ld start=clock();
  #endif
	for (int i=0;i<1010;i++)
		for (int j=0;j<1010;j++){
			if (j==0)
				c[i][j]=1;
			else if (i==0)
				c[i][j]=0;
			else{
				c[i][j]=c[i-1][j]+c[i-1][j-1];
				norm(c[i][j]);
			}
		}
/*	for (int i=0;i<10;i++)
		for (int j=0;j<10;j++)
			cerr<<c[i][j]<<" \n"[j==9];*/
	int n;
	scanf("%d",&n);
	int sum=0;
	for (int i=0;i<n;i++){
		scanf("%d",&x[i]);
		sum+=x[i];
	}
	for (int i=0;i<n;i++)
		scanf("%d",&y[i]);
	for (int i=0;i<=sum;i++)
		t[0][i]=c[x[0]][i];
	int l,r;
	for (int i=0;i<n-1;i++)
		for (int j=0;j<=sum;j++){
			l=j+x[i+1]-y[i+1];
			l=max(l,0);
			r=j+x[i+1];
			r=min(r,sum);
			for (int k=l;k<=r;k++){
				t[i+1][k]+=(t[i][j]*1LL*c[r][k])%modul;
				norm(t[i+1][k]);
			}	
		}
	/*for (int i=0;i<4;i++)
		for (int j=0;j<10;j++)
			cerr<<t[i][j]<<" \n"[j==9];*/
	int ans=t[n-1][0];
	for (int i=0;i<n;i++){
		ans=(ans*1LL*c[sum][x[i]])%modul;
		sum-=x[i];
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE
  	cerr<<(clock()-start)/CLOCKS_PER_SEC<<endl;
  #endif	
    return 0;
}