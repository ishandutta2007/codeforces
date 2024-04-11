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

int n,m;
int c[10];
int d[10];
int c1[10];
int d1[10];
int r[10][10];
int a[10][10];
int cnt;
int f[22][22];
int F[22][22];
int D[10];
int C[10];
bool g[10][10];

char s[10][10];
char S[10][10];


int best=-1;

int ID[26][26];
int now;
int u[22];

bool DEBUG;
int who[33];
int WHO[33];

int flow(int ver,int fl = 100){
	if(ver==21) return fl;
	if(u[ver]==now) return 0;
	u[ver]=now;
	if(f[ver][21]){
		int t = flow(21,min(fl,f[ver][21]));
		return f[ver][21]-=t,f[21][ver]+=t,t;	
	}
	int from=0,to=20;
	if(ver>=10 && ver<=20) to = 10;
	if(ver<10) from=10;
	FOR(i,from,to) if(f[ver][i]){
		int t = flow(i,min(fl,f[ver][i]));
		if(t) return f[ver][i]-=t,f[i][ver]+=t,t;
	}
	return 0;
}

void go(int x,int y,int id=0){
	if(y==m){
		int sum = 0;
		REP(i,10){
			int q = min(d[i],c[i]);
			sum += 2*q;
			d1[i] = d[i] - q;
			c1[i] = c[i] - q;
		}
		//REP(i,10) f[20][i]=f[i][20]=f[i][21]=f[21][i]=0;
		//CL(f,0);
		REP(i,10)REP(j,10) if(g[i][j]){
			int q = min(c1[i],d1[j]);
			c1[i]-=q,d1[j]-=q;sum += q;
			f[i][j+10] = 1000;
			f[j+10][i]=0;
			f[j+10][i] = q;
			f[i][20] = q;
			f[21][j+10] = q;
		}
		REP(i,10) f[20][i] = c1[i];
		REP(i,10) f[i+10][21] = d1[i];
		while(1){
			now++;
			int t = flow(20);
			if(!t) break;
			sum += t;
		}
		if(best<sum){
			best = sum;
			memcpy(r,a,sizeof a);
			memcpy(F,f,sizeof f);
			memcpy(D,d,sizeof d);
			memcpy(C,c,sizeof c);
			memcpy(WHO,who,sizeof who);
		}
		return;
	}
	if(x==n) go(0,y+1,id);
	else{
		if(a[x][y]) go(x+1,y,id);
		else{
			if(x+1<n && !a[x+1][y]){
				int w = ID[s[x][y]-'A'][s[x+1][y]-'A'];
				who[id+1] = w;
				d[w]++;
				a[x][y]=a[x+1][y]=id+1;
				go(x+2,y,id+1);
				a[x+1][y]=a[x][y]=0;
				d[w]--;
			}
			if(y+1<m){
				int w = ID[s[x][y]-'A'][s[x][y+1]-'A'];
				who[id+1] = w;
				d[w]++;
				a[x][y+1]=a[x][y]=id+1;
				go(x+1,y,id+1);
				a[x][y+1]=a[x][y]=0;
				d[w]--;
			}
		}
	}
	
}

string X[]={"BY" ,"BW" ,"BR" ,"BB","RY" ,"RW" ,"RR","WY" ,"WW","YY"};
bool used[111];

void change(int id,int newtype){
	REP(i,n)REP(j,m)if(r[i][j]==id){
//		cout<<"change "<<id<<" for "<<newtype<<endl;
	
		char &c1=s[i][j];
		char &c2=(r[i+1][j]==id)?s[i+1][j]:s[i][j+1];

		if(c1==X[newtype][0]){
			c2 = X[newtype][1];
		}else if(c1==X[newtype][1]){
			c2 = X[newtype][0];
		}else if(c2==X[newtype][0]){
			c1 = X[newtype][1];
		}else if(c2==X[newtype][1]){
			c1 = X[newtype][0];
		}else c1 = X[newtype][0],c2=X[newtype][1];

		return;
	}
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif
	CL(ID,-1);
	REP(i,10) ID[X[i][0]-'A'][X[i][1]-'A']=ID[X[i][1]-'A'][X[i][0]-'A']=i;
	REP(i,10)REP(j,10)
		if(X[i][0]==X[j][0] || X[i][0]==X[j][1] || X[i][1]==X[j][0] || X[i][1]==X[j][1])
			g[i][j]=1;
	n=7,m=8;
	REP(i,n)  cin>>s[i];
	REP(i,10) cin>>c[i];
	go(0,0);
	cout<<best<<endl;
	REP(i,10){
		int q = min(D[i],C[i]);
		d1[i] = D[i] - q;
		c1[i] = C[i] - q;
		C[i] -= q;
		best-=q*2;
		FOR(j,1,n*m/2+1) if(WHO[j] == i && q){
			used[j] = 1;
			q--;			
		}
	}

	CL(f,0);
	REP(i,10)REP(j,10) if(g[i][j])
		f[i][j+10] = 1000;
	REP(i,10) f[20][i] = c1[i];
	REP(i,10) f[i+10][21] = d1[i];
	
	while(1){
		now++;
		int t = flow(20);
		if(!t) break;
		best-=t;
	}
	
	REP(i,10)REP(j,10) if(f[j+10][i]){
		int q = f[j+10][i];
		FOR(k,1,n*m/2+1)if(WHO[k]==j && q && !used[k]){
			C[i]--;
			q--;
			used[k] = true;
			change(k,i);
			
		}
	}
	//puts("START!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	FOR(j,1,n*m/2+1)if(!used[j]){
		REP(i,10)if(C[i]){
			C[i]--;
			change(j,i);
			break;
		}
	}
		
	REP(i,n){
		REP(j,m){
			cout<<s[i][j];
			if(j!=m-1){
				if(r[i][j]==r[i][j+1]) cout<<'-';
				else cout<<'.';
			}
		}
		puts("");
		REP(j,m){
			if(i!=n-1){
				if(r[i][j]==r[i+1][j]) cout<<'|';
				else cout<<'.';
				
				if(j!=m-1) cout<<'.';
			}
		}
		if(i!=n-1) puts("");
	}
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}