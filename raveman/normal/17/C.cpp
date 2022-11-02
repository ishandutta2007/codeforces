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
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n;
string s;

const int mod = 51123987;

int next[155][5];
int d[51][51][51][155];

int go(int a,int b,int c,int pos){
	if(pos>=n || a>50 || b>50 || c>50) return 0;
	if(a+b+c==n) return min(min(a,b),c)+1>=max(a,max(b,c));
	if(d[a][b][c][pos]!=-1) return d[a][b][c][pos];

	int val = go(a+(s[pos]=='a'?1:0),b+(s[pos]=='b'?1:0),c+(s[pos]=='c'?1:0),pos);
	REP(j,3)if(s[pos]-'a'!=j){
		val += go(a+(j==0?1:0),b+(j==1?1:0),c+(j==2?1:0),next[pos][j]);
		if(val>=mod) val-=mod;
	}
	
	return d[a][b][c][pos]=val;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	CL(d,-1);
	cin>>n>>s;
	REP(i,s.size()) REP(j,3){
		next[i][j]=n;
		FOR(k,i,n) if(s[k]==char(j+'a')){
			next[i][j]=k;
			break;
		}
	}
	cout<<(go(1,0,0,next[0][0])+go(0,1,0,next[0][1])+go(0,0,1,next[0][2]))%mod<<endl;

	return 0;
}