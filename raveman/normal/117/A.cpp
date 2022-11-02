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

int n,m;
int getFirstTime(int s,int t){
	s--;
	int val1 = s + (t/2/m)*2*m;
	while(val1<t) val1 += 2*m;
	while(val1-2*m>=t) val1-= 2*m;

	int val2 = 2*m-s + (t/2/m)*2*m;
	while(val2<t) val2 += 2*m;
	while(val2-2*m>=t) val2-= 2*m;

	return min(val1,val2);
}


int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>n>>m;m--;
	REP(i,n){
		int s,f,t;
		scanf(" %d %d %d",&s,&f,&t);
		if(s==f) printf("%d\n",t);
		else{
			int res = getFirstTime(s,t);
			res = getFirstTime(f, res);
			printf("%d\n",res);
		}
	}
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}