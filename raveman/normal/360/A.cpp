#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
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

using namespace std;


typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m;
ll a[5555];
ll b[5555];
ll c[5555];
int x[5555];
int y[5555];
int l[5555];
int r[5555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)b[i]=1000000000;
	REP(i,m){
		cin>>x[i]>>l[i]>>r[i]>>y[i];
		l[i]--,r[i]--;
		if(x[i]==1){
			for(int j=l[i];j<=r[i];j++)a[j]+=y[i];
		}else if(x[i]==2){
			for(int j=l[i];j<=r[i];j++){
				b[j]=min(b[j],y[i]-a[j]);
			}
		}
	}
	bool good = true;
	REP(i,n)if(b[i]<-1000000000)good=0;else c[i]=b[i];
	REP(i,m){
		if(x[i]==1){
			for(int j=l[i];j<=r[i];j++)c[j]+=y[i];
		}else{
			ll mx = c[l[i]];
			for(int j=l[i];j<=r[i];j++){
				mx=max(mx,c[j]);
			}
			//cout<<mx<<' '<<y[i]<<' '<<i<<endl;
			if(mx!=y[i]){good=0;break;}
		}
	}
	if(!good){
		puts("NO");
		return 0;
	}
	puts("YES");
	REP(i,n){
		if(i) printf(" ");
		cout<<b[i];
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}