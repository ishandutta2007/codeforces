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

const int mod = 1000000007;

int n,m,k;

int d[202][505][202][2];

int L[222];
int R[222];

int nmb[222][222];
int CCC[222];

void add(int& x,int v){x+=v;if(x>=mod)x-=mod;}

int per[222][22];
int cst[222];

int solve(int* N){
	CL(d,0);
	
	REP(i,200)FOR(j,1,(i+1<N[211]?m:N[i]+1)){
		d[i][cst[per[0][j]]][per[0][j]][i+1<N[211]?1:(j<N[i]?1:0)]++;
	}

	int val,npos;
	for(int len=200;len;len--)REP(cost,k+1)REP(pos,202)REP(type,2)if(val=d[len][cost][pos][type]){
		for(int next=0;next<m;next++){
			if(type==0 && next>N[len-1])break;
			npos = per[pos][next];			
			add(d[len-1][cost + cst[npos]][npos][type|(next<N[len-1])], val);
		}
	}

	int res = 0;
	REP(i,k+1)REP(j,202){
		res += d[0][i][j][0];
		if(res>=mod)res-=mod;
		res += d[0][i][j][1];
		if(res>=mod)res-=mod;
	}
	
	return res;
}


void readN(int* a){
	scanf("%d",a+211);
	REP(i,*(a+211)) scanf("%d",a+i);
	reverse(a+0,a+*(a+211));
}

vi inv_nmb[222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	
	readN(L);
	readN(R);
	REP(i,n) {
		readN(nmb[i]);
		cin>>CCC[i];
	}

	vector<vi> prefixes;
	prefixes.pb(vi());
	REP(i,n){
		REP(j,nmb[i][211]) inv_nmb[i].pb(nmb[i][j]);
		reverse(inv_nmb[i].begin(),inv_nmb[i].end());
		
		REP(j,inv_nmb[i].size()){
			vi tmp;
			REP(k,j+1)tmp.pb(inv_nmb[i][k]);
			prefixes.pb(tmp);
		}		
	}
	UN(prefixes);
	if(0){
		cout<<prefixes.size()<<endl;
		REP(i,prefixes.size()){
			REP(j,prefixes[i].size()) cout<<prefixes[i][j]<<' ';
			puts("");
		}
	}
	REP(i,prefixes.size())REP(j,m){
		vi tmp=prefixes[i];
		tmp.pb(j);
		//per[i][j]=getPer(prefixes,tmp);
		per[i][j]=-1;
		while(1){
			REP(k,prefixes.size()) if(prefixes[k]==tmp){
				per[i][j]=k;
				break;
			}
			if(per[i][j]!=-1)break;
			tmp.erase(tmp.begin());
		}
	}
	REP(i,prefixes.size()){
		vi tmp=prefixes[i];		
		int COST = 0;
		REP(curr,n){
			if(tmp.size() >= nmb[curr][211]) {
				bool good = true;
				REP(j,nmb[curr][211])
					if(tmp[tmp.size()-j-1]!=nmb[curr][j]) {good=0;break;}
				if(good) COST += CCC[curr];
			}
		}
		cst[i] = COST;
	}



	int res = solve(R);
	
	L[0] --;
	int pos = 0;
	while(L[pos]<0){
		L[pos]+=m;
		pos++;
		L[pos]--;
	}

	res -= solve(L);
	if(res<0)res+=mod;

	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}