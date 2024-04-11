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

int h1,h2,n;
int v[111];
char c[111];
int a[111];
int b[111];

const double eps = 1e-9;

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>h1>>h2>>n;
	REP(i,n) cin>>v[i]>>c[i]>>a[i]>>b[i];

	int best = 0;

	for(int i=-200;i<=200;i++){
	//FOR(i,-6,-5){
		bool good = 1;
		int sum = 0;
		set<int> used;

		int x1 = 0;
		int y1 = h1;
		int x2 = 100000;
		int y2 = h2 + i * 100;
		if(i%2) y2 = 100-h2+i*100;
		//cout<<y2<<endl;
		if(i>0){
			REP(j,i){
				int y = 100 + 100 * j;
				double x = double(x2-x1)/(y2 - y1)*(y-y1);

				bool found = 0;
				REP(k,n)if(a[k]<=x+eps && b[k]>=x-eps){
					if(j%2==0 && c[k]=='T' || j%2==1 && c[k]=='F'){
						if(used.count(k)) good=0;
						used.insert(k);
						sum += v[k];
						found = 1;
						break;
					}
				}
				if(!found) good=0;
			}
		}else if(i<0){
			REP(j,-i){
				int y = - 100 * j;
			//	cout<<y<<endl;
				double x = double(x2-x1)/double(y2 - y1)*(y-y1);
				//cout<<x<<endl;
				bool found = 0;
				REP(k,n)if(a[k]<=x+eps && b[k]>=x-eps){
					if(j%2==0 && c[k]=='F' || j%2==1 && c[k]=='T'){
						if(used.count(k)) good=0;
			//			cout<<"FOUND "<<v[k]<<endl;
						used.insert(k);
						sum += v[k];
						found = 1;
						break;
					}
				}
				if(!found) good=0;//,puts("NOT FOUND");
			}
		}

		if(good) best = max(best, sum);
	}

	cout<<best<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}