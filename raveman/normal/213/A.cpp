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

using namespace std;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int a[222];
vi  v[222];

typedef vector<bool> vb;

int go(vb act, int curr){
	if(act==vb(n, false)) return 0;
	int res = 0;
	bool fl = 1;
	while(fl){
		fl = 0;
		REP(i,n)if(act[i] && a[i]==curr){
			bool can_del = true;
			REP(j,v[i].size()) if(act[v[i][j]]){can_del=0;break;}
			if(can_del){
				fl = 1;
				act[i] = 0;
				res++;
			}
		}
	}
	if(act == vb(n,false)) return res;
	return res + go(act, (curr+1)%3) + 1;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>n;
	REP(i,n) cin>>a[i],a[i]--;
	REP(i,n){
		int x;
		cin>>x;
		REP(j,x){
			int y;
			scanf("%d",&y);
			v[i].pb(y-1);
		}
	}
	vb active(n, true);
	int res = go(active, 0);
	res = min(res, go(active, 1));
	res = min(res, go(active, 2));
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}