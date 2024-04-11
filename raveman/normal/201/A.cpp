#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

bool u[111][111];

void solve(int n,int &n4,int &n2,int &n1){
	n4=0,n2=0,n1=0;
	int N = n;
	if(n%2==0){
		n/=2;
		n--;
		int sum = 0;
		int add = 1;
		int t = n;
		while(t){
			sum += (n + add) / 2;
			n4++;
			add ^= 1;
			t--;
		}
		//return sum * 4;
	}else{
		CL(u,0);
		n/=2;
		int sum = 0;
		REP(i,n)REP(j,n){
			u[i][j]=1;
			if(i && u[i-1][j]) u[i][j]=0;
			if(j && u[i][j-1]) u[i][j]=0;
			if(u[i][j]) sum += 4,n4++;
		}
		REP(i,n) if(!u[i][n-1]) sum += 2, u[i][n]=1,n2++;
		REP(i,n) if(!u[n-1][i]) sum += 2, u[n][i]=1,n2++;
		if(!u[n][n-1] && !u[n-1][n]) sum++,n1++;

	}
}

bool can(int n4,int n2,int n1,int x){
	x -= min(n4,x/4)*4;
	x -= min(n2,x/2)*2;
	x -= min(n1,x);
	return x==0;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int x;	
	cin>>x;
	if(x==2){cout<<3<<endl;return 0;}
	for(int n=1;;n++){
		int n4=0,n2=0,n1=0;
		solve(n,n4,n2,n1);
	//	cout<<n<<' '<<n4<<' '<<n2<<' '<<n1<<' '<<x<<endl;
		if(can(n4,n2,n1,x)){
			cout<<n<<endl;
			return 0;
		}
	}
	
#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}