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

int n;
int f[111111];
int s[111111];

vi v[111111];

vector<pii> res;

bool forb;
int f_a,f_b,f_c;
bool u[111111];

void dfs(int ver,int par=-1){
	if(u[ver]) return;
	u[ver]=true;
	REP(i,v[ver].size()){
		if(v[ver][i]==par) continue;
		if(u[v[ver][i]] && !forb){
			forb = true;
			f_a = par;
			f_b = ver;
			f_c = v[ver][i];
		}
		dfs(v[ver][i],ver);
	}
}

int G_TYPE;
bool w[111111][2][2];
pii  R[111111][2][2];
int  c[111111][2][2];

pii solve(int ver,int take,int par){
	if(w[ver][take][G_TYPE]) return R[ver][take][G_TYPE];

	vector<pii> v1,v2;
	vi vv;

	REP(i,v[ver].size()){
		if(v[ver][i] == par) continue;
		if(forb && G_TYPE==0 && (ver == f_a && v[ver][i] == f_b || ver == f_b && v[ver][i] == f_a)) continue;
		if(forb && G_TYPE==1 && (ver == f_c && v[ver][i] == f_b || ver == f_b && v[ver][i] == f_c)) continue;

		pii t1 = solve(v[ver][i], 0, ver);
		pii t2 = solve(v[ver][i], 1, ver);
		v1.pb(t1);
		v2.pb(t2);
		vv.pb(v[ver][i]);
	}

	pii r;
	REP(i,v1.size()){
		pii t1 = v1[i];
		pii t2 = v2[i];

		if(t1.first > t2.first || t1.first == t2.first && t1.second >= t2.second){
			r.first += t1.first;
			r.second += t1.second;
		}else{
			r.first += t2.first;
			r.second += t2.second;
		}
	}
	if(take==0){
		return w[ver][take][G_TYPE]=1,R[ver][take][G_TYPE]=r;
	}else{
		pii best=r;
		REP(i,vv.size()){
			int nver = vv[i];
			
			pii t1 = v1[i];
			pii t2 = v2[i];

			pii t = r;
			if(t1.first > t2.first || t1.first == t2.first && t1.second >= t2.second){
				t.first -= t1.first;
				t.second -= t1.second;
			}else{
				t.first -= t2.first;
				t.second -= t2.second;
			}

			t.first += t1.first;
			t.second += t1.second;
			
			t.first ++;
			if(s[ver] != s[nver]) t.second++;
			
			if(t.first > best.first || t.first == best.first && t.second > best.second){
				best=t;
				c[ver][take][G_TYPE]=nver;
			}
		}
		return w[ver][take][G_TYPE]=1,R[ver][take][G_TYPE]=best;
	}
}

pii solve(int ver,int type){
	G_TYPE = type;
	pii t1 = solve(ver, 0, -1);
	pii t2 = solve(ver, 1, -1);
	if(t1.first > t2.first || t1.first==t2.first && t1.second >= t2.second) return t1;
	return t2;
}

void add(int ver,int take,int par){
	if(take && c[ver][take][G_TYPE]!=-1)
		res.pb(pii(ver,c[ver][take][G_TYPE]));

	REP(i,v[ver].size()){
		if(v[ver][i] == par) continue;
		if(forb && G_TYPE==0 && (ver == f_a && v[ver][i] == f_b || ver == f_b && v[ver][i] == f_a)) continue;
		if(forb && G_TYPE==1 && (ver == f_c && v[ver][i] == f_b || ver == f_b && v[ver][i] == f_c)) continue;

		if(take && c[ver][take][G_TYPE] == v[ver][i]){
			add(v[ver][i], 0, ver);
		}else{
			pii t1 = solve(v[ver][i], 0, ver);
			pii t2 = solve(v[ver][i], 1, ver);

			if(t1.first > t2.first || t1.first == t2.first && t1.second >= t2.second){
				add( v[ver][i], 0, ver);
			}else{
				add(v[ver][i],1,ver);
			}
		}
	}			
}


void add(int ver,int type){
	G_TYPE = type;
	pii t1 = solve(ver, 0, -1);
	pii t2 = solve(ver, 1, -1);
	if(t1.first > t2.first || t1.first==t2.first && t1.second >= t2.second) add(ver, 0, -1);
	else add(ver, 1, -1);
}


int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	CL(c,-1);
	cin>>n;
	REP(i,n){
		scanf("%d %d",f+i,s+i);
		f[i]--;
		v[i].pb(f[i]);
		v[f[i]].pb(i);
	}
	REP(i,n)if(v[i].size()>1){
		if(v[i].size()==2){
			if(v[i][0]==v[i][1]){
				v[i].pop_back();
			}
			continue;
		}
		UN(v[i]);
	}
	int curr_t=0,curr_e=0;
	REP(i,n)if(!u[i]){
		forb=0;
		dfs(i);

		pii r;
		if(!forb){
			r = solve(i,0);
			add(i,0);
		}else{ 
			r = solve(i,0);
			pii r2 = solve(i,1);

			if(r.first < r2.first || r.first == r2.first && r.second < r2.second){
				r = r2;
				add(i,1);
			}else add(i,0);
		}
		curr_t += r.first;
		curr_e += r.second;
	}

	cout<<curr_t<<' '<<curr_e<<endl;
	REP(i,res.size()) printf("%d %d\n",res[i].first+1,res[i].second+1);
	return 0;
}