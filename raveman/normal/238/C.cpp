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
vi v[3333];
bool d[3333][3333];

int r[3333][3];

int go(int ver,int par,int num){
	if(r[ver][num]!=-1) return r[ver][num];
	int val = 0;
	int sum = 0;
	REP(i,v[ver].size())if(v[ver][i]!=par){
		sum += go(v[ver][i],ver,0);
		if(!d[ver][v[ver][i]]) sum++;
	}
	val = sum;
	if(num>=1){
		REP(i,v[ver].size())if(v[ver][i]!=par){
			int t = sum - go(v[ver][i],ver,0);
			if(!d[ver][v[ver][i]]) t--;

			t += go(v[ver][i],ver,1);
			if(d[ver][v[ver][i]]) t++;

			val = min(val, t);
		}
	}
	if(num>=2){
		int m1 = 1e9;
		int m2 = 1e9;
		REP(i,v[ver].size())if(v[ver][i]!=par){
			int t = -go(v[ver][i],ver,0);
			if(!d[ver][v[ver][i]]) t--;

			t += go(v[ver][i],ver,1);
			if(d[ver][v[ver][i]]) t++;

			//cout<<"		"<<-go(v[ver][i],ver,0)<<' '<<go(v[ver][i],ver,1)<<endl;
			//cout<<v[ver][i]<<' '<<t<<endl;

			if(t<=m1){
				m2 = min(m2, m1);
				m1 = t;
			}else if(t<=m2) m2 = min(m2, t);
		}
		//cout<<ver<<endl;
	//	cout<<m1<<' '<<m2<<' '<<sum<<endl;
		val = min(val, sum + m1 + m2);
	}
//	cout<<"!!!  "<<ver<<' '<<num<<"	= "<<val<<endl;
	return r[ver][num]=val;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>n;
	if(n<=2){
		puts("0");
		return 0;
	}
	REP(i,n-1){
		int x,y;
		cin>>x>>y;
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
		d[x][y]=1;
	}
	int best = n-1;
	REP(i,n){
		//cout<<"start "<<i<<endl;
		CL(r,-1);
		best = min(best, go(i,-1,2));
		//cout<<"end "<<best<<endl;
	}
	cout<<best<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}