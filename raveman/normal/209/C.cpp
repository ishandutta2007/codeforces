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
#define pb				push_back

vi v[1111111];
int n,m;
int d[1111111];
bool u[1111111];
int num;

void dfs(int ver){
	if(u[ver]) return;
	u[ver] = true;
	if(d[ver]%2) num++;
	REP(i,v[ver].size()) dfs(v[ver][i]);
}
vi t;

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
		d[x]++;
		d[y]++;
	}
	v[0].pb(0);
	v[0].pb(0);
	d[0] += 2;
	REP(i,n)if(d[i] && !u[i]){
		num=0;
		dfs(i);
		t.pb(num);
	}
	sort(t.begin()+1,t.end());
	int res = 0;
	while(t.size()>1){
		res++;
		t.back()--;
		t[0]--;
		if(t.back()<0) t.back()=1;
		if(t[0]<0) t[0] = 1;
		t[0] += t.back();
		t.pop_back();
	}
	cout<<res+t[0]/2<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}