#pragma comment(linker, "/STACK:136777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
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


int n,m;
int a[55];
double res;

vector<double> qq[55][55];
bool u[55][55];

vector<double> getV(int n,int m){
	if(u[n][m]) return qq[n][m];
	vector<double> v1,v2;
	v1.resize(n+1),v2.resize(n+1);
	v1[0]=1;
	if(n>0){
		v1=getV(n-1,m);
		REP(j,n) v2[j]=0;
		REP(j,n) v2[j]+=v1[j]*(m-1.)/m;
		REP(j,n) v2[j+1]+=v1[j]/double(m);
		swap(v1,v2);
	}
	return u[n][m]=1,qq[n][m]=v1;
}

double d[55][55][55];

void go(int n,int pos,int val,double pr){
	if(pos==m){
		res+=val*pr;
		return;
	}
	vector<double> v = getV(n,m-pos);
	REP(i,v.size()){
		int num = (i+a[pos]-1)/a[pos];
		d[n-i][pos+1][max(num,val)]+=pr*v[i];
		//go(n-i,pos+1,max(num,val),pr*v[i]);
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif
	cin>>n>>m;
	REP(i,m) cin>>a[i];
	d[n][0][0]=1;
	for(int pos = 0;pos<=m;pos++)
		for(int i=n;i>=0;i--)
			for(int val=n;val>=0;val--)
				go(i,pos,val,d[i][pos][val]);
	//go(n,0,0,1);
	printf("%.9lf\n",res);
	return 0;
}