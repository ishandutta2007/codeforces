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

ll mn=-1,mx=-1;
int n;
int pr[33];
int nm[33];
int pos;

ll qp[33][33];

void go(ll a,ll b,ll c,int p=0){
	if(p==pos){
		ll val = (a+1)*(b+2)*(c+2)-a*b*c;
		if(mn==-1 || mn>val) mn = val;
		if(mx==-1 || mx<val) mx = val;
	}else{
		REP(i1,nm[p]+1)REP(i2,nm[p]+1-i1){
			int i3 = nm[p] - i1 - i2;
			go(a*qp[p][i1],b*qp[p][i2],c*qp[p][i3],p+1);
		}
	}
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n;
	for(int i=2;i*i<=n;i++){
		int c = 0;
		while(n%i==0){
			n/=i;
			c++;
		}
		if(c){
			pr[pos] = i;
			nm[pos] = c;
			pos++;
		}
	}
	if(n>1){
		pr[pos] = n;
		nm[pos] = 1;
		pos++;
	}
	REP(i,pos){
		qp[i][0] = 1;
		FOR(j,1,nm[i]+1){
			//cout<<i<<' '<<j<<endl;

			qp[i][j] = qp[i][j-1] * pr[i];
		}
	}
	
	//return 0;
	go(1,1,1);
	cout<<mn<<' '<<mx<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}