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

char s[1111111];
int n;
int  p[1111111];
bool u[1111111];
int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	gets(s);
	n=strlen(s);
	int curr=-1;
	p[0]=-1;
	for(int i=1;i<n;i++){
		while(curr>=0 && s[i]!=s[curr+1]) curr=p[curr];
		if(s[i]==s[curr+1]) curr++;
		p[i] = curr;
		if(i!=n-1 && curr>=0) u[curr]=true;
	}

	curr = p[n-1];
	while(curr>=0){
		if(u[curr]){
			REP(i,curr+1) printf("%c",s[i]);
			puts("");
			return 0;
		}
		curr=p[curr];
	}

	puts("Just a legend");



#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}