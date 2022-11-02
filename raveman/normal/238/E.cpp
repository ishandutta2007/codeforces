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

int n,m,a,b;
int d[111][111];
int ans[111];
int k;
int s[111];
int t[111];

bool g[111][111];
int r[111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>n>>m>>a>>b;a--,b--;
	
	REP(i,n)REP(j,n){
		if(i==j) d[i][j]=0;
		else d[i][j]=-1;
	}
	
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		d[x][y]=1;
	}

	REP(k,n)REP(i,n)REP(j,n)if(d[i][k]!=-1 && d[k][j]!=-1)
		if(d[i][j]==-1 || d[i][j]>d[i][k]+d[k][j])
			d[i][j]=d[i][k]+d[k][j];

	cin>>k;
	REP(i,k) cin>>s[i]>>t[i],s[i]--,t[i]--;

	REP(i,n)REP(j,k)if(d[s[j]][t[j]]!=-1 && d[s[j]][i]!=-1 && d[i][t[j]]!=-1 && d[s[j]][i]+d[i][t[j]]==d[s[j]][t[j]]){
		int good = 0;
		REP(ii,n)if(d[s[j]][ii] == d[s[j]][i] && d[s[j]][ii] + d[ii][t[j]] == d[s[j]][t[j]]) good++;
		g[i][j]=(good==1);
	}


	CL(ans,-1);
	ans[b]=0;

	bool change = 1;
	while(change){
		change=0;

		REP(i,n)REP(j,k)if(g[i][j]){
			vector<pii> v;
			REP(z,n) if(d[s[j]][i] <= d[s[j]][z] && d[s[j]][z]!=-1 && d[z][t[j]]!=-1 && d[s[j]][z]+d[z][t[j]]==d[s[j]][t[j]])
				v.pb(pii(d[z][t[j]],z));
			SORT(v);

			REP(z,v.size()){
				int ver = v[z].second;
				//cout<<"go "<<ver<<endl;
				r[ver]=ans[ver];
				if(r[ver]==-1) r[ver]=1e9;
				if(z==0) continue;
				int w = 0;
				REP(q,n) if(d[ver][q]==1 && d[q][t[j]]==d[ver][t[j]]-1)
					w=max(w,r[q]);
				r[ver]=min(r[ver],w);
				//cout<<"! "<<ver<<" >> "<<r[ver]<<endl;
			}	
			if(r[i]!=1e9)if(ans[i]==-1 || ans[i]>r[i]+1){
				//cout<<"set "<<i<<' '<<r[i]+1<<" using "<<j<<endl;
				ans[i]=r[i]+1;
				change=1;
			}
		}
	}

	cout<<ans[a]<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}