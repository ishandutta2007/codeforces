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
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int a[111111];
int b[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",a+i);
	int res=-1;
	REP(i,n){
		b[i]=1;
		while(a[i]>=2*b[i])b[i]*=2;
	}

	FOR(i,2,n)if(b[i]==b[i-1] && b[i-1]==b[i-2]){
		res=1;
		break;
	}
	if(res==-1){
		for(int i1=0;i1<n;i1++){
			for(int i2=i1;i2<n;i2++){
				for(int i3=i2+1;i3<n;i3++){
					int n1=0,n2=0;
					REP(i,n)if(i>=i1 && i<=i2)n1^=a[i];
					REP(i,n)if(i>i2 && i<=i3)n2^=a[i];
					if(n1>n2){
						if(res==-1 || res>i3-i1-1) res=i3-i1-1;
					}
				}
			}
		}
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}