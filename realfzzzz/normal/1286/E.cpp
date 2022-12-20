#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
typedef long long ll;
void add(ll& x1,ll& x2,ll y){
	x2+=y;
	x1+=x2/(ll)1e18;
	x2%=(ll)1e18;
}
const int maxn=6e5+5;
int n,w[maxn];
char s[maxn];
int st[maxn],tp=0,nxt[maxn],f[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	ll ans1=0,ans2=0,sum=0;
	unsigned ans3=0;
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		scanf("%s",s+i);
		s[i]=(s[i]-'a'+(ll)1e18%26*ans1+ans2)%26+'a';
		w[i]=readint()^(ans3&((1<<30)-1));
		while(tp&&w[i]<w[st[tp-1]]) tp--;
		st[tp++]=i;
		if(i==1){
			printf("%lld\n",ans2=ans3=sum=w[1]);
			mp[w[1]]=1;
			continue;
		}
		mp[w[i]];
		auto it=mp.upper_bound(w[i]);
		for(auto j=it;j!=mp.end();j++){
			mp[w[i]]+=j->second;
			sum-=1ll*j->second*(j->first-w[i]);
		}
		mp.erase(it,mp.end());
		int u=nxt[i-1];
		while(u){
			if(s[u+1]==s[i]){
				u=f[u];
				continue;
			}
			int res=w[*lower_bound(st,st+tp,i-u)];
			sum-=res;
			mp[res]--;
			u=nxt[u];
		}
		f[i-1]=s[i]==s[nxt[i-1]+1]?f[nxt[i-1]]:nxt[i-1];
		nxt[i]=nxt[i-1];
		while(nxt[i]&&s[nxt[i]+1]!=s[i]) nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i]) nxt[i]++;
		if(s[i]==s[1]){
			mp[w[i]]++;
			sum+=w[i];
		}
		add(ans1,ans2,sum);
		ans3+=sum;
		if(!ans1) printf("%lld\n",ans2);
		else printf("%lld%018lld\n",ans1,ans2);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}