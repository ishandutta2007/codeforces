// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int pl[26],val[100005];
char s[100005],t[100005];
vector<int> vec[26];

void add(int x){
	for(;x<=n;x+=(x&(-x))) val[x]++;
}

int ask(int x){
	int ret=0;
	for(;x;x-=(x&(-x))) ret+=val[x];
	return ret;
}

int getpl(int x){
	return x+ask(n)-ask(x);
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s",s+1);
		scanf("%s",t+1);
		for(int i=0;i<26;i++) vec[i].clear(),pl[i]=0;
		for(int i=1;i<=n;i++) vec[s[i]-'a'].pb(i);
		for(int i=1;i<=n;i++) val[i]=0;
		ll ans=1ll<<60,now=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<t[i]-'a';j++){
				if(pl[j]<vec[j].size()) chkmin(ans,now+getpl(vec[j][pl[j]])-i);
			}
			if(pl[t[i]-'a']==vec[t[i]-'a'].size()) break;
			now+=getpl(vec[t[i]-'a'][pl[t[i]-'a']])-i;
			add(vec[t[i]-'a'][pl[t[i]-'a']]);
			pl[t[i]-'a']++;
		}
		printf("%lld\n",ans==(1ll<<60)?-1:ans);
	}
	return 0;
}