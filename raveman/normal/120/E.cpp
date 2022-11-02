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

int n;
int a[100][100];
map<ll,bool> r;

bool go(ll mask){
	ll hash = 0;
	REP(i,n)REP(j,n){
		hash = hash *3 + a[i][j]+1;
	}
	if(r.count(hash)) return r[hash];
	REP(i,n)REP(j,n)if(a[i][j]==0){
		a[i][j]=1;
		bool g = 1;
		FOR(dx,-2,3)FOR(dy,-2,3)if(abs(dx)+abs(dy)==3){
			int nx = i + dx;
			int ny = j + dy;
			if(nx>=0 && nx<n && ny>=0 && ny<n)
				if(a[nx][ny]){
					g=0;
					break;
				}
		}
		if(g) if(!go(mask|(1ll<<(i*n+j))))
			return r[hash]=1;
		a[i][j]=0;
	}
	return r[hash]=0;
}
bool isp(int n){
	for(int i=2;i*i<=n;i++)if(n%i==0) return 0;
	return 1;
}
int main(){
	freopen("input.txt","r",stdin);
#ifndef LocalHost
	freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;//CL(a,0);
		cout<<1-(n%2)<<endl;
		//puts(n==1 || n!=2 && isp(n)?"0":"1");
		//if(n==1 || n==3) puts("0");
		//else if(n>=11 && (n-11)%6==0) puts("0");
		//else puts("1");
		//r.clear();//CL(r,-1);
		//cout<<n<<' '<<(go(0)?"0":"1")<<endl;
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}