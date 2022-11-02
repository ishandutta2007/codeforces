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

int n,t,m;
int a[111][2];
int b[111][2];
string s[111];
int c[111];
int d[111][111];
vi v[111];
bool u[111];

int main(){
	freopen("input.txt","r",stdin);
#ifndef LocalHost
	freopen("output.txt","w",stdout);
#endif

	cin>>n>>t;
	REP(i,n) cin>>a[i][0]>>b[i][0]>>a[i][1]>>b[i][1];
	cin>>m;
	REP(i,m) cin>>s[i]>>c[i];
	int pos_word = 0;
	int pos_team = 0;
	int pos_in_team = 0;
	int num = 0;
	while(num!=m){
		int T = t;
		while(T){
			int res = max(1, c[pos_word] - (a[pos_team][pos_in_team]+b[pos_team][1-pos_in_team]) - d[pos_team][pos_word]);
			//cout<<pos_team<<' '<<pos_word<<' '<<res<<' '<<T<<' '<<res<<endl;
			if(res<=T){
				u[pos_word]=1;
				v[pos_team].pb(pos_word);
			//	cout<<"added "<<s[pos_word]<<endl;
				num++;
				T-=res;

				
				if(num==m) break;
				
				pos_word=(pos_word+1)%m;
				while(u[pos_word]) pos_word=(pos_word+1)%m;
				
			}else{
				d[pos_team][pos_word] += min(res, T), T=0;
				pos_word=(pos_word+1)%m;
				while(u[pos_word]) pos_word=(pos_word+1)%m;
				
			}
		}
		if(num==m) break;
		pos_team++;
		if(pos_team==n){pos_team=0;pos_in_team^=1;}

	}
	REP(i,n){
		cout<<v[i].size();
		REP(j,v[i].size())
			cout<<' '<<s[v[i][j]];
		puts("");
	}
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}