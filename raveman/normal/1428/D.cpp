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


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",a+i);
	vector<pii> r;
	int row=0;
	int p=0;
	int p3=0;
	REP(i,n){
		if(a[i]==0){
			continue;
		}else if(a[i]==1){
			r.pb(pii(row,i));
			row++;
		}else if(a[i]==2){
			p=max(p,i+1);
			while(p<n && a[p]!=1)p++;
			if(p<n){
				r.pb(pii(row,i));
				r.pb(pii(row,p));
				row++;
				a[p]=-1;
				p++;
			}else{
				puts("-1");
				return 0;
			}
		}else if(a[i]==3){
			p3=max(p3,i+1);
			while(p3<n && a[p3]<1)p3++;
			if(p3<n){
				r.pb(pii(row,i));
				r.pb(pii(row,p3));
				row++;
				p3++;
			}else{
				puts("-1");
				return 0;
			}
		}else if(a[i]==-1){
		}
	}
	cout<<r.size()<<endl;
	REP(i,r.size())printf("%d %d\n",r[i].first+1,r[i].second+1);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}