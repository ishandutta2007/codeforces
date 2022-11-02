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
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int a[555][555];
priority_queue<pl> q;
ll d[555][555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,2*n)REP(j,2*n)scanf("%d",&a[i][j]);
		ll sum=0;
		REP(i,n)REP(j,n)sum+=a[n+i][n+j],a[n+i][n+j]=0;
		REP(i,2*n)REP(j,2*n)d[i][j]=-1;
		d[0][0]=0;
		q.push(pl(0,0*555+0));
		while(!q.empty()){
			pl curr = q.top();
			q.pop();
			int x = curr.second/555;
			int y = curr.second%555;
			ll cc = -curr.first;
			if(d[x][y]!=cc)continue;
			if(x>=n && y>=n)continue;
			FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
				int nx = x + dx;
				int ny = y + dy;
				if(nx==-1)nx=2*n-1;
				if(ny==-1)ny=2*n-1;
				if(nx==2*n)nx=0;
				if(ny==2*n)ny=0;
				ll nc = cc + a[nx][ny];
				if(d[nx][ny]==-1 || d[nx][ny]>nc){
					d[nx][ny]=nc;
					q.push(pl(-nc,555*nx+ny));
				}
			}
		}
		ll t = min(d[n][n],d[n][2*n-1]);
		t=min(t,d[2*n-1][n]);
		t=min(t,d[2*n-1][2*n-1]);
		cout<<sum+t<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}