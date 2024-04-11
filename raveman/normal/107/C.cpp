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

int n,m;
ll y;
vi v[111];
vi w[111];
ll d[1<<16];

int a[22];

void recalc(int pos,int mask){
	CL(d,0);
	d[(1<<n)-1] = 1;
	for(int i=(1<<n)-1;i>=0;i--)if(d[i]){
		int c = 0;
		REP(j,n)if(i&(1<<j)) c++;

		bool found = 0;
		int r_pos = 0;
		REP(j,pos+1) if(a[j]==c-1){
			found = true;
			r_pos = j;
		}

		REP(j,n)if(i&(1<<j)){
			if(found && r_pos!=j) continue;

			bool good = 1;
			REP(k,v[j].size()) if(i&(1<<(v[j][k]))) good = 0;
			if(good) d[i^(1<<j)] += d[i];
		}
	}
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
#ifndef LocalHost
	//freopen("dices.in","r",stdin);
	//freopen("dices.out","w",stdout);
#endif

	cin>>n>>y>>m;y-=2001;
	REP(i,m){
		int x,yy;
		cin>>x>>yy;
		x--,yy--;
		v[x].pb(yy);
		w[yy].pb(x);
	}
	d[(1<<n)-1] = 1;
	for(int i=(1<<n)-1;i>=0;i--)if(d[i]){
		REP(j,n)if(i&(1<<j)){
			bool good = 1;
			REP(k,v[j].size()) if(i&(1<<(v[j][k]))) good = 0;
			if(good) d[i^(1<<j)] += d[i];
		}
	}
	if(d[0] <= y) puts("The times have changed");
	else{
		int mask = 0;
		for(int pos = 0;pos<n;pos++){
			for(int i=0;i<n;i++)if(!(mask&(1<<i))){
				
				mask ^= (1<<i);
				a[pos] = i;
				recalc(pos,mask);
				mask ^= (1<<i);
				
				ll num = d[0];

				if(num>y){
					if(pos) cout<<' ';
					cout<<i+1;
					mask |= (1<<i);
					a[pos] = i;

					recalc(pos,mask);

					break;
				}else y -= num;
			}
		}
		puts("");
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}