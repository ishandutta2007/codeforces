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

int n,m;
int  p[2222];
int  w[2222];
bool u[2222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,2*n)cin>>p[i];
	CL(w,-1);
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		w[x]=y;
		w[y]=x;
	}
	int t;
	cin>>t;

	REP(i,2*n){
		if(t==1 && i%2==0 || t==2 && i%2==1){
			// i move
			// pairs
			bool f = 0;
			REP(j,2*n)if(!u[j] && w[j]!=-1){
				int t1 = j;
				int t2 = w[j];
				if(p[t1]<p[t2])swap(t1,t2);
				cout<<t1+1<<endl;
				u[t1]=1;
				cout.flush();
				f=1;
				break;
			}
			// not pairs
			if(!f){
				int z = -1;
				REP(j,2*n)if(!u[j]){
					if(z==-1 || p[z]<p[j])z=j;
				}
				cout<<z+1<<endl;
				u[z]=1;
				cout.flush();
			}
		}else{
			// he moves
			int x;
			cin>>x;
			x--;
			u[x]=true;
			if(w[x]!=-1 && !u[w[x]]){
				u[w[x]]=1;
				cout<<w[x]+1<<endl;
				cout.flush();
				i++;
				continue;
			}
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}