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

char s1[111111];
char s2[111111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	gets(s1);
	gets(s2);
	int n=strlen(s1);
	int a=0,b=0;
	REP(i,n) if(s1[i]=='4' && s2[i]=='7') a++;
	else if(s1[i]=='7' && s2[i]=='4') b++;
	cout<<max(a,b)<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}