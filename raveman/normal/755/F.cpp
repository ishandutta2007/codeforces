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
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,k;
int a[1<<20];
int d[1<<20];
bitset<1<<20> u;

bool good(int t){
	u[0]=1;
	REP(i,1<<20)if(d[i]){
		int z = d[i];
		int j = 1;
		while(z){
			j=min(j,z);
			z-=j;
//			cout<<j*i<<' ' <<u[2]<<' '<<u[0]<<endl;
			u=u|(u<<(j*i));
	//		cout<<j*i<<' ' <<u[2]<<' '<<u[0]<<endl;
			j*=2;
		}
	}
	return u[t];
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	//n=1000000;
	//k=500001;
	REP(i,n)scanf("%d",a+i),a[i]--;
	//REP(i,n)a[i]=i;//random_shuffle(a,a+n);
	//REP(i,n/2)random_shuffle(a+i*2,a+i*2+2);
	REP(i,n)if(a[i]!=-1){
		int t = i;
		int num = 0;
		while(a[t]!=-1){
			int nt = a[t];
			a[t]=-1;
			t = nt;
			num++;
		}
		d[num]++;
	}
	int mn = k;
	int mx = 0;
	int r = k;
	REP(i,1<<20){
		int z = min(i/2*d[i],r);
		mx += z * 2;
		r -= z;
	}
	REP(i,1<<20)if(i%2==1 && r){
		int z = min(d[i],r);
		r-=z;
		mx+=z;
	}

	int tk=k;
	if(tk>n-k)tk=n-k;
	if(!good(tk))mn++;

	cout<<mn<<' '<<mx<<endl;
	
	
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}