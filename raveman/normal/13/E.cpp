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

const int cell = 333;

int n,m;
int a[111111];
int J[111111];
int F[111111];

void update(int curr){
	int next = curr + a[curr];
	if(next>=n || next/cell!=curr/cell){
		J[curr] = 1;
		F[curr] = curr;
	}else{
		J[curr] = 1 + J[next];
		F[curr] = F[next];
	}
}

pii calc(int curr){
	int end = F[curr];
	
	pii res;
	res.second += J[curr];
	res.first = end;

	int next = end + a[end];

	if(next < n){
		pii t = calc(next);
		res.first = t.first;
		res.second += t.second;
	}

	return res;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	cin>>n>>m;
	REP(i,n) scanf("%d",a+i);
	for(int i=n-1;i>=0;i--) update(i);
	REP(i,m){
		int t;
		scanf("%d",&t);
		if(t==0){
			int x,y;
			scanf("%d %d",&x,&y);
			x--;
			a[x]=y;
			for(int j=x;;j--){
				update(j);
				if(j%cell==0) break;
			}
		}else{
			int x;
			scanf("%d",&x);
			pii v = calc(x-1);
			printf("%d %d\n",v.first+1,v.second);
		}
	}
	return 0;
}