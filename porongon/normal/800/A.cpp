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

int n,p;
int a[100005],b[100005];

bool can(double t){
	double s=0.;
	FORN(i,n){
		if(a[i]*t>b[i]){
			s+=(a[i]*t-b[i])/p;
		}
	}
	return s<t;
}

int main(){
	scanf("%d%d",&n,&p);
	FORN(i,n)scanf("%d%d",a+i,b+i);
	ll z=0;
	FORN(i,n)z+=a[i];
	if(z<=p){puts("-1");return 0;}
	double s=0.,e=1e30;
	FORN(_,200){
		double m=(s+e)/2;
		if(can(m))s=m;
		else e=m;
	}
	printf("%.12lf\n",s);
	return 0;
}

/*
  _____   ____  _____   ____  _   _  _____  ____  _   _
 |  __ \ / __ \|  __ \ / __ \| \ | |/ ____|/ __ \| \ | |
 | |__) | |  | | |__) | |  | |  \| | |  __| |  | |  \| |
 |  ___/| |  | |  _  /| |  | | . ` | | |_ | |  | | . ` |
 | |    | |__| | | \ \| |__| | |\  | |__| | |__| | |\  |
 |_|     \____/|_|  \_\\____/|_| \_|\_____|\____/|_| \_|

*/