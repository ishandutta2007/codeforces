#pragma comment(linker, "/STACK:60777216")  

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

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int err;
vector<char> best;

vector<char> curr;
int n,r;
int it;

void go(int pos,int f1,int f2,int errors){
	//cout<<pos<<' '<<f1<<' '<<f2<<' '<<errors<<endl;
	if(err<=errors) return;
	if(pos==-1){
		err=errors;
		best=curr;	
	}else{
		if(f1==f2){
			curr[pos] = 'T';
			go(-1,0,0,errors+(pos+1<n&&curr[pos+1]==curr[pos]));
		}else if(f1>f2){
			curr[pos] = 'T';
			go(pos-1,f1-f2,f2,errors+(pos+1<n&&curr[pos+1]==curr[pos]));
		}else{
			curr[pos] = 'B';
			go(pos-1,f1,f2-f1,errors+(pos+1<n&&curr[pos+1]==curr[pos]));
		}
	}
}

int gcd(int a,int b){
	while(a&&b)
		if(a>b) a%=b;
		else b%=a;
	return a+b;
}

int ngcd(int a,int b){
	int res=0;
	while(a&&b)
		if(a>b) res+=a/b,a%=b;
		else res+=b/a,b%=a;
	return res;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>r;
	vi nm;
	for(int other=1;other<=r;other++){
		int g = gcd(other, r);
		if(g==1){
			int t = ngcd(other, r);
			if(t==n){
				nm.pb(other);
			}
		}
	}
	if(nm.size()==0) puts("IMPOSSIBLE");
	else{
		err=n+1;curr.resize(n);
		REP(i,nm.size()){
			go(n-1,r,nm[i],0);
			go(n-1,nm[i],r,0);
		}
		cout<<err<<endl;
		REP(i,best.size()) printf("%c",best[i]);
		puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}