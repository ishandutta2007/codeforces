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
vector<pii> v[111111];
vi v2[111111];
int d0[111111];

void bfs1(){
	CL(d0,-1);
	d0[n-1]=0;
	queue<int> q;
	q.push(n-1);
	while(!q.empty()){
		int ver = q.front();
		q.pop();
		REP(i,v[ver].size())if(v[ver][i].second==0){
			if(d0[v[ver][i].first]==-1){
				d0[v[ver][i].first]=d0[ver]+1;
				q.push(v[ver][i].first);
			}
		}
	}
}

int d1[111111];

void bfs2(){
	CL(d1,-1);
	d1[0]=0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int ver = q.front();
		q.pop();
		REP(i,v[ver].size()){
			if(d1[v[ver][i].first]==-1){
				d1[v[ver][i].first]=d1[ver]+1;
				q.push(v[ver][i].first);
			}
		}
	}
}

int d2[111111];
int fr[111111];

void bfs3(){
	CL(d2,-1);
	CL(fr,-1);
	d2[0]=0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int ver = q.front();
		q.pop();
		if(d0[ver]==-1){
			REP(i,v2[ver].size()){
				if(d2[v2[ver][i]]==-1){
					d2[v2[ver][i]]=d2[ver]+1;
					fr[v2[ver][i]]=ver;
					q.push(v2[ver][i]);
				}
			}
		}else{
			REP(i,v[ver].size())if(v[ver][i].second==0){
				if(d2[v[ver][i].first]==-1){
					d2[v[ver][i].first]=d2[ver]+1;
					fr[v[ver][i].first]=ver;
					q.push(v[ver][i].first);
				}
			}
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		v[x].pb(pii(y,z));
		v[y].pb(pii(x,z));
	}

	bfs1(); // n-1  - 0
	bfs2(); // 0 - all

	int mn = 1e9;
	REP(i,n)if(d0[i]!=-1 && d1[i]!=-1)mn=min(mn,d1[i]);
	set<int> c;
	REP(i,n)if(d0[i]!=-1 && d1[i]==mn)c.insert(i);

	string s;
	while(!c.empty()){
		set<int> nc;
		int bestdig = 9;
		for(set<int>::iterator it = c.begin();it!=c.end();it++){
			int ver = *it;
			REP(i,v[ver].size()){
				int nver = v[ver][i].first;
				if(d1[nver]>=0 && d1[nver] == d1[ver] - 1){
					bestdig=min(bestdig, v[ver][i].second);
				}
			}
		}
		s.pb('0'+bestdig);
		for(set<int>::iterator it = c.begin();it!=c.end();it++){
			int ver = *it;
			REP(i,v[ver].size()){
				int nver = v[ver][i].first;
				if(d1[nver]>=0 && d1[nver] == d1[ver] - 1 && v[ver][i].second==bestdig){
					nc.insert(nver);
					v2[nver].pb(ver);
				}
			}
		}
		swap(c,nc);
	}
	s.erase(s.end()-1);
	if(s=="")s="0";
	cout<<s<<endl;

	bfs3();
	cout<<d2[n-1]+1<<endl;

	vi t;
	t.pb(n-1);
	while(t.back()!=0){
		int curr = t.back();
		t.pb(fr[curr]);
	}
	reverse(t.begin(),t.end());
	REP(i,t.size()){
		if(i)printf(" ");
		printf("%d",t[i]);
	}
	puts("");
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}