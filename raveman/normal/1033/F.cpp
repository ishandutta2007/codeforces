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
#include<unordered_map>
#include<unordered_set>

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

int w,n,m;
int a[4444];
int mk[1<<20];
char s[15];

inline int getnewmask(int mask,int bit, char c){
	if(bit==0){
		if (c=='A') return mask*3+2;
		if (c=='O') return mask*3+0;
		if (c=='X') return mask*3+0;
		if (c=='a') return -1;
		if (c=='o') return mask*3+1;
		if (c=='x') return mask*3+1;
	}else{
		if (c=='A') return mask*3+0;
		if (c=='O') return -1;
		if (c=='X') return mask*3+1;
		if (c=='a') return mask*3+1;
		if (c=='o') return mask*3+2;
		if (c=='x') return mask*3+0;
	}
}

int res;

void go(int currnumber, int currmask,int pos){
	if(currmask<0) return;
	if(pos==w){
		//if( a[currnumber] * mk[currmask]) cout<<currnumber<<' '<<currmask<<endl;
		res += a[currnumber] * mk[currmask];
		return;
	}
	char c = s[pos];
	// 0
	go(currnumber*2, getnewmask(currmask,0,c),pos+1);
	// 1
	go(currnumber*2+1,getnewmask(currmask,1,c),pos+1);
}

int solve(){
	res=0;
	go(0,0,0);
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>w>>n>>m;
	REP(i,n){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	REP(i,1<<w){
		REP(j,1<<w){
			int t = 0;
			for(int k=w-1;k>=0;k--){
				t*=3;
				if(j&(1<<k))t += 2;
				else if(i&(1<<k)) t++;
				else t+=0;
			}
			mk[t]+=a[i];
		}
	}

	REP(i,m){
		scanf(" %s",s);
		printf("%d\n",solve());
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}