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
int nx[333333][26];

int a[333333];
vector<pii> cl;

int merge(int p1, int p2){
	int res = 0;
	REP(i,26)if(nx[p1][i]!=-1){
		if(nx[p2][i]!=-1){
			res++;
			res+=merge(nx[p1][i],nx[p2][i]);
		}else{
			nx[p2][i] = nx[p1][i];
			cl.pb(pii(p2,i));
		}
	}
	return res;
}

int solve(int ver){
	int res = 0;
	REP(i,26)if(nx[ver][i]!=-1)res += merge(nx[ver][i], n)  + 1;
	while(!cl.empty()){
		nx[cl.back().first][cl.back().second]=-1;
		cl.pop_back();
	}
	return res;
}

void dfs(int ver,int depth=0){
	REP(i,26)if(nx[ver][i]!=-1)dfs(nx[ver][i], depth+1);
	a[depth] += solve(ver);
}

int build(vector<string> w){
	int nm=0;
	REP(i,w.size()){
		int beg = 0;
		REP(j,w[i].size()){
			if(nx[beg][w[i][j]-'a']==-1){
				nm++;
				nx[beg][w[i][j]-'a']=nm;
				beg=nm;
			}else beg = nx[beg][w[i][j]-'a'];
		}
	}
	return nm;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

start:

	CL(nx,-1);
	CL(a,0);
	vector<string> w;
	if(0){
		REP(i,3){
			string z;
			int q = rand()%3+1;
			REP(j,q)z.pb('a'+rand()%4);
			w.pb(z);
			cout<<z<<endl;
		}
		n=build(w)+1;
	}else{
		cin>>n;REP(i,n-1){int x,y;char c;scanf("%d %d %c",&x,&y,&c);x--,y--;nx[x][c-'a']=y;}
	}
	
	dfs(0);
	int best = -1, pos = -1;
	REP(i,n){
		int total = n - a[i];
		if(best==-1 || best>total){
			best=total;
			pos = i;
		}
	}
	cout<<best<<endl<<pos+1<<endl;
	if(0){
	int stupidbest=-1;
	int stupidpos=-1;
	REP(i,n){
		vector<string> tw;
		REP(j,w.size()){
			string z = w[j];
			if(z.size()>i){
				z.erase(z.begin()+i);
			}
			tw.pb(z);
		}
		CL(nx,-1);
		int x = build(tw) + 1;
		if(stupidbest==-1 || stupidbest>x){
			stupidbest=x;
			stupidpos=i;
		}
	}
	if(stupidbest!=best || stupidpos!=pos){
		while(1){
			cout<<best<<' '<<pos+1<<endl;
			cout<<stupidbest<<' '<<stupidpos+1<<endl;
			puts("FUCK");
			while(1);

		}
	}

	goto start;
	}
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}