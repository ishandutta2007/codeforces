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
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

int n,k1,k2;
int a[1<<20],b[1<<20],x[1<<20];

int main(){
	scanf("%d%d%d",&n,&k1,&k2);
	FORN(i,n)scanf("%d",a+i);
	FORN(i,n)scanf("%d",b+i);
	FORN(i,n)x[i]=abs(a[i]-b[i]);
	FORN(_,k1+k2){
		int k=max_element(x,x+n)-x;
		if(x[k])x[k]--;
		else x[k]++;
	}
	ll r=0;
	FORN(i,n)r+=1LL*x[i]*x[i];
	printf("%lld\n",r);
	return 0;
}