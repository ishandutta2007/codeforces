#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m;
string s[1111111];
int shit[1111111];


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>n>>m;
	getline(cin,s[0]);
	REP(i,n)getline(cin,s[i]);
	REP(i,n)REP(j,m)if(s[i][j]=='X' && i-1>=0 && j+1<m && s[i-1][j+1]=='X') {
		shit[j]=1;
		//cout<<j<<endl;
	}
	REP(i,m)shit[i]=shit[i]+(i>0?shit[i-1]:0);
	int q;
	cin>>q;
	REP(i,q){
		int x1,x2;
		scanf("%d %d",&x1,&x2);
		x1--,x2--;
		int sum = shit[x2-1]-(x1-1>=0?shit[x1-1]:0);
		puts(sum?"NO":"YES");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}