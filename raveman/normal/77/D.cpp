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

const int mod = 1000000007;

int n,m;
int a[255][255];
string s[5555];

char q[3][3];

// 1 - hor
// 2 - ver
// 0 - both
int getType(){
	int num=0;
	REP(i,3)REP(j,3)if(q[i][j]=='O') num++;
	if(num==0 || num==1 || num==4 || num==5) return 0;
	if(num==2 || num==3){
		if(q[0][0]=='O') return 1;
		return 2;
	}
	if(num==6){
		if(q[0][1]=='O') return 1;
		return 2;
	}
}

int r[255];

bool solvable(int column){
	if(n%2) return 0;
	REP(i,n)if(a[i][column]==1) return 0;
	return 1;
}

int d[255];

int num_solve(int c1){
	int c2 = c1+1;
	int res = 0;

	d[0] = 1;
	FOR(i,1,n+1){
		d[i]=0;
		if(a[i-1][c1]!=2 && a[i-1][c2]!=2)
			d[i] += d[i-1];
		if(i>=2)
			if(a[i-1][c1]!=1 && a[i-1][c2]!=1)
				if(a[i-2][c1]!=1 && a[i-2][c2]!=1)
					d[i] += d[i-2];
		
		if(d[i]>=mod) d[i]-=mod;
	}

	res = d[n];
	if(solvable(c1) && solvable(c2))
		res --;
	if(res<0) res+=mod;
	return res;
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	cin>>n>>m;
	REP(i,4*n+1)cin>>s[i];
	REP(i,n)REP(j,m){
		REP(k1,3)REP(k2,3) q[k1][k2] = s[i*4+1+k1][j*4+1+k2];
		a[i][j]=getType();
		//if(j==m-1) puts("");
	}

	r[0] = 1;
	FOR(i,1,m+1){
		if(solvable(i-1)) 
			r[i] = r[i-1];
		if(i>=2){
			ll num = num_solve(i-2);
			r[i] = (r[i] + num * r[i-2]) % mod;
		}
	}
	cout<<r[m]<<endl;

	return 0;
}