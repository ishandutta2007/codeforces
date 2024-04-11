#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n;
int a[111111];
int b[111111];

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n;
	int s=0;
	REP(i,n) scanf("%d",a+i),s+=a[i];
	ll res = 0;
	if(s%3){
		puts("0");
		return 0;
	}
	s/=3;
	int t = 0;
	REP(i,n){
		t+=a[i];
		if(t==s) b[i]=1;
		if(i) b[i]+=b[i-1];
	}
	t=0;
	for(int i=n-1;i>=2;i--){
		t+=a[i];
		if(t==s){
			res+=b[i-2];
		}
	}
	cout<<res<<endl;
	return 0;
}