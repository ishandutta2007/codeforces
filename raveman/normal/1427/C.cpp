//#pragma comment(linker, "/STACK:60777216")  

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

int md[111111];
int d[111111];
int x[111111];
int y[111111];
int t[111111];
int r,n;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>r>>n;
	x[0]=y[0]=1;
	t[0]=0;
	CL(d,-1);
	d[0]=0;
	FOR(i,1,n+1){
		scanf("%d %d %d",t+i,x+i,y+i);
		for(int j=i-1;j>=0;j--){
			if(d[j]!=-1 && abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]){
				d[i]=max(d[i],d[j]+1);
				//cout<<"!"<<i<<' '<<j<<endl;
			}
			if(t[i]-t[j]>=1000){
				d[i]=max(d[i],md[j]+1);
				//cout<<"yo "<<j<<endl;
				break;
			}
		}
		//cout<<i<<' '<<d[i]<<endl;
		md[i]=max(d[i],md[i-1]);
	}
	cout<<md[n]<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}