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

int n,m,k;
string s[55];
bool u[33];

string res;
bool f = 0;

const int inf = 1011111111;
int d[55][55];

void bfs(int X,int Y){
	REP(i,n)REP(j,m)d[i][j]=inf;
	d[X][Y]=0;
	queue<pii> q;
	q.push(pii(X,Y));
	while(!q.empty()){
		pii w = q.front();q.pop();
		int x = w.first;
		int y = w.second;
		FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
			int nx = x + dx;
			int ny = y + dy;
			if(nx>=0 && ny>=0 && nx<n && ny<m){
				if(s[nx][ny]=='S' || s[nx][ny]=='T' || s[nx][ny]>='a' && s[nx][ny]<='z' && u[s[nx][ny]-'a'])
					if(d[nx][ny]==inf){
						d[nx][ny] = d[x][y] + 1;
						q.push(pii(nx,ny));
					}
			}
		}
	}
}

string solve(){
	if(u[1] && u[2])
		u[1]=u[1];
	int x,y,X,Y;
	REP(i,n)REP(j,m)if(s[i][j]=='S')x=i,y=j;
	else if(s[i][j]=='T') X=i,Y=j;

	bfs(X,Y);

	if(d[x][y]==inf) return "-1";
	set<int> st;
	string res="";
	st.insert(x*100+y);
	while(st.size()){
		vector<pair<char,int> > v;
		for(set<int>::iterator it = st.begin();it!=st.end();it++){
			int x = *it/100;
			int y = *it%100;
			FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
				int nx = x + dx;
				int ny = y + dy;
				if(nx>=0 && ny>=0 && nx<n && ny<m){
					if(s[nx][ny]=='S' || s[nx][ny]=='T' || s[nx][ny]>='a' && s[nx][ny]<='z' && u[s[nx][ny]-'a'])if(d[nx][ny]==d[x][y]-1){
						v.pb(make_pair(s[nx][ny],nx*100+ny));
					}
				}
			}
		}
		if(!v.size()) break;
		SORT(v);
		res += v[0].first;
		st.clear();
		REP(i,v.size()) if(v[i].first == v[0].first)
			st.insert(v[i].second);
	}
	res.erase(res.end()-1);
	return res;
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,n) cin>>s[i];
	REP(i,k) u[i]=true;
	sort(u,u+26);
	do{
		string t = solve();
		if(t!="-1"){
			if(!f || t.size() < res.size() || t.size()==res.size() && t<res)
				res=t,f=1;
		}
	}while(next_permutation(u,u+26));

	if(!f) puts("-1");
	else cout<<res<<endl;
	return 0;
}