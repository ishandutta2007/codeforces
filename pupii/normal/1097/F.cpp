#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::bitset<7001>s[100010],mu[7010],d[7010];
int pr[7001],P;bool yes[7001],MU[7001];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),q=gi(),o,x,y,z;
	MU[1]=1;
	for(int i=2;i<7001;++i){
		if(!yes[i])MU[i]=1,pr[++P]=i;
		for(int j=1;j<=P&&i*pr[j]<7001;++j){
			yes[i*pr[j]]=1;
			if(i%pr[j]==0){MU[i*pr[j]]=0;break;}
			MU[i*pr[j]]=MU[i];
		}
	}
	for(int i=1;i<7001;++i)
		for(int j=i;j<7001;j+=i)
			d[j][i]=1,mu[i][j]=MU[j/i];
	while(q--){
		o=gi();x=gi();
		if(o==1)s[x]=d[gi()];
		else if(o==2)y=gi(),z=gi(),s[x]=s[y]^s[z];
		else if(o==3)y=gi(),z=gi(),s[x]=s[y]&s[z];
		else putchar('0'+((s[x]&mu[gi()]).count()&1));
	}
	return 0;
}