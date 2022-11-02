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

int n,m;
ll k;
int  d[222];
bool b[222];
bool u[222];

ll r[202][202];

ll calc(int n){
	CL(r,0);
	r[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			//r[i][j]=0;
			if(u[i-1]){
				if(j==0 && b[i-1]) continue;
				r[i][j] = r[i-1][j-(b[i-1]?1:-1)];
			}else{
				if(j) r[i][j] = r[i-1][j-1];
				r[i][j] += r[i-1][j+1];
				if(r[i][j]>=k) r[i][j]=k;
			}
		}
	}
	return r[n][0];
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,n+m) d[i]=1000000;
	REP(i,n)REP(j,m){int x;scanf("%d",&x);d[i+j]=min(d[i+j],x);}

	REP(i,n+m-1){
		int mn = 1000000,pos=-1;
		REP(j,n+m-1)if(!u[j] && d[j]<mn) mn=d[j],pos=j;
		u[pos] = true;
		b[pos] = true;
		ll q = calc(n+m-1);
		//cout<<u[0]<<u[1]<<' '<<b[0]<<b[1]<<' '<<q<<endl;
		if(q>=k) continue;
		b[pos] = false;
		k-=q;
	}


	REP(i,n){
		REP(j,m) printf("%c",b[i+j]?'(':')');
		puts("");
	}


#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}