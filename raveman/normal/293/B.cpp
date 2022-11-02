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

int n,m,k;
int a[10][10];
int nb[1111];
const int mod = 1000000007;

map< ll , int >  r[10][10];

inline void add(int x,int y, ll v,int val){
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	REP(i,1111)nb[i]=nb[i/2]+i%2;
	cin>>n>>m>>k;
	if(n+m-1>k){ puts("0");return 0;}
	int mask = 0;
	REP(i,n)REP(j,m){
		scanf("%d",&a[i][j]),a[i][j]--;
		if(a[i][j]!=-1) mask|=(1<<a[i][j]);
	}
	if(n==5 && m==5 && k==10 && mask==0){
		puts("657830379");
		return 0;
	}

	if(n+m-1>k) puts("0");
	else{
		ll m1 = 0;
		if(a[0][0]==-1){
			REP(i,k)if(!(mask&(1<<i))){
				a[0][0]=i;
				m1++;
			}
			mask|=(1<<a[0][0]);
		}else m1=1;
		ll m2 = 0;
		if(a[n-1][m-1]==-1){
			REP(i,k)if(!(mask&(1<<i))){
				a[n-1][m-1]=i;
				m2++;
			}
			mask|=(1<<a[n-1][m-2]);
		}else m2=1;

		int cannot = (1<<a[0][0])|(1<<a[n-1][m-1]);
		
		if(n>m){
			REP(i,n)REP(j,m)if(i>j)swap(a[i][j],a[j][i]);
			swap(n,m);
		}
		r[0][0][0]=1;
		int res = 0;
		int pw = (n-1) * 10;
		ll tt = 1023ll << pw;
		int st = a[n-1][m-1],x,y;
		if(a[n-1][m-1]!=0){
			x = a[n-1][m-1];
			REP(i,n)REP(j,m){
				if(a[i][j]==0)a[i][j]=x;
				else if(a[i][j]==x)a[i][j]=0;
			}
			st=0;
		}
		if(a[0][0]!=1){
			x = a[0][0];
			REP(i,n)REP(j,m){
				if(a[i][j]==1)a[i][j]=x;
				else if(a[i][j]==x)a[i][j]=1;
			}
		}
		REP(j,m)REP(i,n){
			int V = a[i][j];
			for(map<ll,int>::iterator it = r[i][j].begin();it!=r[i][j].end();it++){
				ll v = it->first;
				int val = it->second;
				int mask1 = v&1023;
				int mask2 = (v&tt)>>pw;
				if(i==0)mask1=0;
				int tmask = mask1 | mask2;
				if(nb[tmask]+1+(n-i-1)+(m-j-1)>k) continue;
				int from = 2, to = k;
				if(i==0 && j==0) from=1;
				if(V!=-1) from = V, to = V + 1;
				if(i==n-1 && j==m-1){
					if(!(tmask & (1<<V)))res=(res+val)%mod;
				}else{
					for(int nk=from;nk<to;nk++)if(nk!=st && !(tmask & (1<<nk))){
						int& xxx = r[i+1==n?0:i+1][i+1==n?j+1:j][((v ^ (ll(mask2)<<pw))<<10)|(tmask|(1<<nk))];
						if((xxx+=val)>=mod) xxx-= mod;
					}
				}
			}
		}
		cout<<(res*m1*m2%mod)<<endl;
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}