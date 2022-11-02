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

int n;
char s[2222][2222];
bool inv_row[2222];
bool inv_col[2222];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	gets(s[0]);
	REP(i,n) gets(s[i]);
	int res = 0;
	while(n){
		bool curr_inv1 = 0;
		//hor
		REP(i,n-1){
			bool black = (s[n-1][i]=='1');
			black ^= curr_inv1;
			black ^= inv_col[i];
			if(black){
				res++;
				inv_col[i]^=1;
				curr_inv1^=1;
			}
		}
		bool curr_inv2 = 0;
		//ver
		REP(i,n-1){
			bool black = (s[i][n-1]=='1');
			black ^= curr_inv2;
			black ^= inv_row[i];
			if(black){
				res++;
				inv_row[i]^=1;
				curr_inv2^=1;
			}
		}
		bool bl = s[n-1][n-1]=='1';
		bl ^= curr_inv1;
		bl ^= curr_inv2;
		bl ^= inv_row[n-1];
		bl ^= inv_col[n-1];
		if(bl) res++;

		n--;
	}
	cout<<res<<endl;
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}