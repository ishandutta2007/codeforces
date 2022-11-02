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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,m;
int a[111111];
int a1[111111];
int a2[111111];
int nb[1<<13];

const int N1 = 13;
int c[N1+1][1<<(20-N1)];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	string s;
	getline(cin,s);
	REP(i,n){
		getline(cin,s);
		REP(j,m)if(s[j]=='1')a[j]|=1<<i;
	}
	REP(i,1<<13)nb[i]=nb[i/2]+i%2;
	int n1 = min(n,N1);
	int fn1 = (1<<n1)-1;
	int n2 = n - n1;
	int t,sum,v;
	int best = n*m;
	REP(i,m)a1[i]=a[i]&fn1,a2[i]=a[i]>>n1;
	REP(m1,1<<n1){
		CL(c,0);
		REP(j,m)c[nb[a1[j] ^ m1]][a2[j]]++;
		REP(m2,1<<n2){
			sum=0;
			REP(fnb,n1+1)REP(fm2,1<<n2)if(v=c[fnb][fm2]){
				t=fnb+nb[fm2^m2];
				sum += v * min(n-t,t);
			}
			best=min(best,sum);
		}
	}
	cout<<best<<endl;
	
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}