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

ll n,m,k;
int x[111111];
int y[111111];
ll  r[111111];

int gcd(int a,int b){
	while(a&&b){
		if(a>b)a%=b;
		else b%=a;
	}
	return a+b;
}


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,k)scanf("%d %d",x+i,y+i);

	int g = 2 * gcd(n,m);
	int g2 = gcd(n,m);

	int nn = 2 * n / g;
	int mm = 2 * m / g;
	int k1,k2;
	REP(i,mm){
		ll t1 = ll(i)*nn - 1;
		if(t1%mm==0){
			k1 = i;
			k2 = t1 / mm;
		}
	}
	CL(r,-1);
	REP(i,k){
		ll X = x[i];
		ll Y = y[i];

		REP(j,4) {
			//X + 2*n*t1 = Y + 2 * m * t2
			ll xx,yy;
			if(j==0 || j==1) xx = X;
			else xx = (2*n - X);
			if(j==0 || j==2) yy = Y;
			else yy = (2*m - Y);

			ll z = yy - xx;
			// 2nt1-2mt2 = z
			if (z % g == 0) {
				z /= g;
				ll t1 = k1 * z;
				ll t2 = k2 * z;

 
				if (t1<0){
					ll c = -t1 / (m/g2)+10;
					t1 += c * (m/g2);
					t2 += c * (n/g2);
				}
				if(t1>0){
					ll c = t1 / (m/g2);
					t1 -= c * (m/g2);
					t2 -= c * (n/g2);
				}
				//cout<<t1<<' '<<t2<<endl;
				if(t1>=0 && t2>=0){
					ll XXX = xx + 2 * n * t1;
					//cout<<"!"<<XXX<<' '<<xx<<' '<<n*m/g2<<endl;
					if (XXX<= n * m / g2) if(r[i]==-1 || r[i]>XXX) r[i]=XXX;
				}
			}
		}
	}

	//cout<<z.size()<<' '<<z[0].first<<' '<<z[0].second<<endl;
	
	REP(i,k)cout<<r[i]<<"\n";

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}