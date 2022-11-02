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

int n,m;
char s[555][555];
int d[555][26][26];
int r[555][26][2];
int t[26][26];

void go(int n,int p1,int p2){
	if(n<0) return;

	if(n>0)
	REP(pp1,26) REP(pp2,26) if(p1!=pp1 && p2!=pp2 && pp1!=pp2){
		int r1 = r[n][p1][0];
		int r2 = r[n][p2][1];
		int change = m - r1 - r2;
		if(d[n][p1][p2]== d[n-1][pp1][pp2] + change){
			go(n-1,pp1,pp2);
			goto here;
		}
	}

here:
	REP(i,m){
		if(i%2) printf("%c",char('a'+p2));
		else printf("%c",char('a'+p1));
	}
	puts("");
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	cin>>n>>m;
	gets(s[0]);
	REP(i,n) gets(s[i]);
	REP(i,n)REP(j,26){
		int p1 = 0;
		int p2 = 0;
		REP(q,m) if(s[i][q]==char(j+'a')){
			if(q%2) p2++;
			else p1++;
		}
		r[i][j][0]=p1;
		r[i][j][1]=p2;
	}
	REP(i,n){
		REP(j,26)REP(k,26)if(j!=k){
			int r1 = r[i][j][0];
			int r2 = r[i][k][1];
			int change = m - r1 - r2;

			d[i][j][k] = n*m;
			REP(q,26) if(q!=j)
				d[i][j][k] = min(d[i][j][k], change + t[q][k]);
		}
		REP(q,26){
			REP(j,26){
				t[q][j] = n*m;
				REP(k,26)if(k!=j && k!=q){
					t[q][j]=min(t[q][j],d[i][q][k]);
				}
			}
		}
	}
	int res = n*m;
	int p1=-1,p2=-1;
	REP(j,26)REP(k,26) if(j!=k && res > d[n-1][j][k])
		res=d[n-1][j][k],p1=j,p2=k;
	cout<<res<<endl;
	go(n-1,p1,p2);
	return 0;
}