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

bool OUTPUT_TO_FILE = 0;

int n;
int A[555];
string s;
int d[155][155][155];

int go(int a,int b,int num){
	if(a>b){
		if(A[num]==-1) return -2;
		return A[num];
	}
	if(d[a][b][num]!=-1) return d[a][b][num];


	int val = -2;
	for(int i=2;i<=num;i+=2){
		int t = go(a,b,num-i);
		if(t!=-2 && A[i]!=-1)
			val = max(val, t + A[i]);
	}
	if(a==b){
		int t = go(a+1,b-1,num+1);
		if(t!=-2) val = max(val, t);
	}else{
		int t = go(a+1,b,0);
		if(t!=-2 && A[num+1]!=-1) val = max(val, A[num+1] + t);

		t = go(a,b-1,0);
		if(t!=-2 && A[num+1]!=-1) val = max(val, A[num+1] + t);

		if(s[a]==s[b]){
			int t = go(a+1,b-1,num+2);
			if(t!=-2)
				val = max(val, t);
		}
		FOR(i,a,b){
			int t1 = go(a,i,num);
			int t2 = go(i+1,b,0);

			if(t1!=-2 && t2!=-2) val = max(val, t1 + t2);

			int t3 = go(a,i,0);
			int t4 = go(i+1,b,num);

			if(t3!=-2 && t4!=-2) val = max(val, t3 + t4);
		}
	}

	return d[a][b][num] = val;
}

int r[155][155];
int solve(int a,int b){
	if(a>b) return 0;
	if(r[a][b]!=-1) return r[a][b];
	int val = 0;
	val = max(val, go(a,b,0));
	val = max(val, solve(a+1,b));
	FOR(i,a,b) val = max(solve(a,i)+solve(i+1,b), val);
	return r[a][b]=val;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE) freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) cin>>A[i+1];
	cin>>s;
	CL(d,-1);
	CL(r,-1);
	cout<<solve(0,n-1)<<endl;

#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}