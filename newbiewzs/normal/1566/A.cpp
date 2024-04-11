#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<cmath> 
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
using namespace std;
int read(){
	char c=getchar();int x=1;int s=0;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
int n,m;
void solve(){
	cin>>n>>m;
//	n=7;m=17;
	int pos=ceil(1.0*n/2);
	int sy=n-pos+1;
	cout<<(m/sy)<<'\n';
}
signed main(){
	int T;
	cin>>T;
//T=1;
	while(T--){
		solve();
	}
	return 0;
}