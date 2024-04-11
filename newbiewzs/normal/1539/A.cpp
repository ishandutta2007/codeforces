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
int T,n,x,t;
signed main(){
//	freopen("data.in","r",stdin);
	cin>>T;
	while(T--){
		n=read();x=read();t=read();
		int ans=0;
		int las=n-t/x;
		if(las<0){
			cout<<(n*(n-1ll)/2ll)<<endl;
			continue;
		}
		int any=t/x;
		int sy=n-las;
		ans=(las)*any+(sy*(sy-1ll)/2ll);
		cout<<ans<<endl;
	}
	return 0;
}