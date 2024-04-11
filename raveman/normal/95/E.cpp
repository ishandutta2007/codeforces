#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n,m;
vi v[111111];
bool u[111111];
vi t;
int c;

void dfs(int ver){
	if(u[ver]) return;
	u[ver]=true;
	c++;
	REP(i,v[ver].size())
		dfs(v[ver][i]);
}

int cnt[111111];
int d[111111];
int r[111111];
int f[111111];
int p1,p2;
void solve(int val,int cnt){
	REP(mod,val){
		int start = n/val * val; start += mod;
		if(start>n) start-=val;

		int sub = 0;

		p1=p2=0;
		FOR(j, 1 ,cnt + 1 )if(start-j*val>=0){
			int pos = start - j * val;
			r[p2] = d[pos] + j;
			f[p2] = j;
			if(r[p2] <= r[p1]) p1 = p2;

			p2 ++;
		}


		int add = cnt;
		for(;start>=0;start-=val){

			if(p1<p2)
				d[start] = min(d[start], r[p1] - sub);

			sub++;
			if(f[p1] == sub) p1 ++;

			if(start - val - cnt * val >=0){
				add++;
				r[p2] = d[start-  val - cnt * val] + add;			
				f[p2] = add;
				if(r[p2] <= r[p1]) p1 = p2;
				p2++;
			}
		}
	}
}

bool good(int val){
	if(val==0) return 1;
	return good(val/10) && (val%10 == 4 || val%10==7);
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif



	cin>>n>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	REP(i,n)if(!u[i]){
		c=0;
		dfs(i);
		cnt[c]++;
	}

	REP(i,n+1) d[i] = n+1;
	d[0] = 0;

	REP(i,n+1) if(cnt[i]){
		//cout<<i<<' '<<cnt[i]<<endl;
		solve(i, cnt[i]);
	}

	int res = -1;
	FOR(i,1,n+1) if(d[i]<=n && good(i))
		if(res==-1 || res > d[i])
			res = d[i];
	if(res==-1) puts("-1");
	else cout<<res-1<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}