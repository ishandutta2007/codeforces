#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=2e5+55;
int T;
int n,a[N];
void solve(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	map<int,int>ma;
	bool flag=0;
	for(int i=1;i<=n;i++){
		ma[((i+a[i])%n+n)%n]++;
		if(ma[((i+a[i])%n+n)%n]==2)flag=1;
	}
	if(flag)puts("NO");
	else puts("YES");
}
signed main(){
	cin>>T;
	// T=1;
	while(T--){
		solve();
	}
	return 0;
}