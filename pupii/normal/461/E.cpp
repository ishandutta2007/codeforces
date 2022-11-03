#include<bits/stdc++.h>
typedef long long ll;
#define all(x) (x).begin(),(x).end()
#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
ll gi(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char T[100010];
int ch[1000010][4],cnt;
struct matrix{
	ll s[4][4];
	matrix(){memset(s,63,sizeof s);}
	ll*operator[](int x){return s[x];}
}Trans;
matrix operator*(matrix a,matrix b){
	matrix c;
	for(int j=0;j<4;++j)
		for(int i=0;i<4;++i)
			for(int k=0;k<4;++k)
				cnk(c[i][k],a[i][j]+b[j][k]);
	return c;
}
void DFS(int x,int st,int ed,int len){
	if(!x)return cnk(Trans[st][ed],len-1ll);
	for(int i=0;i<4;++i)DFS(ch[x][i],st,i,len+1);
}
int main(){
	ll m=gi();
	scanf("%s",T+1);int n=strlen(T+1);
	for(int i=1;i<=n;++i){
		int x=0;
		for(int j=0;j<10&&i+j<=n;++j){
			if(!ch[x][T[i+j]-'A'])ch[x][T[i+j]-'A']=++cnt;
			x=ch[x][T[i+j]-'A'];
		}
	}
	for(int i=0;i<4;++i)DFS(ch[0][i],i,i,1);
	ll ans=1;
	static matrix X,Tr[62];
	memset(X.s,0,sizeof X.s);
	Tr[0]=Trans;for(int i=1;i<62;++i)Tr[i]=Tr[i-1]*Tr[i-1];
	for(ll i=61;~i;--i){
		matrix _X=X*Tr[i];
		ll mn=9e18;
		for(int j=0;j<4;++j)for(int k=0;k<4;++k)cnk(mn,_X.s[j][k]);
		if(mn<m)X=_X,ans+=1ll<<i;
	}
	printf("%lld\n",ans);
	return 0;
}