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
int n,m,f[N];
char a[N],b[N];
void solve(){
	n=read();
	scanf("%s",a+1);scanf("%s",b+1);
	int ans=0,tmp=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i])ans+=2;
		else if(a[i]==b[i] && a[i]=='0')
		{
			if(!f[i-1] && a[i-1]==b[i-1] && a[i-1]=='1')ans+=2,f[i]=1;
			else ans++;
		}
		else if(a[i]==b[i] && a[i]=='1'){
			if(!f[i-1] && a[i-1]==b[i-1] && a[i-1]=='0')ans++,f[i]=1;
		}
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i])tmp+=2;
		else if(a[i]==b[i] && a[i]=='1'){
			if(!f[i-1] && a[i-1]==b[i-1] && a[i-1]=='0')tmp++,f[i]=1;
		}
		else if(a[i]==b[i] && a[i]=='0')
		{
			if(!f[i-1] && a[i-1]==b[i-1] && a[i-1]=='1')tmp+=2,f[i]=1;
			else tmp++;
		}
	}
	memset(f,0,sizeof(f));
	cout<<min(ans,tmp)<<'\n';
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