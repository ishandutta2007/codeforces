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

string t;
int p[2222222];
string t2;
int z[2222222];
string a,b;
int n;

bool good(int i,int j){
	return z[n+i+2] >= j-i-1;
}

int getJ(int i){
	int best = n - p[2*n-i-1] - 1;
	if(good(i,best)) return best;
	return -1;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	getline(cin,a);
	getline(cin,b);
	if(a.size()!=b.size()){
		puts("-1 -1");
		return 0;
	}
	n=a.size();

	t=a;reverse(t.begin(),t.end());t.pb(0);
	t+=b;
	int curr=-1;
	p[0]=-1;
	for(int i=1;i<=2*n;i++){
		while(curr>=0 && t[i]!=t[curr+1]) curr=p[curr];
		if(t[i]==t[curr+1]) curr++;
		p[i] = curr;
	}

	t2=b;t2.pb(0);t2+=a;
	int l = 0,r = 0;
	for(int i=1;i<t2.size();i++){
		if(i<r)
			z[i] = min(r-i, z[i-l]);
		while(i+z[i]<t2.size() && t2[i+z[i]]==t2[z[i]]) z[i]++;
		if(i+z[i]>r)
			l=i,r=i+z[i];
		//cout<<i<<' '<<z[i]<<endl;
	}

	int r1=-1,r2=-1;
	REP(i,n-1){
		if(a[i]!=b[n-1-i]) break;
		//cout<<i<<endl;
		int j = getJ(i);
		if(j==-1) continue;

		r1 = i, r2 = j;
	}
	cout<<r1<<' '<<r2<<endl;
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}