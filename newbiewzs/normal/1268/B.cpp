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
const int N=3e5+55;
int n,a[N],h,b;
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int maxx=0;
	for(int i=1;i<=n;i++){
		if(i&1){
			h+=ceil(1.0*a[i]/2);
			b+=a[i]-ceil(1.0*a[i]/2);
		}
		else{
			b+=ceil(1.0*a[i]/2);
			h+=a[i]-ceil(1.0*a[i]/2);
		}
	}
	if(h==b){
		cout<<h;
		return 0;
	}
	else{
		cout<<min(h,b);
		return 0;
	}
	return 0;
}