#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000007;
int f[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	f[0]=1;
	FOR(i,1,111111){
		f[i]=f[i-1];
		if(i-2>=0)f[i]+=f[i-2];
		if(f[i]>=mod)f[i]-=mod;
	}
	int n,m;
	cin>>n>>m;

	int res = f[n];
	FOR(i,1,m)res+=f[i-1],res%=mod;

	cout<<(res*2)%mod<<endl;
	return 0;
	
	int a[11][11];
	CL(a,0);
	for(int n=1;n<=10;n++)
		for(int m=1;m<=n;m++){

			int x = n * m;
			if(x>25)continue;
			int num = 0;
			REP(i,1<<x){
				REP(i1,n)REP(i2,m){
					a[i1][i2]=(i&(1<<(i1*m+i2)))?1:0;
				}
				bool good = 1;
				REP(i1,n)REP(i2,m){
					int w = 0;
					FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
						int nx=i1+dx;
						int ny=i2+dy;
						if(nx>=0 && nx<n && ny>=0 && ny<m)
							if(a[nx][ny]==a[i1][i2])w++;
					}
					if(w>1)good=0;
				}
				if(good)num++;
			}
			cout<<n<<' '<<m<<' '<<num<<endl;
		}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}