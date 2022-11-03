#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int siz[510],s[510];
il bool cmp_siz(const int&x,const int&y){return siz[x]<siz[y];}
std::vector<int>S;
int fa[510];
int main(){
	int n=gi();
	for(int i=2;i<=n;++i){
		printf("1\n1\n%d\n",n-1);
		for(int j=2;j<=n;++j)printf("%d ",j);puts("");
		printf("%d\n",i);
		fflush(stdout);siz[i]=gi();
	}
	siz[1]=n;
	for(int i=1;i<=n;++i)s[i]=i;
	std::sort(s+1,s+n+1,cmp_siz);
	for(int i=1;i<=n;++i){
		int x=s[i];
		while(!S.empty()){
			printf("1\n1\n%d\n",S.size());
			for(auto j:S)printf("%d ",j);
			puts("");
			printf("%d\n",x);
			fflush(stdout);if(gi()==0)break;
			int l=0,r=S.size()-1,mid;
			while(l<r){
				mid=(l+r)>>1;
				printf("1\n1\n%d\n",mid+1);
				for(int j=0;j<=mid;++j)printf("%d ",S[j]);
				puts("");
				printf("%d\n",x);
				fflush(stdout);
				if(gi()==0)l=mid+1;
				else r=mid;
			}
			fa[S[l]]=x;
			S.erase(S.begin()+l);
		}
		if(x!=1)S.push_back(x);
	}
	puts("ANSWER");
	for(int i=2;i<=n;++i)printf("%d %d\n",fa[i],i);
	fflush(stdout);
	return 0;
}