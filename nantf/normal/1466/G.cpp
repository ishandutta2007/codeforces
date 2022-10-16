#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=1000000007,bs1=61,bs2=251,mod1=1004535809,mod2=999911659,hhh=1000000;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,q,mx,len[22],ans[maxn],cnt,id[maxn],fail[maxn],que[maxn],h,r,sss[maxn],x[maxn],fl,ch[maxn][26];
int pre1[maxn*2],pre2[maxn*2],suf1[maxn*2],suf2[maxn*2];
char s0[maxn],s[maxn*2],t[maxn],str[maxn*2];
bool ok[maxn];
struct fuck_the_mle{
	int at,pos,id;
	bool operator <(const fuck_the_mle &f)const{
		if(at!=f.at) return at<f.at;
		return pos<f.pos;
	}
}fff[maxn];
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
} 
void insert(const char *s,int d){
	int now=0,l=strlen(s+1);
	FOR(i,1,l){
		int p=s[i]-'a';
		if(!ch[now][p]) ch[now][p]=++cnt;//,printf("add %d\n",cnt);
		now=ch[now][p];
	}
	id[d]=now;
}
void build(){
	h=1;r=0;
	FOR(i,0,25) if(ch[0][i]) que[++r]=ch[0][i];
	while(h<=r){
		int now=que[h++];
		FOR(i,0,25) if(ch[now][i]){
			fail[ch[now][i]]=ch[fail[now]][i];
			que[++r]=ch[now][i];
		}
		else ch[now][i]=ch[fail[now]][i];
	}
}
void work(int vs){
//	printf("work %d\n",vs);
	FOR(i,1,cnt) sss[i]=0;
	int now=0,l=strlen(s+1);
	FOR(i,1,l){
		int p=s[i]-'a';
		now=ch[now][p];
		sss[now]++;
//		printf("add at %d\n",now);
	}
	ROF(i,r,1) sss[fail[que[i]]]=(sss[fail[que[i]]]+sss[que[i]])%mod;
//	FOR(i,1,cnt) printf("%d ",sss[i]);
//	puts("");
	int tmp=qpow(2,mod-1-vs);
	FOR(i,1,q) if(vs==min(mx,x[i])) ans[i]=(ans[i]+1ll*sss[id[i]]*tmp)%mod;
//	FOR(i,1,q){
//		printf("%lld ",1ll*ans[i]*qpow(2,x[i])%mod);
//	}
//	puts("");
}
int main(){
	n=read();q=read();
	scanf("%s%s",s0+1,t+1);
	len[0]=strlen(s0+1);
	strcpy(s+1,s0+1);
	FOR(i,1,n){
		mx=i;
		strcpy(str+1,s+1);
		s[len[i-1]+1]=t[i];
		strcat(s+1,str+1);
		len[i]=2*len[i-1]+1; 
		if(len[i]>=hhh) break;
	}
	FOR(i,1,len[mx]){
		pre1[i]=(1ll*pre1[i-1]*bs1+s[i]-'a')%mod1;
		pre2[i]=(1ll*pre2[i-1]*bs2+s[i]-'a')%mod2;
	}
	int pr1=1,pr2=1;
	ROF(i,len[mx],1){
		suf1[i]=(suf1[i+1]+1ll*(s[i]-'a')*pr1)%mod1;
		suf2[i]=(suf2[i+1]+1ll*(s[i]-'a')*pr2)%mod2;
		pr1=1ll*pr1*bs1%mod1;
		pr2=1ll*pr2*bs2%mod2;
	}
/*	FOR(i,mx+1,n){
		FOR(j,0,25) sum[i][j]=sum[i-1][j];
		sum[i][t[i]-'a']=(sum[i][t[i]-'a']+qpow(2,mod-1-i))%mod;
	}*/
	FOR(_,1,q){
		x[_]=read();
		scanf("%s",str+1);
		int l=strlen(str+1);
		insert(str,_);
		if(x[_]<=mx || l>len[mx]) continue; 
		FOR(i,1,l) ok[i]=true;
		int hs1=0,hs2=0;
		FOR(i,1,l-1){
			hs1=(1ll*hs1*bs1+str[i]-'a')%mod1;
			hs2=(1ll*hs2*bs2+str[i]-'a')%mod2;
			ok[i+1]&=hs1==suf1[len[mx]-i+1] && hs2==suf2[len[mx]-i+1];
		}
		hs1=hs2=0;
		int pr1=1,pr2=1;
		ROF(i,l,2){
			hs1=(hs1+1ll*(str[i]-'a')*pr1)%mod1;
			hs2=(hs2+1ll*(str[i]-'a')*pr2)%mod2;
			ok[i-1]&=hs1==pre1[l-i+1] && hs2==pre2[l-i+1];
			pr1=1ll*pr1*bs1%mod1;
			pr2=1ll*pr2*bs2%mod2;
		}
		FOR(i,1,l) if(ok[i]) fff[++fl]=(fuck_the_mle){str[i]-'a',x[_],_};
//		FOR(i,1,l) if(ok[i]) ans[_]=(ans[_]+sum[x[_]][str[i]-'a'])%mod;
	}
	sort(fff+1,fff+fl+1);
	int cur=1;
	FOR(i,0,25){
		while(cur<=fl && fff[cur].at<i) cur++;
		int sum=0;
		FOR(j,mx+1,n){
			if(t[j]-'a'==i) sum=(sum+qpow(2,mod-1-j))%mod;
			while(cur<=fl && fff[cur].at==i && fff[cur].pos<j) cur++;
			while(cur<=fl && fff[cur].at==i && fff[cur].pos==j){
				ans[fff[cur].id]=(ans[fff[cur].id]+sum)%mod;
				cur++;
			}
		}
	}
	build();
	MEM(s,0);
	strcpy(s+1,s0+1);
	work(0);
	FOR(i,1,n){
		strcpy(str+1,s+1);
		s[len[i-1]+1]=t[i];
		strcat(s+1,str+1);
		len[i]=2*len[i-1]+1;
//		printf("%s\n",s+1);
		work(i);
		if(len[i]>=hhh) break;
	}
	FOR(i,1,q){
		ans[i]=1ll*ans[i]*qpow(2,x[i])%mod;
		printf("%d\n",ans[i]);
	}
}