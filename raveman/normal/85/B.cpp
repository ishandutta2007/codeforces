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

int k1,k2,k3;
int t1,t2,t3;
int a[111111];
ll  c[111111];
int n;
ll res;

typedef pair<ll,ll> pl;

void solve(int k,int t){
	queue<ll> q;
	int num = k;
	ll curr = 0;
	REP(i,n){
		curr = max(curr, c[i]);
		if(num==0){
			curr = max(curr,q.front());q.pop();
			num++;
		}
		num--;
		q.push(curr+t);
		c[i] = curr+t;
		res = max(res, curr+t-a[i]);
	}
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>k1>>k2>>k3;
	cin>>t1>>t2>>t3;
	cin>>n;
	REP(i,n){
		int x;
		scanf("%d",&x);
		a[i]=c[i]=x;
	}
	sort(c,c+n);
	solve(k1,t1);
	solve(k2,t2);
	solve(k3,t3);
	cout<<res<<endl;

	return 0;
}