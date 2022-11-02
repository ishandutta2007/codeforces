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

int n,m;
char s[22][22];
int c[22];

int d[22][22][1<<8];
queue<pii> q;

int st[10];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	st[0]=1;
	FOR(i,1,10)st[i]=st[i-1]*3;

	cin>>n>>m;
	int mx = -1;
	REP(i,n){
		cin>>s[i];
		REP(j,m)if(isdigit(s[i][j]))s[i][j]--,mx=max(mx, s[i][j]-'0');
	}
	int tmx=mx;
	REP(i,n)REP(j,m)if(s[i][j]=='B'){
		mx++;
		s[i][j]=char('0'+mx);
	}
	REP(i,mx+1)c[i]=-1000000;
	REP(i,tmx+1)cin>>c[i];
	mx++;
	REP(i,n)REP(j,m)REP(z,6666)d[i][j][z]=-1000000;	
	REP(i,n)REP(j,m)if(s[i][j]=='S'){
		d[i][j][0]=0;
		q.push(make_pair(0, i * 1000 * 10000 + j * 10000 + 0));
	}

	int it = 0;
	while(!q.empty()){
		++it;
		pii ppp = q.front();
		int cost = -ppp.first;
		int x = ppp.second/1000/10000;
		int y = ppp.second/10000%1000;
		int mask = ppp.second % 10000;
		q.pop();
		if(d[x][y][mask]!=cost) continue;
		//cout<<x<<' '<<y<<' '<<mask<<" : " <<cost<<' '<<f[x][y][mask]<<endl;
		
		FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
			int nx = x + dx;
			int ny = y + dy;
			int nmask = mask;
			if (nx>=0 && ny>=0 && nx<n && ny<m && (s[nx][ny]=='S' || s[nx][ny]=='.')){
				if(dy==0){
					if (d[nx][ny][nmask] < cost - 1) {
						d[nx][ny][nmask] = cost - 1;
						q.push(pii(-d[nx][ny][nmask], nx * 1000*10000 + ny*10000+nmask));
					}
				}else if(dy==1){
					int ncost = cost - 1;
					FOR(z,nx+1,n) if(isdigit(s[z][y])){
						nmask ^= (1<<(s[z][y]-'0'));
					}
					if (d[nx][ny][nmask] < ncost){						
						d[nx][ny][nmask] = ncost;
						q.push(pii(-d[nx][ny][nmask], nx * 1000*10000 + ny*10000+nmask));
					}
				}else if(dy==-1){					
					int ncost = cost - 1;
					FOR(z,nx+1,n) if(isdigit(s[z][ny])){
						nmask ^= (1<<(s[z][ny]-'0'));
					}
					if (d[nx][ny][nmask] < ncost){						
						d[nx][ny][nmask] = ncost;
						q.push(pii(-d[nx][ny][nmask], nx * 1000*10000 + ny*10000+nmask));
					}
				}
			}
		}
	}

	int res = 0;
	REP(i,n)REP(j,m)if(s[i][j]=='S'){
		REP(z,1<<8)if(d[i][j][z]!=-1000000){
			int mask = z;
			if(mask<(1<<(tmx+1))){
				int t = 0;
				REP(jj,tmx+1)if(mask&(1<<jj)) t+=c[jj];
				res=max(res,d[i][j][z]+t);
			}	
		}
	}
	cout<<res<<endl;//' '<<it<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}