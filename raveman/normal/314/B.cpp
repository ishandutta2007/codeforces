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

string a,c;

bool  u[111];
pii   d[111];

pii solve(int pos){
	if(u[pos]) return d[pos];
	u[pos]=true;
	
	int start = pos-1;
	int lp = 0;
	int pos2 = 0;
	while(pos2<c.size()){
		start++;
		if(start==a.size()) start=0,lp++;
		int num = 0;
		while(a[start]!=c[pos2]){
			start++;
			if(start==a.size()) start=0,lp++,num++;
			if(num>2) return d[pos]=pii(-1,-1);
		}
		pos2++;
	}
	return d[pos]=pii(start,lp);
}


bool  v[22][111];
pii   r[22][111];

pii go(int step,int pos){
	//cout<<step<<' '<<pos<<endl;
	if(step==0) return solve(pos);
	if(v[step][pos]) return r[step][pos];
	v[step][pos]=true;
	pii x = go(step-1,pos);
	if(x.first==-1) return r[step][pos]=x;
	x.first++;
	if(x.first==a.size()){
		x.first=0;
		x.second++;
	}
	pii y = go(step-1,x.first);
	if(y.first==-1) return r[step][pos]=y;
	return r[step][pos]=pii(y.first,y.second+x.second);
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	int b,d;
	cin>>b>>d;
	cin>>a>>c;
	

	int res = 0;

	int start = 0;
	int loop = 0;
	while(loop < b){
		bool allbad=1;
		pii x;
		int st;
		for(int step=10;step>=0;step--){
			//cout<<"CALL "<<step<<endl;
			x = go(step, start);
			if(x.first==-1)
				continue;
			//cout<<"! " <<x.first<<' '<<x.second<<endl;
			if(loop+x.second<b){
				allbad=0;
				st=(1<<step);
				break;
			}
			//puts("HERE");
		}
		if(allbad) break;
		//puts("YO");
		//cout<<st<<endl;
		loop += x.second;
		start = x.first;

		if(loop<b){
			res+=st;
			start++;
			if(start>=a.size()){
				start=0;
				loop++;
			}
		}
	}

	cout<<res/d<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}