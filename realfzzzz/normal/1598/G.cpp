#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
const int maxn=5e5+5,maxm=2e5+5;
int n,m;
char s[maxn],t[maxm];
int nxt[maxm],ext[maxn];
const ll mod1=167772161,mod2=469762049,mod3=1004535809;
ll pw1[maxn],pw2[maxn],pw3[maxn];
ll hs1[maxn],hs2[maxn],hs3[maxn],x1=0,x2=0,x3=0;
ll hash1(int l,int r){
	return (hs1[r]-hs1[l-1]*pw1[r-l+1]%mod1+mod1)%mod1;
}
ll hash2(int l,int r){
	return (hs2[r]-hs2[l-1]*pw2[r-l+1]%mod2+mod2)%mod2;
}
ll hash3(int l,int r){
	return (hs3[r]-hs3[l-1]*pw3[r-l+1]%mod3+mod3)%mod3;
}
int a[maxm];
void check(int l1,int r1,int l2,int r2){
	if((hash1(l1,r1)+hash1(l2,r2))%mod1!=x1) return;
	if((hash2(l1,r1)+hash2(l2,r2))%mod2!=x2) return;
	if((hash3(l1,r1)+hash3(l2,r2))%mod3!=x3) return;
	memset(a,0,sizeof(a));
	for(int i=l1;i<=r1;i++) a[r1-i]+=s[i]-'0';
	for(int i=l2;i<=r2;i++) a[r2-i]+=s[i]-'0';
	int n=max(r1-l1+1,r2-l2+1);
	for(int i=0;i<n;i++) if(a[i]>10){
		a[i+1]++;
		a[i]-=10;
	}
	if(a[n]) n++;
	if(n!=m) return;
	for(int i=0;i<n;i++) if(a[i]!=t[m-i]-'0') return;
	printf("%d %d\n%d %d\n",l1,r1,l2,r2);
	exit(0);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	int l=0,r=0;
	nxt[1]=m;
	for(int i=2;i<=m;i++){
		if(i<=r) nxt[i]=min(nxt[i-l+1],r-i+1);
		while(i+nxt[i]<=m&&t[i+nxt[i]]==t[nxt[i]+1]) nxt[i]++;
		if(i+nxt[i]-1>r){
			l=i;
			r=i+nxt[i]-1;
		}
	}
	l=r=0;
	for(int i=1;i<=n;i++){
		if(i<=r) ext[i]=min(nxt[i-l+1],r-i+1);
		while(i+ext[i]<=n&&ext[i]<m&&s[i+ext[i]]==t[ext[i]+1]) ext[i]++;
		if(i+ext[i]-1>r){
			l=i;
			r=i+ext[i]-1;
		}
	}
	pw1[0]=pw2[0]=pw3[0]=1;
	for(int i=1;i<=n;i++){
		pw1[i]=pw1[i-1]*10%mod1;
		pw2[i]=pw2[i-1]*10%mod2;
		pw3[i]=pw3[i-1]*10%mod3;
	}
	for(int i=1;i<=n;i++){
		hs1[i]=(hs1[i-1]*10%mod1+s[i]-'0')%mod1;
		hs2[i]=(hs2[i-1]*10%mod2+s[i]-'0')%mod2;
		hs3[i]=(hs3[i-1]*10%mod3+s[i]-'0')%mod3;
	}
	for(int i=1;i<=m;i++){
		x1=(x1*10%mod1+t[i]-'0')%mod1;
		x2=(x2*10%mod2+t[i]-'0')%mod2;
		x3=(x3*10%mod3+t[i]-'0')%mod3;
	}
	if(m>1) for(int i=1;i+m*2-3<=n;i++) check(i,i+m-2,i+m-1,i+m*2-3);
	for(int i=1;i+m-1<=n;i++){
		if(m>ext[i]&&i+m*2-ext[i]-1<=n) check(i,i+m-1,i+m,i+m*2-ext[i]-1);
		if(m>ext[i]+1&&i+m*2-ext[i]-2<=n) check(i,i+m-1,i+m,i+m*2-ext[i]-2);
		if(m>ext[i]&&i>m-ext[i]) check(i-m+ext[i],i-1,i,i+m-1);
		if(m>ext[i]+1&&i>m-ext[i]-1) check(i-m+ext[i]+1,i-1,i,i+m-1);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}