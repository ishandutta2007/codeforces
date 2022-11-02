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

char s[111111];
int n,k;

void go(vi v){
	//cout<<k<<' '<<v.size()<<endl;
	vi t[26];
	ll len[26];
	CL(len,0);
	REP(j,v.size()){
		int pos = v[j];
		t[s[pos]-'a'].pb(pos);
		len[s[pos]-'a']+=n-pos;
	}
	REP(i,26)if(len[i]){
		//cout<<"y "<<i<<' '<<len[i]<<endl;
		
		if(len[i]>=k){
			printf("%c",char('a'+i));
			v=t[i];
			if(k<=v.size()) return;
			k-=v.size();
			REP(j,v.size()){
				v[j]++;
			}			
			if(v.back()==n) v.pop_back();
			go(v);
			break;
		}else k-=len[i];
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	gets(s);
	n=strlen(s);
	//n=100000;
	//REP(i,n) s[i]=char('a'+rand()%5);
	//k=100000;
	cin>>k;
	vi v;
	REP(i,n)v.pb(i);
	if(k>n*ll(n+1)/2) puts("No such line.");
	else {go(v);puts("");}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}