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

int n,k,r;
bool x[200005];  // 1->must use winter
vi w;

int doit(vi w, int k){
	int r=0,s=0;
	sort(w.begin(),w.end());
	FORN(i,w.size())s+=w[i];
	while(s>k){
		s-=w.back();
		r+=2;
		w.pop_back();
	}
	return r;
}

int main(){
	r=1<<30;
	scanf("%d%d",&n,&k);
	int s=0;
	FORN(i,n){
		int t;
		scanf("%d",&t);
		x[i]=t<0;
		s+=x[i];
	}
	if(s>k){puts("-1");return 0;}
	k-=s;
	int i=0;
	while(i<n&&!x[i])i++;
	if(i==n){puts("0");return 0;}
	while(i<n){
		while(i<n&&x[i])i++;
		int j=i;
		while(j<n&&!x[j])j++;
		if(j>i)w.pb(j-i);
		i=j;
	}
	if(x[n-1]){
		r=doit(w,k);
	}
	else {
		int p=w.back();
		w.pop_back();
		r=1+doit(w,k);
		if(k-p>=0){
			r=min(r,doit(w,k-p));
		}
	}
	printf("%d\n",1+r);
	return 0;
}