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

int a[111][111];
int n,m,k;

int d[111][111][11];
string res;

void go(int row,int col, int ost){
	if(row==n-1){
		cout<<col+1<<endl;
		return;
	}
	int curr = d[row][col][ost];
	ost -= a[row][col];
	ost %= k; ost += k; ost %= k;

	for(int dx =-1;dx<=1;dx+=2){
		int nx = col + dx;
		if(nx>=0 && nx<m && d[row+1][nx][ost]!=-1 && d[row+1][nx][ost] == - a[row][col] + curr){
			go(row+1,nx,ost);
			res.pb(dx==-1?'R':'L');
			break;
		}			
	}
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	CL(d,-1);
	cin>>n>>m>>k;k++;
	REP(i,n){
		string s;
		cin>>s;
		REP(j,m) a[i][j] =s[j]-'0';
	}
	REP(j,m) d[n-1][j][a[n-1][j]%k] = a[n-1][j];
	for(int i=n-2;i>=0;i--){
		REP(j,m) for(int dx =-1;dx<=1;dx+=2)REP(kk,k){
			int nx = j + dx;
			if(nx>=0 && nx<m && d[i+1][nx][kk]!=-1){
				d[i][j][(kk+a[i][j])%k] = max(d[i][j][(kk+a[i][j])%k], d[i+1][nx][kk]+a[i][j]);
			}			
		}
	}
	int mx = -1;
	int pos = 0;
	REP(i,m)if(d[0][i][0]>mx)mx=d[0][i][0],pos=i;
	cout<<mx<<endl;
	if(mx!=-1){
		go(0,pos,0);
		//reverse(res.begin(),res.end());
		cout<<res<<endl;
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}