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

const int mod = 1000000009;

int f[333333];
int fs[333333];

int n,m;
int a[333333];
int b[333333];
int X[666];
int Y[666];
int nm;

int st[333333];

bool DO_STUPID = 0;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	f[0]=f[1]=1;
	fs[0]=1;fs[1]=2;
	FOR(i,2,333333){
		f[i]=f[i-1]+f[i-2];
		if(f[i]>=mod)f[i]-=mod;
		fs[i]=fs[i-1]+f[i];
		if(fs[i]>=mod)fs[i]-=mod;
	}
	cin>>n>>m;
	if(DO_STUPID){
		n=5;
		m=20;
	}
	REP(i,n){
		scanf("%d",a+i);
		if(DO_STUPID){
			a[i]=0;//rand();
			st[i]=a[i];
		}
		if(i)a[i]+=a[i-1];
		if(a[i]>=mod) a[i]-=mod;
	}

	int t,x,y,sum,t1,t2,len,start;
	REP(i,m){
		scanf("%d %d %d",&t,&x,&y);
		if(DO_STUPID){
			t=rand()%2+1;
			x=rand()%n+1;
			y=rand()%n+1;
			if(x>y)swap(x,y);
			cout<<t<<' '<<x<<' '<<y<<endl;
		}
		x--,y--;
		if(t==1){
			X[nm]=x;
			Y[nm]=y;
			if (DO_STUPID) {
				FOR(j,x,y+1){
					st[j]+=f[j-x];
					if(st[j]>=mod)st[j]-=mod;
				}
			}
			nm++;
			if(nm==600){
				CL(b,0);
				REP(j,nm){
					if(X[j]==Y[j]){
						b[X[j]]++;
						if(b[X[j]]>=mod)b[X[j]]-=mod;
						b[X[j]+1]--;
						if(b[X[j]+1]<0)b[X[j]+1]+=mod;
						b[X[j]+2]--;
						if(b[X[j]+2]<0)b[X[j]+2]+=mod;
						continue;
					}
					b[X[j]]++;
					if(b[X[j]]>=mod)b[X[j]]-=mod;
					//b[X[j]+1]++;
					//if(b[X[j]+1]>=mod)b[X[j]+1]-=mod;

					b[Y[j]+1]-=f[Y[j]-X[j]+1];
					if(b[Y[j]+1]<0)b[Y[j]+1]+=mod;
					b[Y[j]+2]-=f[Y[j]-X[j]];
					if(b[Y[j]+2]<0)b[Y[j]+2]+=mod;
				}
				int sum = 0;
				REP(j,n){
					b[j]+=(j-1>=0?b[j-1]:0);
					if(b[j]>=mod)b[j]-=mod;
					b[j]+=(j-2>=0?b[j-2]:0);
					if(b[j]>=mod)b[j]-=mod;
					sum+=b[j];
					if(sum>=mod)sum-=mod;
					a[j]+=sum;
					//cout<<j<<' '<<b[j]<<endl;
					if(a[j]>=mod)a[j]-=mod;
				}
				nm=0;
			}
		}else if(t==2){
			sum=a[y]-(x-1>=0?a[x-1]:0);
			if(sum<0)sum+=mod;
			REP(j,nm){
				if(Y[j]<x || X[j]>y) continue;
				t1=(x>X[j]?x:X[j]);
				t2=(y>Y[j]?Y[j]:y);
				len=t2-t1+1;
				start=t1-X[j];
				sum+=fs[start+len-1];
				sum-=(start-1>=0?fs[start-1]:0);
				if(sum>=mod)sum-=mod;
				if(sum<0)sum+=mod;
			}
			if (DO_STUPID) {
				int stres = 0;
				FOR(j,x,y+1){
					stres += st[j];
					if(stres >=mod)stres -=mod;
				}
				cout<<" ! " << stres <<endl;
			}
			printf("%d\n",sum);
		}
	}
	

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}