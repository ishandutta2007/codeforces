/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
bool f[300];
char c[1005];
signed main(){
	scanf("%s",c+1);
	int n=strlen(c+1);
	f['w']=f['W']=f['o']=f['O']=f['I']=f['U']=f['H']=f['Y']=f['x']=f['X']=f['T']=f['V']=f['v']=f['M']=f['A']=1;
	if(n&1){
		if(!f[c[n/2+1]]){
			cout<<"NIE";RE 0;
		}
	}
	FOR(i,1,n/2){
		char c1=c[i],c2=c[n-i+1];
		if(c1=='b'&&c2=='d'||c1=='d'&&c2=='b'||c1==c2&&f[c1]||c1=='p'&&c2=='q'||c1=='q'&&c2=='p'){
			continue;
		}
		cout<<"NIE";RE 0;
	}
	cout<<"TAK";
	RE 0;
}