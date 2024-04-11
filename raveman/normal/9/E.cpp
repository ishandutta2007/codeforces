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
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n,m;
int a[55][55];
int c,s;
bool u[55];

void dfs(int ver){
	if(u[ver]) return;
	u[ver]=1;c++;
	REP(i,n)if(a[ver][i]) s+=a[ver][i],dfs(i);
}

bool good(){
	vi v(n);
	REP(i,n) REP(j,n) if(a[i][j]) v[i]+=a[i][j];
	REP(i,n) if(v[i]>2) return 0;

	int sum=0;
	REP(i,n)REP(j,n) sum+=a[i][j];

	if(sum==2*n){
		c=0;CL(u,0);
		dfs(0);
		return c==n;
	}else{
		CL(u,0);
		REP(i,n) if(!u[i]){
			c=0,s=0;
			dfs(i);
			if(s>=c*2) return 0;
		}
	}

	return 1;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m ){
		int x,y;
		cin>>x>>y;
		x--,y--;
		a[x][y]++;
		a[y][x]++;
	}
	if(good()){
		puts("YES");
		cout<<n-m<<endl;
		REP(i,n) REP(j,n){
			while(1){
				a[i][j]++;a[j][i]++;
				if(!good()) {a[i][j]--,a[j][i]--;break;}
				else cout<<i+1<<' '<<j+1<<endl;
			}
		}
	}else puts("NO");

    return 0;
}