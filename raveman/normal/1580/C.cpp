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

int n,m;
int x[222222];
int y[222222];
int added_time[222222];

int d[200001][501];

int s[1<<20];
void add(int from,int to,int val){
	to=min(to,m-1);
	if(from>to)return;
	s[from]+=val;
	s[to+1]-=val;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)scanf("%d %d",x+i,y+i);
	int LIMIT=500;
	REP(i,m){
		int op,k;
		scanf("%d %d",&op,&k);
		k--;
		if(op==1){
			added_time[k]=i;
			if(x[k]+y[k]>=LIMIT){
				int start = i;
				while(start<m){
					add(start+x[k],start+x[k]+y[k]-1,1);
					start+=x[k]+y[k];
				}
			}else{
				FOR(j,i+x[k],i+x[k]+y[k]){
					if(j>=m)break;
					d[j][x[k]+y[k]]++;
				}
			}
		}else{
			if(x[k]+y[k]>=LIMIT){
				int start = added_time[k];
				while(start<m){
					int from = start+x[k];
					int to = start + x[k]+y[k]-1;
					from=max(from, i);
					if(from<=to)add(from,to,-1);
					start+=x[k]+y[k];
				}
			}else{
				FOR(j,added_time[k]+x[k],added_time[k]+x[k]+y[k]){
					if(j>=m)break;
					int tj = j;
					if(tj<i)tj+=(i-tj)/(x[k]+y[k])*(x[k]+y[k]);
					while(tj<i)tj+=(x[k]+y[k]);
					d[tj][x[k]+y[k]]--;
				}
			}
		}
	}
	int sum2=0;
	REP(i,m){
		int sum=0;
		sum2+=s[i];
		REP(j,501){
			sum+=d[i][j];
			if(i+j<200000)d[i+j][j]+=d[i][j];
		}

		cout<<sum+sum2<<"\n";
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}