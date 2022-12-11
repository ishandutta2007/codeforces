#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

int n;
vi q;
bool qq[1024];
int r[1024];

void ask(){
	printf("%d\n",(int)q.size());
	memset(qq,0,sizeof(qq));
	FORN(i,q.size()){
		if(i)putchar(' ');
		printf("%d",q[i]+1);
		qq[q[i]]=1;
	}
	puts("");
	fflush(stdout);
	FORN(i,n){
		int x;
		scanf("%d",&x);
		if(!qq[i])r[i]=min(r[i],x);
	}
}

vii w;
vii w2;
vi q0;
vi q1;

bool ready(){
	FORN(i,w.size())if(w[i].snd-w[i].fst>1)return 0;
	return 1;
}

int main(){
	scanf("%d",&n);
	FORN(i,n)r[i]=1<<30;
	w.pb(mp(0,n));
	while(!ready()){
		w2.clear();q0.clear();q1.clear();
		FORN(i,w.size()){
			int s=w[i].fst;
			int e=w[i].snd;
			int m=(s+e)/2;
			FOR(j,s,m)q0.pb(j);
			FOR(j,m,e)q1.pb(j);
			if(m-s>1)w2.pb(mp(s,m));
			if(e-m>1)w2.pb(mp(m,e));
		}
		q=q0;ask();
		q=q1;ask();
		w=w2;
	}
	puts("-1");
	FORN(i,n){
		if(i)putchar(' ');
		printf("%d",r[i]);
	}
	puts("");
	fflush(stdout);
	return 0;
}