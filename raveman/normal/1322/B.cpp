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
typedef pair<int,pii>	p3;
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

int n;
int a[444444];
int b[444444];
int c[1<<25];
int u[1<<25];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",a+i);
	CL(c,0);CL(u,0);

	int res=0;
	CL(u,-1);
	REP(i,25){
		int n1=0,n2=0;
		REP(j,n){
			if(a[j]&(1<<i))n1++;else n2++;
			b[j]=a[j]&((1<<i)-1);
			if(u[b[j]]!=i)u[b[j]]=i,c[b[j]]=0;
			c[b[j]]++;
		}
		if((n1%2)*(n2%2))res^=(1<<i);
		int sum=0;
		REP(j,1<<i){
			if(j+j>=(1<<i))break;
			if(u[(1<<i)-j]==i){
				sum ^= (c[(1<<i)-j]%2);
			}
			if(u[j]==i && (c[j]%2) && sum) res ^= (1<<i);//,cout<<"jere"<<j<<endl;;
		}
		if(i>0){
			sum=0;
			FOR(j,(1<<i)/2,(1<<i))if(u[j]==i){
				sum += c[j];
				if((ll(c[j])*ll(c[j]-1)/2)%2==1)res^=(1<<i);
			}
			FOR(j,(1<<i)/2,(1<<i))if(u[j]==i){
				sum-=c[j];
				if(c[j]%2 && sum%2)res^=(1<<i);
			}
		}
		//c/out<<i<<' '<<res<<' '<<n1<<' '<<n2<<' '<<u[(1<<i)/2]<<' '<<c[(1<<i)/2]<<endl;
	}
	cout<<res<<endl;
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}