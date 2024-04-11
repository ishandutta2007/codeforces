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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n;
int a[1111][1111];
int b[1111][1111];

void output(){
	int cnt=0;
	REP(i,n)REP(j,i)if(a[i][j]==1)cnt++;
	cout<<cnt<<endl;
	REP(i,n)REP(j,i)if(a[i][j]==1)cout<<i+1<<' '<<j+1<<"\n";
}
int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif


	int k;
	cin>>n>>k;
	if(k!=2 && k!=3) puts("-1");
	else{
		int nm = n * (n-1)/2;
		REP(mask,100){
			int pos = 0;
			int type = (k==3) && n>50;
			CL(a,-1);CL(b,-1);
			REP(i,n)a[i][i]=b[i][i]=0;
			REP(i,n)REP(j,i){
				int val = rand()%2;
				if (n>10 && type) {
					if(i==1 && j==0) val = 0;
					else if (i==2 && j==1) val=0;
					else if(i==2 && j==0) val = 1;
					else if(i==6 && j==5) val = 1;
					else if(i==7 && j==6) val = 1;
					else if(i==7 && j==5) val = 0;
					else if(j==0) val = 0;
					else if(j==2) val = 1;
				}
				if(val/*mask&(1<<pos)*/) a[i][j]=a[j][i]=1;
				else b[i][j]=b[j][i]=1;
				pos++;
			}
			if(n>200){
				output();return 0;
			}else{
				REP(k,n)REP(i,n)REP(j,n)if(a[i][k]!=-1 && a[k][j]!=-1)
					if(a[i][j]==-1 || a[i][j]>a[i][k]+a[k][j])a[i][j]=a[i][k]+a[k][j];
				REP(k,n)REP(i,n)REP(j,n)if(b[i][k]!=-1 && b[k][j]!=-1)
					if(b[i][j]==-1 || b[i][j]>b[i][k]+b[k][j])b[i][j]=b[i][k]+b[k][j];
				bool g = 1;
				int d1=0,d2=0;
				REP(i,n)REP(j,n){
					d1=max(d1,a[i][j]);
					d2=max(d2,b[i][j]);
					if(a[i][j]==-1 || b[i][j]==-1)g=0;
				}
				if(g) {
					int z = min(d1,d2);
					if(z==k) {output();return 0;}
				}
			}
		}
		puts("-1");
	}

	
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}