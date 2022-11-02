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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int a[111111];
unsigned char d[8][100001][60];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n){
		scanf("%d",a+i);
		REP(j,60)d[0][i][j]=(j%a[i]==0?1:0);
	}
	FOR(st,1,8){
		REP(i,n)if(i+(1<<st)<=n){
			REP(j,60)
				d[st][i][j]=d[st-1][i+(1<<(st-1))][(j+d[st-1][i][j]+(1<<(st-1)))%60]+d[st-1][i][j];
		}
	}
	int q;
	cin>>q;
	char c;
	int x,y,t;
	REP(tc,q){
		scanf(" %c %d %d",&c,&x,&y);
		
		if(c=='A'){
			x--,y--;
			int res = 0;
			while(x<y){
				for(int st=7;st>=0;st--){
					if(((x>>st)<<st)!=x)continue;
					if(x+(1<<st)<=y){
						res += d[st][x][res%60]+(1<<st);
						x+=(1<<st);
						break;
					}
				}
			}
			printf("%d\n",res);
		}else if(c=='C'){
			x--;
			REP(j,60)d[0][x][j] = (j%y==0?1:0);
			for(int st=1;st<=7;st++){
				x>>=st;
				x<<=st;
				REP(j,60){
					d[st][x][j]=d[st-1][x+(1<<(st-1))][(j+d[st-1][x][j]+(1<<(st-1)))%60]+d[st-1][x][j];
				}
			}
		}
	}


	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}