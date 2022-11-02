#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

const int mod = 1000000007;

int n,k;
int a[111111];
int f[111111];
int inv[111111];

int qp(ll c,int st){
	ll r = 1;
	while(st){
		if(st&1) r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

map<int,int> m;

bool lucky(int c){
	while(c){
		int d = c%10;
		c/=10;
		if(d!=4 && d!=7) return 0;
	}
	return 1;
}

ll c(int n,int m){
	if(m>n) return 0;
	if(m==0 || n==m) return 1;
	ll val = f[n];
	val *= inv[m]; val%=mod;
	val *= inv[n-m]; val%=mod;
	return val;
}

int r[1111][1111];

int stupid(){
	int b[1111];
	CL(b,0);
	REP(i,k) b[i]=1;
	sort(b,b+n);
	int res=0;
	do{
		bool good = 1;
		set<int> s;
		REP(i,n)if(b[i]){
			if(lucky(a[i])){
				if(s.count(a[i])) {good=0;break;}
				s.insert(a[i]);	
			}
		}
		if(good) res++;
	}while(next_permutation(b,b+n));
	return res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	f[0]=1;
	FOR(i,1,111111) f[i]=(ll(f[i-1])*i)%mod;
	REP(i,111111) inv[i]=qp(f[i],mod-2);

	cin>>n>>k;
	REP(i,n){
		scanf("%d",a+i);
		//a[i]=rand()%100+1;
	}

	int g = 0;
	REP(i,n)if(lucky(a[i])) m[a[i]]++;
	else g++;

	ll res = 0;
	int pos = 0;
	r[0][0] = 1;
	for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
		int num = it->second;
		for(int j=0;j<1111;j++)if(r[pos][j]){
			r[pos+1][j] += r[pos][j];
			if(r[pos+1][j]>=mod) r[pos+1][j]-=mod;

			r[pos+1][j+1] = (r[pos+1][j+1]+ll(r[pos][j]) * num)%mod;
		}
		pos++;
	}
	REP(i,1111)if(r[pos][i] && i<=k)
		res = (res+ll(r[pos][i])*c(g,k-i))%mod;
	cout<<res<<endl;
	//cout<<stupid()<<endl;
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}