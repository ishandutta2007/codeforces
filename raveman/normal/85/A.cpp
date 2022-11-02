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

int a[4][111];
char c[4][111];

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	int num = 1;
	REP(i,n/2){
		a[0][i*2]=a[0][i*2+1]=num;
		num++;
		a[1][i*2]=a[1][i*2+1]=num;
		num++;
	}
	if(n%2){
		a[0][n-1]=a[1][n-1]=num;
		num++;
	}
	REP(i,(n-1)/2){
		a[2][1+i*2]=a[2][2+i*2]=num;
		num++;
		a[3][1+i*2]=a[3][2+i*2]=num;
		num++;
	}
	a[2][0]=a[3][0]=num;
	num++;
	if(n%2==0){
		a[2][n-1]=a[3][n-1]=num;
		num++;
	}

	REP(i,4) REP(j,n+1) c[i][j]=0;
	REP(i,4)REP(j,n)if(!c[i][j]){
		int mask = 0;
		FOR(dx,-1,3)FOR(dy,-1,3){
			int x = i + dx;
			int y = j + dy;
			if(x>=0 && x<4 && y>=0 && y<n && c[x][y])
				mask|=(1<<(c[x][y]-'a'));
		}
		c[i][j]='a';
		while(mask&(1<<(c[i][j]-'a')))
			c[i][j]++;
		if(a[i][j+1]==a[i][j]) c[i][j+1]=c[i][j];
		else c[i+1][j] = c[i][j];
	}
	REP(i,4) cout<<c[i]<<endl;


	return 0;
}