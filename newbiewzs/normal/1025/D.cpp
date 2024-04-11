#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<math.h>
//#include<unordered_map>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
	char c=getchar();
	ll x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=1000;
int n,a[N],f[N][N][2],g[708][708];
int gcd(int x,int y){
	if(!x)return y;
	else return gcd(y%x,x);
}
int solve(int l,int r,int fa){
	if(l>r)return 1;
	if(f[l][r][fa]!=-1)return f[l][r][fa];
	bool flag=0;
	if(l==1 && r==n){
		for(int k=l;k<=r;k++){
			if(solve(l,k-1,1) and solve(k+1,r,0)){
				flag=1;
				break;
			}
		}
	}
	else if(fa==1){
		for(int k=l;k<=r;k++){
			if(g[k][r+1]==1)continue;
			if(solve(l,k-1,1) and solve(k+1,r,0)){
				flag=1;
				break;
			}
		}
	}
	else{
		for(int k=l;k<=r;k++){
			if(g[k][l-1]==1)continue;
			if(solve(l,k-1,1) and solve(k+1,r,0)){
				flag=1;
				break;
			}
		}
	}
	f[l][r][fa]=flag;
	return flag;
}
int main(){
//	freopen("data.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			g[i][k]=gcd(a[i],a[k]);
		}
	}
	sort(a+1,a+n+1);
	memset(f,-1,sizeof(f));
	if(solve(1,n,0)){
		puts("Yes");
	}
	else puts("No");
	return 0;
}