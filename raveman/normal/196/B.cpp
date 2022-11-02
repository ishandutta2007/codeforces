#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

char s[1555][1555];
pii  a[1555][1555];
bool u[1555][1555];
queue<pii> q;
int n,m;

pii getid(int x,int y){
	if(x>=0) x/=n;
	else x=(x+1)/n-1;
	if(y>=0) y/=m;
	else y=(y+1)/m-1;
	return pii(x,y);
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) scanf(" %s",s[i]);
	REP(i,n)REP(j,m) if(s[i][j]=='S'){
		q.push(pii(i,j));
		s[i][j]='.';
		a[i][j] = getid(i,j);
		u[i][j]=1;
	}
	while(!q.empty()){
		pii cc = q.front();q.pop();
		int x = cc.first;
		int y = cc.second;
		FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
			int nx = x + dx;
			int ny = y + dy;
			int tx = (nx%n + n ) % n;
			int ty = (ny%m + m ) % m;
			if(s[tx][ty]=='.'){
				if(u[tx][ty] && a[tx][ty]!=getid(nx,ny)){
					puts("Yes");
					return 0;
				}
				if(u[tx][ty]) continue;
				u[tx][ty]=1;
				a[tx][ty]=getid(nx,ny);
				q.push(pii(nx,ny));
			}
		}
	}
	puts("No");

#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}