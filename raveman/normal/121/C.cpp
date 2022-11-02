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

int n,k;

ll f[20];

int solve1(int n,ll c = 0){
	if(c>n) return 0;
	int res = 0;
	if(c && c<=n) res++;
	res += solve1(n,c*10+4);
	res += solve1(n,c*10+7);
	return res;
}

bool good(int c){
	if(c==0) return 1;
	if(c%10==4 || c%10==7) return good(c/10);
	return 0;
}

int solve2(int n,int start,int k){
	//cout<<n<<' '<<start<<' '<<k<<endl;
	vi v;
	int mask = 0;
	while(v.size()!=n){
		for(int i=0;i<n;i++)if(!(mask&(1<<i))){
			if(k<=f[n-v.size()-1]){
				v.pb(i);
				mask|=(1<<i);
				break;
			}else k-=f[n-v.size()-1];
		}
	}
	int res = 0;
	REP(i,v.size()){
		//cout<<v[i]<<' ';
		if(good(v[i]+start) && good(i+start)) res++;
	}
	//puts("");
	return res;
}


int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	f[0]=1;
	for(int i=1;i<20;i++)f[i]=f[i-1]*i;
	cin>>n>>k;

	if(n<14 && k>f[n]) puts("-1");
	else{
		int res = 0;
		for(int i=0;i<=n;i++)if(f[i]>=k){
			res += solve1(n-i);
			res += solve2(i,n-i+1,k);
			break;
		}
		cout<<res<<endl;
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}