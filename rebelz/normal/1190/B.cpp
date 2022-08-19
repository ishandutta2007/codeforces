#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=2;i<=n;i++) if(a[i]==a[i-1]) cnt++;
	if(cnt>=2) return printf("cslnb\n"),0;
	if(cnt==1){
		if(a[1]==a[2]&&a[1]==0) return printf("cslnb\n"),0;
		for(int i=3;i<=n;i++) if(a[i]==a[i-1]&&a[i-2]==a[i]-1) return printf("cslnb\n"),0;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans^=(a[i]-i+1)&1;
	if(!ans) printf("cslnb\n");
	else printf("sjfnb\n");
	return 0;
}