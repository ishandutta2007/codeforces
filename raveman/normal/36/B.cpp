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

int w[111][111];
int k,n;

string s[11];

bool win(int x,int y){
	if(w[x][y]) return w[x][y]==1;
	if(x>1 && !win(x-1,y))  return w[x][y]=1;
	if(y>1 && !win(x,y-1)) return w[x][y]=1;
	if(x-k>=1 && y-k>=1 && !win(x-k,y-k)) return w[x][y]=1;
	return w[x][y]=-1,0;
}

int main(){
	freopen("input.txt","r",stdin);
#ifndef LocalHost    
    freopen("output.txt","w",stdout);
#endif
	cin>>n>>k;
	REP(i,n) cin>>s[i];
	int t = 1;
	REP(i,k) t*=n;
	REP(x,t){
		REP(y,t){
			bool xxx = 0;

			int xx = x, yy = y;
			REP(j,k){
				int c1 = xx%n;
				int c2 = yy%n;
				if(s[c1][c2]=='*') xxx = 1;
				xx/=n,yy/=n;
			}

			if(xxx) printf("*");
			else printf(".");
		}
		puts("");
	}
	/*cin>>k;
	FOR(x,1,20){
		FOR(y,1,20){
			if(win(x,y)) printf("+");
			else printf("-");
		}
		puts("");
	}
*/
	return 0;
}