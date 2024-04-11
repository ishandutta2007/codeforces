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

int n;
int a[444444];


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",a+i);
	sort(a,a+n);
	vector<pii> v;
	for(int i=0;i<n;){
		int j=i;
		while(j<n && a[i]==a[j])++j;
		v.pb(pii(j-i,a[i]));
		i=j;
	}
	SORT(v);
	reverse(v.begin(),v.end());

	int best=0;
	int nrows=0,ncol=0;

	int pos = v.size() - 1;
	int sum=0;
	for(int rows=1;rows<=n;rows++){
		while(pos>=0 && v[pos].first<rows){
			sum += v[pos].first;
			pos--;
		}
		//cout<<rows<<' '<<sum<<endl;
		int csum = sum + (pos+1)*rows;
		int cols = csum / rows;
		if(cols>=rows){
			if(best<cols*rows){
				best=cols*rows;
				nrows=rows;
				ncol=cols;
			}
		}
	}



	cout<<best<<endl<<nrows<<' '<<ncol<<endl;
	vector<vi> r;
	REP(i,nrows)r.pb(vi(ncol,-1));
	int t=0;
	REP(i,v.size()){
		int num = min(v[i].first,nrows);
		REP(j,num){
			int x=t%nrows;
			int y=t/nrows+x;
			y%=ncol;
			r[x][y]=v[i].second;
			t++;
		}
	}

	REP(i,r.size()){
		REP(j,r[i].size()) printf("%d ",r[i][j]);
		puts("");
	}
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}