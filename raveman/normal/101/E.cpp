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

int n,m,p;
int x[22222];
int y[22222];
int d[10007][650];

int d1[20000];
int d2[20000];

string res;
bool first = true;

void go(){
	if(n==0 && m==0) return;
	if(n==0){
		res.pb('S');
		m--;
		go();
		return;
	}
	if(m==0){
		res.pb('C');
		n--;
		go();
		return;
	}
	
	if(n==10000 && first){
		first = false;
		return;
	}

	int row = n;
	if(row>10000) row-=10000;

	int md = m % 31;
	int dv = m / 31;
			
	if(d[row][dv] &(1<<md)){
		res.pb('S');
		m--;
		go();
	}else{
		res.pb('C');
		n--;
		go();
	}
}

int solve(){
	CL(d1,0);
	CL(d2,0);
	CL(d,0);

	int *f1 = d1;
	int *f2 = d2;

	REP(i,n){
		int md = -1;
		int dv = 0;
		REP(j,m){
			md ++;
			if(md>=31) md-=31,dv++;
			int row = i;
			if(row>10000) row-=10000;
			if(d[row][dv] &(1<<md))
				d[row][dv] ^= (1<<md);

			f1[j] = (x[i]+y[j]);
			if(f1[j]>=p) f1[j]-=p;

			int v1 = j?f1[j-1]:-1;
			int v2 = i?f2[j]:-1;

			if(v1==-1 && v2==-1) continue;
			
			
			if(v1>v2){
				f1[j] += v1;
				d[row][dv] |= (1<<md);
			}else{
				f1[j] += v2;
			}
		}
		swap(f1,f2);
	}
	return f2[m-1];
}

bool check(string s,int val){
	int t = (x[0] +y[0])%p;
	int a = 0, b = 0;
	REP(i,s.size()){
		if(s[i]=='C') a++;
		else b++;
		t += (x[a] + y[b])%p;
	}
	if(t!=val){
		puts("FUCK");
		return 0;
	}
	else puts("OK");
	return 1;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
	cin>>n>>m>>p;
	
	/*int it = 0;
here:
	it++;
	srand(it);
	
	n = 11111;//9999 + rand()%10 + 1;
	m = 5;// + rand() %100 + 1;
	p = rand() % 1000 + 1;
	*/
	REP(i,n){
		scanf("%d",x+i);
		//x[i] = rand();
		x[i]%=p;
	}
	REP(i,m){
		scanf("%d",y+i);
		//y[i] = rand();
		y[i]%=p;
	}
	
	res="";
	int qq = solve();
	cout<<qq<<endl;
	n--,m--;
	go();
	n++,m++;
	solve();
	n--,m--;
	go();
	reverse(res.begin(),res.end());
	//if(check(res,qq))
	//	goto here;
	printf("%s\n",res.c_str());
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}