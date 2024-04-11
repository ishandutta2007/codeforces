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

int n,m,k;
string a[111];
int rs,cs,re,ce;
string s;

pii t[26];

set<pii> ins;
map< pair<pii,pii> , int> d;

int u[111][111];
pii f[111][111];


void build(int x,int y){
	CL(u,-1);
	u[x][y]=0;
	priority_queue< pair<int, pii> > q;
	q.push(make_pair(0, pii(x,y)));

	while(!q.empty()){
		int cost = -q.top().first;
		int xx = q.top().second.first;
		int yy = q.top().second.second;
		q.pop();
		if(u[xx][yy]!=cost) continue;

		if(ins.count(pii(xx,yy))){
			d[make_pair(pii(x,y),pii(xx,yy))] = cost;
	//		cout<<x<<','<<y<<" -> "<<xx<<','<<yy<<" = "<<cost<<endl;
		}

		FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
			int nx = xx + dx;
			int ny = yy + dy;
			if(nx>=0 && nx<n && ny>=0 && ny<m){
				if(a[nx][ny]!='#'){
					int ncost = cost;

					if(isalpha(a[xx][yy]) && cost) continue;
					if(isalpha(a[xx][yy])) ncost ++;
					else ncost += a[xx][yy] - '0';

					if(u[nx][ny]==-1 || u[nx][ny]>ncost){
						u[nx][ny] = ncost;
						f[nx][ny] = pii(xx,yy);
						q.push(make_pair(-ncost,pii(nx,ny)));
					}
				}
			}
		}
	}
}

void go(int x,int y,int tx,int ty,int k){
	//cout<<k<<endl;
	//k = d[make_pair(pii(x,y),pii(tx,ty))] - k;
	build(x,y);
	//cout<<k<<endl;
	while(u[tx][ty]>k){
		//cout<<k<<endl;
		//k--;
		pii tt = f[tx][ty];
		tx = tt.first;
		ty = tt.second;

	}
	cout<<tx+1<<' '<<ty+1<<endl;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,n) cin>>a[i];
	REP(i,n)REP(j,m)if(a[i][j]>='a'&&a[i][j]<='z')
		t[a[i][j]-'a']=pii(i,j),ins.insert(pii(i,j));
	cin>>rs>>cs>>s>>re>>ce;rs--,cs--,re--,ce--;
//	cout<<s<<endl;
	ins.insert(pii(rs,cs));
	ins.insert(pii(re,ce));
	build(rs,cs);
	build(re,ce);
	REP(i,n)REP(j,m)if(a[i][j]>='a'&&a[i][j]<='z')
		build(i,j);
	int x = rs;
	int y = cs;
	REP(i,s.size()){
		pii pos = t[s[i]-'a'];
		int dist = d[make_pair(pii(x,y),pos)];
		if(dist<=k){
			k -= dist;
			x = pos.first;
			y = pos.second;
		}else{
			go(x,y,pos.first,pos.second,k);
			return 0;
		}
	}
	int dist = d[make_pair(pii(x,y),pii(re,ce))];
	if(dist>=k){
		go(x,y,re,ce,k);
	}else cout<<re+1<<' '<<ce+1<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}