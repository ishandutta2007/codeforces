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
//#define int long long
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
const int N=2025;
int T,n,a[N],pos[N],st[N*5],top;
void work(){
	for(int i=1;i<=n;i++)pos[a[i]]=i;
}
void solve(){
	bool flag=1;
	for(int i=1;i<=n;i++)if((a[i]&1)^(i&1))flag=0;
	if(!flag)return (void)(puts("-1"));top=0;
	for(int i=n;i>1;i-=2){
		work();
		if(pos[i]!=1)st[++top]=pos[i],reverse(a+1,a+pos[i]+1);
		work();
		if(pos[i-1]!=2)
		{
			st[++top]=pos[i-1]-1,reverse(a+1,a+pos[i-1]);
			st[++top]=pos[i-1]+1;reverse(a+1,a+pos[i-1]+1+1);
			st[++top]=3;reverse(a+1,a+3+1);
		}
		st[++top]=i;
		reverse(a+1,a+i+1);
	}
	cout<<top<<'\n';
	for(int i=1;i<=top;i++)cout<<st[i]<<" ";
	cout<<'\n';
}
int main(){
	cin>>T;
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		solve();
	}
	return 0;
}
/*
1
5
3 4 5 2 1
*/