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
ll A[1000010],B[1000010];
bool yes[1000010];
int _i[1000010],_j[1000010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)A[i]=A[i-1]+gi();
	for(int i=1;i<=n;++i)B[i]=B[i-1]+gi();
	bool swp=0;
	if(A[n]>B[n])swp=1,std::swap(A,B);
	for(int i=0,j=0;i<=n;++i){
		while(A[i]>B[j])++j;
		if(yes[B[j]-A[i]]){
			if(!swp){
			printf("%d\n",i-_i[B[j]-A[i]]);
			for(int k=_i[B[j]-A[i]]+1;k<=i;++k)printf("%d ",k);
			puts("");
			printf("%d\n",j-_j[B[j]-A[i]]);
			for(int k=_j[B[j]-A[i]]+1;k<=j;++k)printf("%d ",k);
			puts("");
			}else{
			printf("%d\n",j-_j[B[j]-A[i]]);
			for(int k=_j[B[j]-A[i]]+1;k<=j;++k)printf("%d ",k);
			puts("");
			printf("%d\n",i-_i[B[j]-A[i]]);
			for(int k=_i[B[j]-A[i]]+1;k<=i;++k)printf("%d ",k);
			puts("");
			}
			return 0;
		}
		yes[B[j]-A[i]]=1;
		_i[B[j]-A[i]]=i;
		_j[B[j]-A[i]]=j;
	}
	return 0;
}