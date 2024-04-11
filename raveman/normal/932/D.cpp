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

ll     w[444444];
int    p[444444][19];
ll     s[444444][19];

void addVertex(int id,int parent,int weight){
	w[id] = weight;
	while(parent>=1 && w[parent]<w[id]) parent=p[parent][0]; 
	p[id][0]=parent;
	s[id][0]=w[id];
	//cout<<"add " <<id<<' '<<parent<<endl;
	FOR(i,1,19){
		if (p[id][i-1] == -1) p[id][i]=-1;
		else {
			p[id][i]=p[p[id][i-1]][i-1];
			s[id][i]=s[id][i-1]+s[p[id][i-1]][i-1];
		}
	}
}

int solve(int start,ll total_cost){
	int res = 0;
	for(int ii=18;ii>=-1;ii--){
		int i = max(ii,0);
		//cout<<"start " << start<<" "<<i<<" "<<p[start][i]<<endl;
		if (start != -1) if(p[start][i]!=-1 || i==0){
			if(s[start][i]<=total_cost){
				res += (1<<i);
				total_cost -= s[start][i];
				start = p[start][i];
			}
		}
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	CL(p,-1);

	int q;
	cin>>q;
	int last=0,cnt=1;
	REP(Q,q){
		ll t,p,q;
		scanf("%I64d %I64d %I64d",&t,&p,&q);
		p^=last;
		q^=last;
		if (t==1){
			addVertex(cnt+1,p,q);
			cnt++;
		}else if (t==2){
			last=solve(p,q);
			printf("%d\n",last);
		}
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}