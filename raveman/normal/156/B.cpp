#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
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

bool OUTPUT_TO_FILE = 0;

int n,m;
int pos = 0, neg = 0;
int pos_t[111111];
int neg_t[111111];
bool could_be[111111];
int total;
int r[111111];
int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE) freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n){
		int x;
		scanf("%d",&x);
		r[i+1] = x;
		if(x>0){
			pos++;
			pos_t[x]++;
		}else{
			neg++;
			neg_t[-x]++;
		}
	}
	FOR(i,1,n+1){
		int lied = pos - pos_t[i] + neg_t[i];
		if(lied == n-m){
			total ++;
			could_be[i] = true;
			//cout<<i<<endl;
		}
	}

	FOR(i,1,n+1){
		if(r[i]>0){
			if(!could_be[r[i]]) puts("Lie");
			else{
				if(total == 1) puts("Truth");
				else puts("Not defined");
			}
		}else{
			r[i]=-r[i];
			if(!could_be[r[i]]) puts("Truth");
			else{
				if(total == 1) puts("Lie");
				else puts("Not defined");
			}
		}
	}

#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}