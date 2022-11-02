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

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
#ifndef LocalHost
	//freopen("dices.in","r",stdin);
	//freopen("dices.out","w",stdout);
#endif

	int n;
	cin>>n;
	int best = -1;
	int n4=-1,n7=-1;
	REP(i,n+1){
		int sum = n - 7 * i;
		if(sum>=0 && sum%4==0){
			best= sum/4 + i;
			n4= sum/4;
			n7=i;
		}
	}
	if(best==-1)cout<<-1<<endl;
	else{
		REP(i,n4)printf("4");
		REP(i,n7)printf("7");
		puts("");
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}