#pragma comment(linker, "/STACK:60777216")  

#include <algorithm>
#include <iostream>
#include <complex>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define sz(a)                   int(a.size())
#define all(a)                  (a).begin(), (a).end()
#define CL(a, b)                memset(a, b, sizeof a) 
#define FOR(i, a, b)			for (int i(a); i < (b); ++i)
#define REP(i, n)               FOR(i, 0, n)
#define UN(a)                   sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb                      push_back
#define SORT(a)                 sort(all(a))

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n,x;
int a[1111111];
bool p[2111111];

set<int> q;

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	cin>>n>>x;
	REP(i,n) scanf("%d",a+i),q.insert(a[i]);
	sort(a,a+n);
	if(x==2) puts("0");
	else if(n==0) puts("-1");
	else if(a[0]==1) puts("1");
	else{
		int cc =0;
		for(int i=2;i<=2000000;i++)if(!p[i]){
			cc++;
			for(int j=i+i;j<=2000000;j+=i) p[j]=1;
		}
		int num = 0;
		for(int i=2;i<=2000000;i++)if(!p[i]){
			if(i>=x) break;
			if(!q.count(i)){
				puts("-1");
				return 0;
			}
			num++;
		}
		cout<<num<<endl;
	}
	return 0;
}