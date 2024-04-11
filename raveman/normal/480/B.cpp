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

int n,l,x,y;
int a[111111];
set<int> st;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>l>>x>>y;
	REP(i,n)scanf("%d",a+i),st.insert(a[i]);

	bool hasx=0;
	bool hasy=0;
	REP(i,n)if(st.count(a[i]+x))hasx=1;
	REP(i,n)if(st.count(a[i]-x))hasx=1;
	REP(i,n)if(st.count(a[i]+y))hasy=1;
	REP(i,n)if(st.count(a[i]-y))hasy=1;
	if(hasx && hasy) puts("0");
	else if(hasx){
		cout<<1<<endl<<y<<endl;
	}else if(hasy){
		cout<<1<<endl<<x<<endl;
	}else{
		bool fone = false;
		REP(i,n)if(st.count(a[i]+x+y)){
			fone=true;
			cout<<1<<endl<<a[i]+x<<endl;
			break;
		}
		if (!fone) {
			REP(i,n)if(st.count(a[i]+y-x)){
				//cout<<"here "<<' '<<a[i]<<' '<<x<<endl;
				if(a[i]>=x){
					cout<<1<<endl<<a[i]-x<<endl;
					fone=true;
				}else if(a[i]+y<=l){
					cout<<1<<endl<<a[i]+y<<endl;
					fone=true;
				}
				if(fone)break;
			}
		}
		if (!fone) {
			cout<<2<<endl<<x<<' '<<y<<endl;
		}
	}

#ifdef LocalHost
//	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}