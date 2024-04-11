#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

int n,k;
string s[2];
int    d[2][111111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	cin>>s[0]>>s[1];
	CL(d,-1);
	queue<pii> q;
	q.push(pii(0,0));
	d[0][0] = 0;
	while(!q.empty()){
		int side = q.front().first;
		int h = q.front().second;
		q.pop();

		if(h==n-1){
			puts("YES");
			return 0;
		}
		if(s[side][h+1]=='-' && d[side][h+1]==-1){
			d[side][h+1] = d[side][h] + 1;
			q.push(pii(side,h+1));
		}

		if(h && s[side][h-1]=='-' && d[side][h-1]==-1){
			if(d[side][h] + 1 >= h-1 + 1){}
			else{
				d[side][h-1] = d[side][h] + 1;
				q.push(pii(side,h-1));
			}
		}

		if(h+k>=n){
			puts("YES");
			return 0;
		}
		if(s[side^1][h+k]=='-' && d[side^1][h+k]==-1){
			d[side^1][h+k] = d[side][h] + 1;
			q.push(pii(side^1,h+k));
		}
	}
	puts("NO");

	
#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}