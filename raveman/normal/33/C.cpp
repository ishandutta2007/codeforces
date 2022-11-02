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
typedef pair<int,pii> p3i;
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
int s[111111];
int m[111111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d",a+i);

	REP(i,n) s[i]=a[i]+(i?s[i-1]:0);
	
	REP(i,n){
		m[i]=max((i?m[i-1]:0)+a[i],-s[i]);
	}

	int res = m[n-1];

	int t = 0;
	for(int i=n-1;i>=0;i--){
		t-=a[i];
		res=max(res, t + (i?m[i-1]:0));
	}

	cout<<res<<endl;

	return 0;
}