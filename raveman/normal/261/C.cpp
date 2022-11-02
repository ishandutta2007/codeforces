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

vi v;
ll res;
int W;
ll C[111][111];

ll c(int n,int m){
	if(m<0 || m>n) return 0;
	return C[n][m];
}

void go(int pos,int num,bool sm = 0){
	if(sm || pos==v.size()){
		int xx = v.size() - pos;

		res += c(xx,W-num);
	}else{
		for(int i=0;i<=v[pos];i++)
			go(pos+1,num+i,i<v[pos]);		
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	for(int i=0;i<100;i++){
		C[i][i]=C[i][0]=1;
		for(int j=1;j<i;j++)C[i][j]=C[i-1][j]+C[i-1][j-1];
	}

	ll n,t;
	cin>>n>>t;

	ll x = t & (t-1);
	if(x) puts("0");
	else{
		int num = 0;
		while(t) num++,t>>=1;
		W=num;
		res = 0;
		n++;

		while(n){
			v.pb(n%2);
			n/=2;
		}
		reverse(v.begin(),v.end());


		go(0,0);

		if(num==1) res--;//check

		cout<<res<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}