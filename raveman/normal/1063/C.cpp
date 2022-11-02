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
#include<unordered_map>
#include<unordered_set>

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

int main(){	
#ifdef LocalHost
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	cout<<"0 0"<<endl;
	string c[33];
	cin>>c[0];

	int from = 1;
	int to = 1000000000;
	FOR(i,1,n){
		int t = (from + to) / 2;
		cout<<t<<" 0"<<endl;
		cin>>c[i];

		if(c[i]==c[0]){
			from = t + 1;
		}else{
			to=t-1;
		}
	}

	cout<<from<<" "<<1<<" "<<min(1000000000,from+1)<<" 1000000000"<<endl;
	/*

	if (n == 1){
		cout<<"0 1 1 0"<<endl;
		return 0;
	}
	cout<<"500000000 0"<<endl;
	cin>>c[1];

	if(n==2){
		if(c[0]==c[1]){
			cout<<"1 1 2 1"<<endl;
		}else{
			cout<<"1 0 1 1"<<endl;
		}
		return 0;
	}

	int from = 500000000;
	int to = 1000000000;

	int curr = 1;
	while(c[curr]==c[0] && curr+1<n){
		int t = (from + to) / 2;
		cout<<t<<" 0"<<endl;
		curr++;
		cin>>c[curr];
		if(c[curr]==c[0]) from=t;
		else{
			to=t;
		}
	}
	if(curr==1){
		to=from;
		from=0;
	}
	
	if (curr==n-1){
		cout<<"1 1 2 1"<<endl;
		return 0;
	}

	while(curr+1<n){
		int t = (from+to)/2;
		cout<<t<<" 0"<<endl;
		curr++;
		cin>>c[curr];

		if(c[curr]==c[0]){
			from=t;
		}else{
			to=t;
		}
	}

	cout<<to<<" 1"<<" "<<to+1<<" 1000000000"<<endl;
	*/
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif

	return 0;
}