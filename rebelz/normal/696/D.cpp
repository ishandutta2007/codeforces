#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct matrix{
	int n;
	ll a[205][205];
	matrix operator*(const matrix c)const{
		matrix ret;
		ret.n=n;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				ret.a[i][j]=-(1ll<<61);
				for(int k=0;k<=n;k++) ret.a[i][j]=max(ret.a[i][j],a[i][k]+c.a[k][j]);
			}
		}
		return ret;
	}
}c,ans;

ll n,l,root,cnt;
ll q[205],ch[205][30],fail[205],b[205],val[205];
char s[205];

void insert(char *t,ll g){
	int m=strlen(t+1),p=root;
	for(int i=1;i<=m;i++){
		if(!ch[p][t[i]-'a']) ch[p][t[i]-'a']=++cnt;
		p=ch[p][t[i]-'a'];
	}
	val[p]+=g;
}

void buildac(){
	int front=0,rear=0;
	q[rear++]=root;
	while(front<rear){
		int t=q[front++];
		val[t]+=val[fail[t]];
		for(int i=0;i<26;i++){
			if(ch[t][i]){
				q[rear++]=ch[t][i];
				if(!t) fail[ch[t][i]]=0;
				else fail[ch[t][i]]=ch[fail[t]][i];
			}
			else ch[t][i]=ch[fail[t]][i];
		}
	}
}

void power(ll p){
	for(int i=1;i<=cnt;i++) ans.a[0][i]=-(1ll<<61);
	for(;p;p>>=1,c=c*c) if(p&1) ans=ans*c;
}

int main(){
	n=readint(); l=readint();
	for(int i=1;i<=n;i++) b[i]=readint();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		insert(s,b[i]);
	}
	buildac();
	for(int i=0;i<=cnt;i++) for(int j=0;j<=cnt;j++) c.a[i][j]=-(1ll<<61);
	for(int i=0;i<=cnt;i++) for(int j=0;j<26;j++) if(ch[i][j]) c.a[i][ch[i][j]]=val[ch[i][j]];
	c.n=ans.n=cnt;
	power(l);
	ll ret=0;
	for(int i=0;i<=cnt;i++) ret=max(ret,ans.a[0][i]);
	cout<<ret<<endl;
	return 0;
}