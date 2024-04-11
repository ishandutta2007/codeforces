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
#define int long long
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
const int N=1e5+55;
int n,a[N];
int out(int l,int r){
	cout<<l<<" "<<r<<endl;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n==1){
		out(1,1);
		cout<<-a[1]<<endl;
		cout<<"1 1\n0\n1 1\n0";
		return 0;
	}
	out(1,n-1);
	for(int i=1;i<=n-1;i++){
		cout<<a[i]*(n-1)<<" ";
		a[i]=a[i]*n;
	}
	cout<<endl;
	out(n,n);
	cout<<n-a[n]<<endl;
	a[n]=n;
	out(1,n);
	for(int i=1;i<=n;i++){
		cout<<-a[i]<<" ";
	}
	return 0;
}