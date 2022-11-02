#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back	

int n,k;
string s[2222];
pii    a[2222][2222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n)cin>>s[i];
	REP(i,n)REP(j,n)a[i][j].first=-1;
	a[0][0]=pii(k,s[0][0]-'a');
	if(a[0][0].second && k){
		a[0][0].first--;
		a[0][0].second=0;
	}
	vi r;
	REP(d,n-1+n-1){
		int bst = 100;
		REP(row,n){
			int column = d - row;
			if(column>=0 && column<n){
				if(a[row][column].first==-1)continue;
				bst = min(bst,a[row][column].second);
			}
		}
		REP(row,n){
			int column = d - row;
			if(column>=0 && column<n){
				if(a[row][column].first==-1)continue;
				//cout<<row<<' '<<column<<' '<<a[row][column].first<<' '<<a[row][column].second<<endl;
				if (bst != a[row][column].second) a[row][column].first=-1;
			}
		}
		r.pb(bst);

		REP(row,n){
			int column = d - row;
			if(column>=0 && column<n){
				if(a[row][column].first==-1)continue;

				if(row+1<n){
					pii nval(a[row][column].first,s[row+1][column]-'a');
					if(nval.first && nval.second){
						nval.first--;
						nval.second=0;
					}
					if(a[row+1][column].first==-1 || a[row+1][column].second>nval.second || a[row+1][column].second==nval.second && a[row+1][column].first<nval.first){
						a[row+1][column] = nval;
					}
				}

				if(column+1<n){
					pii nval(a[row][column].first,s[row][column+1]-'a');
					if(nval.first && nval.second){
						nval.first--;
						nval.second=0;
					}
					if(a[row][column+1].first==-1 || a[row][column+1].second>nval.second || a[row][column+1].second==nval.second && a[row][column+1].first<nval.first){
						a[row][column+1] = nval;
					}
				}
			}
		}
	}
	
	REP(i,r.size()) cout<<char('a'+r[i]);
	cout<<char(a[n-1][n-1].second+'a')<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}