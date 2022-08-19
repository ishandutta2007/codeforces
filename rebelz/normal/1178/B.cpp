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
char s[1000005];
int a[1000006];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=2;i<=n;i++) if(s[i]=='v'&&s[i-1]=='v') a[i]=1;
	ll ans=0,now=0,cnt=0;
	for(int i=2;i<=n;i++){
		if(a[i]){
			ans+=now;
			cnt++;
		}
		else if(s[i]=='o'){
			now+=cnt;
		}
	}
	cout<<ans<<endl;
	return 0;
}