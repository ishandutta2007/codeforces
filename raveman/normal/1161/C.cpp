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

//int d[11][11][11][11][11][11];
/*map<vi,int> d;

bool win(vi a){
	SORT(a);
	if(a[a.size()/2]==0) return 0;
	if(d.count(a)) return d[a];

	vi t=a;
	do{
		FOR(i1,1,t[0]+1)FOR(i2,1,t[1]+1)FOR(i3,1,t[2]+1){
			vi z=t;
			z[0]-=i1;
			z[1]-=i2;
			z[2]-=i3;
			if(!win(z)) return d[a]=1;
		}
	}while(next_permutation(t.begin(),t.end()));

	return d[a]=0;
}
*/
int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	int n;
	cin>>n;


	vi a(n);
	REP(i,n)cin>>a[i];
	SORT(a);
	if(a[0]==a[n/2]) puts("Bob");
	else puts("Alice");
	return 0;

	//CL(d,-1);
/*	vi a(6);
	for(a[0]=1;a[0]<=10;a[0]++)
	for(a[1]=a[0];a[1]<=10;a[1]++)
	for(a[2]=a[1];a[2]<=10;a[2]++)
	for(a[3]=a[2];a[3]<=10;a[3]++)
	for(a[4]=a[3];a[4]<=10;a[4]++)
	for(a[5]=a[4];a[5]<=5;a[5]++){
		if(!win(a)){
			REP(j,6)cout<<a[j]<<' ';
			puts("");
		}
	}
	cout<<"yo"<<endl;
	*/
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}