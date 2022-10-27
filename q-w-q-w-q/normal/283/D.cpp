#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=1000005,inf=2147483647;
char ch;
inline void rd(int &x){
	x=0;
	ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
}
inline int mx(int a,int b){
	return a>b?a:b;
}
inline int mn(int a,int b){
	return a<b?a:b;
}
int n,s[5001];
ll a[5001];
int f[5001],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]&1^1) a[i]>>=1,s[i]++;
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
		for(int j=i-1;j;j--)
		if(a[j]%a[i]==0&&(s[i]==s[j]+i-j||s[i]<i-j)) f[i]=mx(f[i],f[j]+1);
		ans=mx(ans,f[i]);
	}
	cout<<n-ans;
}