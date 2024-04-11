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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int m,n;
int t[111111];
int x[111111];
int l[111111];
int c[111111];
ll  p[111111];

vi s;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>m;
	REP(i,m){
		scanf("%d", t+i);
		if(t[i]==1) scanf("%d",x+i);
		else scanf("%d %d",l+i,c+i);
	}
	cin>>n;
	REP(i,n)cin>>p[i],p[i]--;
	ll curr_len = 0;
	int curr_pos = 0;
	REP(i,m){
		if(curr_pos>=n) break;
		if(t[i]==1){
			if(curr_len == p[curr_pos]){
				if(curr_pos)printf(" ");
				printf("%d",x[i]);
				curr_pos++;
			}
			if(s.size() <= 100000) s.pb(x[i]);
			++curr_len;
		}else{
			while(curr_pos < n && curr_len + l[i]*c[i] > p[curr_pos]) {
				if(curr_pos)printf(" ");
				printf("%d",s[(p[curr_pos] - curr_len)%l[i]]);
				curr_pos++;
			}
			REP(j,l[i]*c[i]){
				if(s.size() > 100000) break;
				s.pb(s[j%l[i]]);
			}
			curr_len += l[i]*c[i];
		}
	}
	puts("");
	
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}