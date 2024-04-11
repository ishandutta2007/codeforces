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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m,l;
int a[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	set<pii> s;
	cin>>n>>m>>l;
	REP(i,n)scanf("%d",a+i);
	for(int i=0;i<n;i++)if(a[i]>l){
		int j=i;
		while(j<n && a[j]>l)++j;
		s.insert(pii(i,j-1));
		i=j;
	}
	REP(i,m){
		int t;
		scanf("%d",&t);
		if(t==0)printf("%d\n",int(s.size()));
		else{
			int p,d;
			scanf("%d %d",&p,&d);
			p--;
			if(a[p]<=l && a[p]+d>l){
				set<pii>::iterator it = s.lower_bound(pii(p,p));
				pii v1(-1,-1);
				pii v2(-1,-1);
				if(it!=s.end() && it->first==p+1){
					v2 = *it;
					s.erase(it);
				}
				it = s.lower_bound(pii(p,p));
				if(it!=s.begin()){
					it--;
					if(it->second+1==p){
						v1=*it;
						s.erase(it);
					}
				}
				if(v1.first==-1 && v2.first==-1)s.insert(pii(p,p));
				else if(v1.first==-1) s.insert(pii(v2.first-1,v2.second));
				else if(v2.first==-1) s.insert(pii(v1.first,v1.second+1));
				else s.insert(pii(v1.first,v2.second));
			}
			a[p]=min(a[p]+d,l+1);
		}
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}