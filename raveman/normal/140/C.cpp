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
priority_queue<pii> q;
typedef pair<int,pii> p3;
int b[3];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n) scanf("%d",a+i);
	sort(a,a+n);
	for(int i=0;i<n;){
		int j=i;
		while(j<n && a[j]==a[i]) j++;
		q.push(pii(j-i,a[i]));
		i=j;
	}

	vector<p3> v;
	while(q.size()>2){
		pii v1 = q.top();q.pop();
		pii v2 = q.top();q.pop();
		pii v3 = q.top();q.pop();
		b[0] = v1.second;
		b[1] = v2.second;
		b[2] = v3.second;
		sort(b,b+3);
		v.pb(p3(b[2],pii(b[1],b[0])));

		v1.first--;if(v1.first) q.push(v1);
		v2.first--;if(v2.first) q.push(v2);
		v3.first--;if(v3.first) q.push(v3);
	}

	cout<<v.size()<<endl;
	REP(i,v.size()){
		printf("%d %d %d\n",v[i].first,v[i].second.first,v[i].second.second);
	}
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}