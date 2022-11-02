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

int a[22];
vi v[222];
int wm[1<<20];
int mw[222];
bool u[222];

bool dfs(int ver){
	if(ver<0) return 1;
	if(u[ver]) return 0;
	u[ver]=1;
	REP(i,v[ver].size())
		if(dfs(wm[v[ver][i]]))
			return mw[ver]=v[ver][i],wm[v[ver][i]]=ver,1;
	return 0;
}

void print(int h){
	string s;
	while(h){
		s.pb('a'+h%27-1);
		h/=27;
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
}

int main(){
	freopen("input.txt","r",stdin);
#ifndef LocalHost
	freopen("output.txt","w",stdout);
#endif

	CL(wm,-1);

	int n;
	cin>>n;
	REP(i,n){
		string s;
		cin>>s;
		FOR(j,1,5)if(s.size()>=j){
			CL(a,0);
			REP(k,j) a[k]=1;
			sort(a,a+s.size());
			do{
				int hash = 0;
				REP(k,s.size())if(a[k]){
					hash = hash*27 + s[k]-'a'+1;
				}
				v[i].pb(hash);
			}while(next_permutation(a,a+s.size()));
		}
	}
	int num=0;
	REP(i,n){CL(u,0);num+=dfs(i);}
	if(num==n){
		REP(i,n) print(mw[i]);
	}else puts("-1");
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}