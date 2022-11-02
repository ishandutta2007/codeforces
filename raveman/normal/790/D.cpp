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

int n;
int d[333333];
unordered_map<int,int> w[333333];

int a[333333];
int b[333333];
int c[333333];

ll s[333333];

int v[3][1<<20];
void setVal(int* v,int pos,int val){
	pos+=1<<19;
	while(pos){
		v[pos]=min(v[pos],val);
		pos>>=1;
	}
}

unordered_map<ll, int> sp;
void precompute(int *a,int *v){
	//puts("start");
	sp.clear();
	REP(i,1<<20)v[i]=n+1;
	sp[0]=-1;
	REP(i,n){
		s[i+1]=s[i]+a[i];
		if(sp.count(s[i+1])){
			setVal(v,sp[s[i+1]]+1,i);
		//	cout<<"found "<<sp[s[i+1]]+1<<" "<<i<<endl;
		}
		sp[s[i+1]]=i;
	}
}

int findNext(int from,int *v){
	from += 1<<19;
	int to = n-1+(1<<19);
	int best = n + 1;
	while(from<=to){
		best=min(best,v[from]);
		best=min(best,v[to]);
		from=(from+1)>>1;
		to=(to-1)>>1;
	}
	return best;
	
}

int solve(int pos);

int solve2(int p1,int p2){
	if(p1>=n && p2>=n)return 0;
	if(w[p1].count(p2)) return w[p1][p2];
	int res = 0;
	int np1 = findNext(p1,v[0]);
	int np2 = findNext(p2,v[1]);
	if(np1<n && np1<=np2){
		res=max(res,1+solve2(np1+1,p2));
		res=max(res,1+solve(max(np1+1,p2)));
	}
	if(np2<n && np2<np1){
		res=max(res,1+solve2(p1,np2+1));
		res=max(res,1+solve(max(p1,np2+1)));
	}
	//cout<<p1<<' '<<p2<<" = " <<res<<endl;
	return w[p1][p2]=res;
}

int solve(int pos){
	if(pos>=n)return 0;
	if(d[pos]!=-1) return d[pos];
	int res = 0;
	// 2
	int npos = findNext(pos,v[2]);
	if(npos<n){
		res = max(res, 1 + solve(npos+1));
	}
	// 1
	res=max(res,solve2(pos,pos));

	//cout<<pos<<" = " <<res<<endl;
	return d[pos]=res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	CL(d,-1);
	cin>>n;
	REP(i,n)scanf("%d",&a[i]);
	REP(i,n)scanf("%d",&b[i]),c[i]=b[i]+a[i];

	precompute(a,v[0]);
	precompute(b,v[1]);
	precompute(c,v[2]);

	cout<<solve(0)<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}