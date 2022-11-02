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

int d[111111];
int p[111111];
int a[111111];

int n,m;

bool on[111111];

int id[111111];

void clear(int x){
	while(x>1){
		id[p[x]] = 0;
		x = a[x];
	}
}

int turn(int x){
	int t = x;
	while(x>1){
		if(id[p[x]]) return id[p[x]];
		x = a[x];
	}
	x=t;
	while(x>1){
		id[p[x]] = t;
		x = a[x];
	}
	return 0;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE) freopen("output.txt","w",stdout);
#endif

	CL(d,-1);
	FOR(i,2,111111)if(d[i]==-1)
		for(int j=2*i;j<111111;j+=i) d[j] = i;
	FOR(i,1,111111){
		if(d[i]==-1) p[i] = i, a[i] = 1;
		else{
			p[i] = d[i];
			int x = i;
			while(x%p[i]==0) x/=p[i];
			a[i] = x;

		}		
	}

	cin>>n>>m;
	CL(id,0);

	REP(i,m){
		char type;
		int x;
		scanf(" %c %d",&type,&x);
		if(type=='+'){
			if(on[x]) puts("Already on");
			else{
				int y = turn(x);
				if(y==0) puts("Success"),on[x] = true;
				else printf("Conflict with %d\n",y);

			}
		}else{
			if(on[x]==0) puts("Already off");
			else{
				puts("Success");
				clear(x);
				on[x]=0;
			}
		}
	}

#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}