#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[100005];
ll res[30];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	ll ans=0;
	for(int i=0;i<26;i++){
		ll cnt=0;
		memset(res,0,sizeof(res));
		for(int j=1;j<=n;j++){
			res[s[j]-'a']+=cnt;
			if(s[j]-'a'==i) cnt++;
		}
		chkmax(ans,cnt);
		for(int j=0;j<26;j++) chkmax(ans,res[j]);
	}
	printf("%lld\n",ans);
	return 0;
}