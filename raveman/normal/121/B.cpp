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
char s[111111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	scanf(" %s",s);
	//n=100000;
	//k=1000000000;
	//REP(i,n)s[i]=(rand()%2?'4':'7');
	for(int i=0;i<n-1;){
		if(i+2<n && (i%2)==0 && s[i]=='4' && s[i+1]=='4' && s[i+2]=='7'){
			k%=2;
		}
		if(k==0) break;
		if(s[i]=='4' && s[i+1]=='7'){
			if(i%2){s[i]='7';}
			else{s[i+1]='4';}
			k--;
			i--;
			i=max(i,0);
		}else i++;
	}
	cout<<s<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}