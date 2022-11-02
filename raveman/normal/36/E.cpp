#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n;
vector<pii> v[11111],v2[11111];
int cc;
int u[11111];
int deg[11111];

void dfs(int ver){
	if(u[ver]) return;
	u[ver] = cc;
	if(v[ver].size()%2) deg[cc]++;
	REP(i,v[ver].size())
		dfs(v[ver][i].first);
}

bool used[11111];
vi res;

void dfs2(int ver, int edge = -1){
	REP(i,v[ver].size())if(!used[v[ver][i].second]){
		used[v[ver][i].second] = 1;
		dfs2(v[ver][i].first, v[ver][i].second);
	}
	if(edge!=-1)
		res.pb(edge);
}

void solve(int col){
	int start = -1;
	REP(i,10001)if(u[i]==col && v[i].size()) if(start == -1 || (v[i].size()%2)) start = i;
	res.clear();
	dfs2(start);
	cout<<res.size()<<endl;
	REP(i,res.size()){
		if(i) printf(" ");
		printf("%d",res[i]);
	}
	puts("");
}


bool b[11111];
int  fr[11111];
int  fv[11111];
queue<int> q;

int main(){
	freopen("input.txt","r",stdin);
#ifndef LocalHost    
    freopen("output.txt","w",stdout);
#endif
	int m;
	cin>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(pii(y,i+1));
		v[y].pb(pii(x,i+1));
	}

	if(m==1){
		puts("-1");
		return 0;
	}

	int num = 0;
	REP(i,11111)if(v[i].size()%2) num++;

	if(num!=0 && num!=2 && num!=4){
		puts("-1");
		return 0;
	}

	
	REP(i,11111) if(v[i].size() && !u[i]){
		++cc;
		dfs(i);
	}
	if(cc>2){
		puts("-1");
		return 0;
	}

	if(cc==1){
		if(deg[1]==0){
			REP(i,11111)if(v[i].size()){
				cout<<1<<endl;
				cout<<v[i][0].second<<endl;
				used[v[i][0].second] = 1;				
				break;
			}
			solve(1);
		}else if(deg[1]==2){
			REP(i,11111)if(v[i].size()%2){
				cout<<1<<endl;
				cout<<v[i][0].second<<endl;
				used[v[i][0].second] = 1;
				int edge = v[i][0].second;
				int to = v[i][0].first;
				v[i].erase(v[i].begin());
				REP(j,v[to].size()) if(v[to][j].second == edge){
					v[to].erase(v[to].begin()+j);
					break;
				}
				break;
			}
			solve(1);
		}else{
			vi t;
			REP(i,11111) if(v[i].size()%2) t.pb(i);
			q.push(t[0]);
			b[t[0]] = 1;
			while(!q.empty()){
				int ver = q.front(); q.pop();
				REP(i,v[ver].size()) if(!b[v[ver][i].first]){
					b[v[ver][i].first] = 1;
					fr[v[ver][i].first] = v[ver][i].second;
					fv[v[ver][i].first] = ver;
					q.push(v[ver][i].first);
				}
			}
			int v1 = t[0], v2 = t[1];
			int v3 = t[2], v4 = t[3];
			int q = v2;
			while(q!=v1){
				used[fr[q]] = 1;
				q = fv[q];
			}

			dfs2(v3);
			cout<<res.size()<<endl;
			REP(i,res.size()){
				if(i) printf(" ");
				printf("%d",res[i]);
			}
			puts("");

			q = v2;
			while(q!=v1){
				used[fr[q]] = 0;
				q = fv[q];
			}

			REP(i,11111){
				vector<pii> vv;
				REP(j,v[i].size()) if(!used[v[i][j].second])
					vv.pb(v[i][j]);
				v[i]=vv;
			}

			
			res.clear();
			dfs2(v1);
			cout<<res.size()<<endl;
			REP(i,res.size()){
				if(i) printf(" ");
				printf("%d",res[i]);
			}
			puts("");
		}
	}else{
		if(deg[1] == 4 || deg[2] == 4){
			puts("-1");
			return 0;
		}
		solve(1);
		solve(2);
	}

	return 0;
}