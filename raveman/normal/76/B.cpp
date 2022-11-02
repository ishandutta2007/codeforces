#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
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

const int inf = 1000000000;
int n,m,y,Y;
int x[111111],X[111111];
int d[111111][2];
vi  v[111111];

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	cin>>n>>m>>y>>Y;
	REP(i,n) scanf("%d",x+i);
	REP(i,m) scanf("%d",X+i);

	REP(i,n) d[i][0]=d[i][1]= inf;
	
	REP(i,n){
		int pos = lower_bound(X,X+m,x[i])-X;
		if(pos >= m) pos--;
		else{
			if(pos>=1){
				if(X[pos] - x[i] > x[i] - X[pos-1])
					pos--;
			}
		}

		if(pos>=1 && X[pos] - x[i] == x[i] - X[pos-1]){
			v[i].pb(pos-1);
			v[i].pb(pos);
			pos--;

			if(i==0) d[0][0] = d[0][1] = 0;
			else{
				d[i][1] = min(d[i-1][0], d[i-1][1]);
				if(v[i-1].size() == 2){
					if(v[i-1].back()==pos) d[i][0] = min(d[i-1][0], d[i-1][1] + (x[i-1]+x[i]!=X[pos]*2?1:0));
					else d[i][0] = min(d[i-1][0],d[i-1][1]);
				}else{
					if(v[i-1][0] == pos) d[i][0] = d[i-1][0] + (x[i-1]+x[i]!=X[pos]*2?1:0);
					else d[i][0] = d[i-1][0];
				}

			}
		}else{
			v[i].pb(pos);
			if(i==0){
				d[0][0] = 0;
			}else{
				if(v[i-1].size() == 2){
					if(v[i-1].back()==pos) d[i][0] = min(d[i-1][0], d[i-1][1] + (x[i-1]+x[i]!=X[pos]*2?1:0));
					else d[i][0] = min(d[i-1][0],d[i-1][1]);
				}else{
					if(v[i-1][0] == pos) d[i][0] = d[i-1][0] + (x[i-1]+x[i]!=X[pos]*2?1:0);
					else d[i][0] = d[i-1][0];
				}
			}
		}
//		cout<<d[i][0]<<' '<<d[i][1]<<endl;
	}

	cout<<min(d[n-1][0],d[n-1][1])<<endl;
	return 0;
}