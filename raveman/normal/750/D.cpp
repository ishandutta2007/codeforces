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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int  res;
bool w[333][333];
bool u[333][333][31][6][8];
int  t[33];
int n;

int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,-1,-1,-1,0,1,1,1};

void go(int x,int y,int i, int len, int d) {
	if(len==t[i]){
		x-=dx[d];
		y-=dy[d];
		if(i+1!=n){
			int nd = (d+1)%8;
			go(x+dx[nd],y+dy[nd],i+1,0,nd);
			nd = (d+7)%8;
			go(x+dx[nd],y+dy[nd],i+1,0,nd);
		}
	}else{
		if(u[x][y][i][len][d])return;
		u[x][y][i][len][d]=true;
		if(!w[x][y]){w[x][y]=1;res++;}
		go(x+dx[d],y+dy[d],i,len+1,d);
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>t[i];
	go(150,150,0,0,0);
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}