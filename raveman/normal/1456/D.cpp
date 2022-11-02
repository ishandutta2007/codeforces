//#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int t[5555];
int x[5555];

bool u[5555][5555];
bool f;

set<pii> q;

int d[5555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>t[i+1]>>x[i+1];
	CL(d,-1);
	d[0]=0;
	q.insert(pii(0,0));
	u[0][0]=1;
	queue<pii> q2;
	q2.push(pii(0,0));
	int real,clone,tt;
	while(!q.empty() || !q2.empty()){
		if(!q2.empty()){
			real=q2.front().first;
			clone=q2.front().second;
			q2.pop();
		}else{
			tt = q.begin()->first;
			clone = q.begin()->second;
			q.erase(q.begin());

			//cout<<"@: "<<clone<<" "<<tt<<endl;


			int tm = tt;
			if(clone+1<=n)if(abs(x[clone+1]-x[clone])<=t[clone+1]-tm){
				if(!u[clone+1][clone+1]){
					u[clone+1][clone+1]=1;
					q2.push(pii(clone+1,clone+1));
				}
			}
			for(int jp=clone+2;jp<=n;jp++){
				ll t1 = tm + ll(abs(x[jp]-x[clone]));
				t1 = max(t1,(ll)t[clone]);
				if(abs(x[jp]-x[clone+1])<=t[clone+1]-t1){
					if(!u[clone+1][jp]){
						u[clone+1][jp]=1;
						q2.push(pii(clone+1,jp));
					}
				}
			}

			continue;
		}

		//cout<<real<<' '<<clone<<" = "<<endl;

		if(real==n || clone==n && real==n-1)f=1;
			
		if(real==clone-1 || real==clone){
			if(clone+1<=n) if(abs(x[clone+1]-x[real])<=t[clone+1]-t[real]){
				if(!u[clone+1][clone+1]){
					u[clone+1][clone+1]=1;
					q2.push(pii(clone+1,clone+1));
				}
			}
			int posx = x[real];
			ll tm = t[real];
			for(int jp=clone+1;jp<=n;jp++){
				tm+=abs(x[jp]-posx);
				tm=max(tm,(ll)t[jp-1]);
				if(tm<=t[jp]){
					posx=x[jp];
					if(d[jp]==-1 || d[jp]>tm){
						if(d[jp]!=-1)q.erase(pii(d[jp],jp));
						d[jp]=tm;
						q.insert(pii(d[jp],jp));
					}
				}else break;
			}

			for(int jp=clone+2;jp<=n;jp++){
				ll t1 = t[real] + ll(abs(x[jp]-x[real]));
				t1 = max(t1,(ll)t[clone]);
				if(abs(x[jp]-x[clone+1])<=t[clone+1]-t1){
					if(!u[clone+1][jp]){
						u[clone+1][jp]=1;
						q2.push(pii(clone+1,jp));
					}
				}
			}
		}else if(real<clone-1){
			if(abs(x[real+1]-x[real])<=t[real+1]-t[real]){
				if(!u[real+1][clone]){
					u[real+1][clone]=1;
					q2.push(pii(real+1,clone));
				}
			}
		}else{
			puts("fuck");
		}
	}
	puts(f?"YES":"NO");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}