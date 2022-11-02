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
#define da(x) cout<<"sese:"<<x<<endl;
#define db(x,y) cout<<"???"<<x<<" "<<y<<endl;
#define dc(x,y,z) cout<<"!!!!:"<<x<<" "<<y<<" "<<z<<endl;
#define dd(x,y,z,w) cout<<"yiw:"<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
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
const int N=1e5+55;
int T,n;
int a[N],b[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		int pre=0;
		int suf=n+1;
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i])break;
			pre=i;
		}
		for(int i=n;i>=1;i--){
			if(a[i]!=b[i])break;
			suf=i;
		}
		if(suf<pre){
			puts("YES");
			continue;
		}
		bool flag=0;
		int zs=a[pre+1]-b[pre+1];
		for(int i=pre+2;i<suf;i++){
			if(a[i]-b[i]!=zs)flag=1;
		}
		if(!flag)
		{
		    if(zs>0)puts("NO");
			else puts("YES");
		}
		else puts("NO");
	}
	return 0;
}