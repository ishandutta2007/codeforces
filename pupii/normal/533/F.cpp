#include<bits/stdc++.h>
#define vd void
#define mod1 998244353
#define mod2 1000000009
#define mod3 998244853
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int pow(int x,int y,int mo){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mo;
		x=1ll*x*x%mo;y>>=1;
	}
	return ret;
}
int Base1[200010],Base2[200010],Base3[200010];
const int iB1=pow(19260817,mod1-2,mod1);
const int iB2=pow(19491001,mod2-2,mod2);
const int iB3=pow(23333,mod3-2,mod3);
struct Hash{
	int H1,H2,H3,len;
	Hash(int a=0,int b=0,int c=0,int d=0){H1=a,H2=b,H3=c,len=d;}
	void pop_front(){
		--len;
		H1=1ll*(H1-1+mod1)*iB1%mod1;
		H2=1ll*(H2-2+mod2)*iB2%mod2;
		H3=1ll*(H3-3+mod3)*iB3%mod3;
	}
	void update(int p,int x){
		--p;
		H1=(H1-1ll*Base1[p]*x%mod1+mod1)%mod1;
		H2=(H2-1ll*Base2[p]*x%mod2+mod2)%mod2;
		H3=(H3-1ll*Base3[p]*x%mod3+mod3)%mod3;
	}
}HS,HT;
Hash operator+(const Hash&A,const Hash&B){
	return{
		(A.H1+1ll*Base1[A.len]*B.H1)%mod1,
		(A.H2+1ll*Base2[A.len]*B.H2)%mod2,
		(A.H3+1ll*Base3[A.len]*B.H3)%mod3,
		A.len+B.len
	};
}
Hash cth(int s){return{s+1,s+2,s+3,1};}
bool operator==(const Hash&A,const Hash&B){return A.H1==B.H1&&A.H2==B.H2&&A.H3==B.H3&&A.len==B.len;}
char S[200010],T[200010];
int preT[200010],lst[128],preS[200010],nxtS[200010];
int ans[200010],k,K;
std::vector<int>qaqS[26],qaqT[26];
int main(){
	int n=gi(),m=gi();
	Base1[0]=1;for(int i=1;i<=n;++i)Base1[i]=Base1[i-1]*19260817ll%mod1;
	Base2[0]=1;for(int i=1;i<=n;++i)Base2[i]=Base2[i-1]*19491001ll%mod2;
	Base3[0]=1;for(int i=1;i<=n;++i)Base3[i]=Base3[i-1]*23333ll%mod3;
	scanf("%s",S+1),scanf("%s",T+1);
	for(int i=1;i<=m;++i)T[i]-='a',preT[i]=lst[T[i]],lst[T[i]]=i;
	memset(lst,0,sizeof lst);
	for(int i=1;i<=n;++i)S[i]-='a',preS[i]=lst[S[i]],lst[S[i]]=i;
	memset(lst,0,sizeof lst);
	for(int i=n;i;--i)nxtS[i]=lst[S[i]],lst[S[i]]=i;
	memset(lst,0,sizeof lst);
	for(int i=1;i<=m;++i)if(preT[i])preT[i]=i-preT[i];
	for(int i=1;i<=n;++i)if(preS[i])preS[i]=i-preS[i];
	for(int i=1;i<=m;++i)HT=HT+cth(preT[i]);
	for(int i=1;i<=m;++i)HS=HS+cth(preS[i]);
	for(int i=1;i<=n-m+1;++i){
		if(HS==HT)ans[++k]=i;
		HS.pop_front();
		if(nxtS[i]){
			if(nxtS[i]<=i+m-1)HS.update(nxtS[i]-i,preS[nxtS[i]]);
			else preS[nxtS[i]]=0;
		}
		HS=HS+cth(preS[i+m]);
	}
	for(int i=1;i<=m;++i)qaqT[T[i]].push_back(i);
	for(int i=0;i<26;++i)qaqT[i].push_back(n+1);
	for(int i=1;i<=n;++i)qaqS[S[i]].push_back(i);
	for(int i=0;i<26;++i)qaqS[i].push_back(n+1);
	for(int i=0;i<26;++i){
		for(int j=1;j<=k;++j)
			if(ans[j]){
				int ps=*std::lower_bound(qaqS[i].begin(),qaqS[i].end(),ans[j]);
				int pt=qaqT[i][0];
				if(ps<ans[j]+m&&pt<ans[j]+m&&ps-ans[j]+1!=pt&&S[ans[j]+pt-1]!=T[ps-ans[j]+1])ans[j]=0;
			}
	}
	for(int i=1;i<=k;++i)if(ans[i])++K;
	printf("%d\n",K);
	for(int i=1;i<=k;++i)if(ans[i])printf("%d ",ans[i]);
	return 0;
}