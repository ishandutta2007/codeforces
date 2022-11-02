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
int a[111111];
int b[111111];

int main(){
#ifdef LocalHost

    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif
	
	cin>>n;
	REP(i,n) scanf("%d",a+i),b[i]=a[i];
	sort(a,a+n);
	sort(b,b+n);
	if(a[0]==1000000000) a[0]=999999999;
	else a[0]=1000000000;
	sort(a,a+n);

	if(b[n-1]==1) b[n-1]=2;
	else b[n-1]=1;
	sort(b,b+n);
	REP(i,n){
		if(i) printf(" ");
		printf("%d",min(a[i],b[i]));
	}
	puts("");


	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}