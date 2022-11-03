#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::bitset<1001>G[1001],x,intree,MN,Edge[1001];
bool operator!=(const std::bitset<1001>a,const std::bitset<1001>b){
	for(int i=1;i<=1000;++i)if(a[i]!=b[i])return 1;
	return 0;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i){
		int k=gi();
		while(k--)G[i][gi()]=1;
	}
	int a,b,c=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			x=G[i]&G[j];
			if(x.count()==2){
				a=x._Find_first(),b=x._Find_next(a);
				if(Edge[a][b])continue;
				printf("%d %d\n",a,b);++c;
				intree[a]=intree[b]=1;
				Edge[a][a]=Edge[b][b]=Edge[a][b]=Edge[b][a]=1;
			}
		}
	if(c==0)for(int i=1;i<n;++i)printf("%d %d\n",i,n);
	else if(c==1){
		std::bitset<1001>A,B;
		for(int i=1;i<=n;++i)
			if(G[i].count()<n&&A!=G[i]&&B!=G[i])
				if(!A.count())A=G[i];
				else B=G[i];
		for(int i=1;i<=n;++i)if(!intree[i])printf("%d %d\n",A[i]?a:b,i);
	}else{
		for(int i=1;i<=n;++i)
			if(!intree[i]){
				for(int j=1;j<=n;++j)MN[j]=1;
				for(int j=1;j<=n;++j)
					if(G[j][i]){
						x=G[j]&intree;
						if(x.count()<MN.count())MN=x;
					}
				for(int j=MN._Find_first();j<=n;j=MN._Find_next(j))
					if(Edge[j]==MN)
						{printf("%d %d\n",i,j);break;}
			}
	}
	return 0;
}