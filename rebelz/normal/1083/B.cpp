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

ll n,k,ans;
char s[500005],t[500005];

int main(){
	n=readint(); k=readint();
	scanf("%s%s",s+1,t+1);
	if(k==1) return printf("%d\n",n),0;
	ll now1=0,now2=0,fl=0,fin=0;
	for(int i=1;i<=n;i++){
		if(!fl&&s[i]==t[i]){
			ans++;
			continue;
		}
		else if(!fl){
			now1=1,now2=1;
			ans+=2,fl=1;
			continue;
		}
		now1=now1*2-(s[i]-'a');
		now2=now2*2+(t[i]-'a')-1;
		if(!fin) ans+=min(k,now1+now2);
		else ans+=k;
		if(now1+now2>=k) fin=1;
	}
	printf("%lld\n",ans);
	return 0;
}