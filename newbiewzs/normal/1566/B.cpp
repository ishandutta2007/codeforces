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
const int N=1e5+5;
int n,m;
char a[N];
void solve(){
	scanf("%s",a+1);
	n=strlen(a+1);
	bool f1=0,f0=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='1')f1=1;
		else f0=1;
	}
	int ans;
	if(f1 && f0)ans=2;
	if(f1 && !f0)ans=0;
	if(!f1 && f0)ans=1;
	int z0=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='0' && a[i-1]!='0')z0++;
	}
	ans=min(ans,z0);
	cout<<ans<<'\n';
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