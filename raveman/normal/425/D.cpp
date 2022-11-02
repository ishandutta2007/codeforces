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

int n;
int x[111111];
int y[111111];

vi vert[111111];
vi hor[111111];
#include<unordered_set>
unordered_set<int> hs[111111];

const int mod = (1<<20)-1;
bool u1[1<<20];
bool u2[1<<20];
bool u3[1<<20];
bool u4[1<<20];
bool u5[1<<20];
bool u6[1<<20];

bool hasPoint(int x,int y){
	return hs[x].count(y);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	
	cin>>n;
	//n=100000;
	REP(i,n){
		scanf("%d %d",x+i,y+i);
		//x[i]=i%333;
		//y[i]=i/333;
		vert[x[i]].pb(y[i]),hor[y[i]].pb(x[i]),u1[(x[i]*10007+y[i])&mod]=true,u2[(x[i]*9991+y[i])&mod]=true,u3[(x[i]*9607+y[i])&mod]=true,u4[(x[i]*9007+y[i])&mod]=true,hs[x[i]].insert(y[i]);
		u5[x[i]*ll(y[i])&mod]=true;
		u6[(13*x[i]+17*y[i]+3)&mod]=true;
	}
	REP(i,111111)SORT(vert[i]);
	REP(i,111111)SORT(hor[i]),reverse(hor[i].begin(),hor[i].end());

	ll res = 0;
	REP(i,111111)if(vert[i].size()){
		vi& curr = vert[i];
		int val,n1,n2,side;
		REP(j,curr.size()){
			val = curr[j];
			vi& hr = hor[val];
			n1 = curr.size() - j;
			n2 = hr.size();
			if(n1>n2){
				REP(k,hr.size()){
					side = hr[k] - i;
					if (side > 0 && hasPoint(i,val+side) && hasPoint(i+side,val+side)) res++;
				}
			}else{
				for(int k=j+1;k<curr.size();k++){
					side = curr[k] - val;
					if(hasPoint(i+side,val) && hasPoint(i+side,val+side)) res++;
				}
			}
			hr.pop_back();
		}
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}