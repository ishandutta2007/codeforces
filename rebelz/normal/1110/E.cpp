#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll c[100005],t[100005];
map<ll,int> mp;

int main(){
	n=readint();
	for(int i=1;i<=n;i++) c[i]=readint();
	for(int i=1;i<=n;i++) t[i]=readint();
	if(c[1]!=t[1]||c[n]!=t[n]) return printf("No\n"),0;
	for(int i=1;i<=n;i++) c[i]=c[i+1]-c[i],t[i]=t[i+1]-t[i];
	n--;
	for(int i=1;i<=n;i++) mp[c[i]]++;
	for(int i=1;i<=n;i++){
		if(!mp[t[i]]) return printf("No\n"),0;
		mp[t[i]]--;
	}
	printf("Yes\n");
	return 0;
}