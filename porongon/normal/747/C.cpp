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

int n,q;
int w[128];

int main(){
	scanf("%d%d",&n,&q);
	FORN(i,q){
		int t,k,d;
		scanf("%d%d%d",&t,&k,&d);
		int c=0;
		FORN(i,n)if(t>=w[i])c++;
		if(c<k){puts("-1");continue;}
		c=k;
		int r=0;
		FORN(i,n)if(t>=w[i]){
			r+=i+1;
			w[i]=t+d;
			c--;
			if(!c)break;
		}
		printf("%d\n",r);
	}
	return 0;
}