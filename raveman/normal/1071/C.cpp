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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back	

int w[1<<14];
pii f[1<<14];
int f2[1<<14];

int h(const vi& p){
	int c = 0;
	REP(i,p.size())c=c*2+p[i];
	return c;
}

vi p1,p2;
bool solve(vi p,int start){
	queue<vi> q;
	q.push(p);
	CL(w,-1);
	w[h(p)]=0;
	int mx = 0;
	while(!q.empty()){
		p = q.front();q.pop();
		int hc = h(p);
		int cost = w[hc];
		REP(x,p.size())FOR(y,x+1,p.size()){
			int z = y + y - x;
			if(z<p.size()){
				vi np=p;
				np[x]^=1;
				np[y]^=1;
				np[z]^=1;
				int c = h(np);
				if(w[c]==-1){
					w[c]=cost+1;
					q.push(np);
					f[c]=pii(x,y);
					f2[c]=hc;
				}
			}
		}
	}
	if(w[0]==-1)return 0;
	int curr = 0;
	while(w[curr]){
		pii x = f[curr];
		p1.pb(x.first+start);
		p2.pb(x.second+start);
		curr = f2[curr];
	}
	return 1;
}

int n;
int a[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	/*FOR(n,8,12){
		int r = 0;
		REP(mask,1<<n){
			vi p;
			REP(i,n)if(mask&(1<<i))p.pb(1);else p.pb(0);
			r=max(r,good(p));
			//if(!good(p)) {cout<<n<<" - fails"<<endl;REP(i,p.size()) cout<<p[i]<<' ';puts("");break;}
		}
		cout<<n<<' '<<r<<endl;
	}*/
	cin>>n;
	REP(i,n)scanf("%d",a+i);
	int start = 0;
	int prev = 0;
	while(n-start>=14){
		if(a[start]==0)start++;
		else{
			if(a[start+1]==0){//10
				if(a[start+2]==0){//100
					p1.pb(start);
					p2.pb(start+3);
				}else{//101
					p1.pb(start);
					p2.pb(start+2);
				}
			}else{//11
				if(a[start+2]==1){//111
					p1.pb(start);
					p2.pb(start+1);
				}else{//110
					if(a[start+3]+a[start+4]+a[start+5]==0){//000
						p1.pb(start);
						p2.pb(start+6);
						p1.pb(start+1);
						p2.pb(start+7);
					}else if(a[start+3]+a[start+4]+a[start+5]==1){//001
						int p = (a[start+3]==1?start+3:(a[start+4]==1?start+4:start+5));
						p1.pb(start);
						p2.pb(p);
						p1.pb(start+1);
						p2.pb(start+7);
					}else if(a[start+3]+a[start+4]+a[start+5]==2){//011
						FOR(x1,start+3,start+6)if(a[x1]){
							FOR(x2,x1+1,start+6)if(a[x2]){
								p1.pb(start);
								p2.pb(x1);
								p1.pb(start+1);
								p2.pb(x2);
								break;
							}
							break;
						}
					}else{//111
						p1.pb(start+1);
						p2.pb(start+3);
						
						p1.pb(start);
						p2.pb(start+4);
					}
				}
			}
		}
		while(prev<p1.size()){
			a[p1[prev]]^=1;
			a[p2[prev]]^=1;
			a[p2[prev]+p2[prev]-p1[prev]]^=1;
			prev++;
		}
	}

	int rstart=start;
	vi rem;
	while(start<n){
		rem.pb(a[start]);
		start++;
	}
	if(solve(rem,rstart)){
		puts("YES");
		cout<<p1.size()<<endl;
		REP(i,p1.size()){
			cout<<p1[i]+1<<' '<<p2[i]+1<<' '<<p2[i]+1+p2[i]+1-p1[i]-1<<'\n';
		}
	}else{
		puts("NO");
	}



	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}