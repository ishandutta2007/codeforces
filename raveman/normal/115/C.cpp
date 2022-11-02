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

const int mod = 1000003;

int row[1111111];
int col[1111111];

int main(){ 

#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,m;
	char c;

	cin>>n>>m;
	REP(i,n){
		REP(j,m){
			scanf(" %c",&c);
			//cout<<c;
			if(c=='.') continue;
			if(c=='1' || c=='2')
				row[i] |= 1<<(j%2);
			else row[i] |= 1<<(1-j%2);

			if(c=='1' || c=='4')
				col[j] |= 1<<(i%2);
			else col[j] |= 1<<(1-i%2);
		}
		//puts("");
	}
	REP(i,n)if(row[i]==3) {
		puts("0");
		return 0;
	}
	REP(i,m)if(col[i]==3){
		puts("0");
		return 0;
	}
	int cc = 0;
	REP(i,n)if(row[i]==0) cc++;
	REP(i,m)if(col[i]==0) cc++;
	int res = 1;
	while(cc){
		res*=2;
		cc--;
		res%=mod;
	}
	cout<<res<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}