#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int A[410][410],f[410][410];
std::unordered_map<int,int>M[410];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			A[i][j]=gi();
	for(int i=1;i<=m;++i)
		for(int j=i;j<=m;++j)
			f[i][j]=1;
	int ans=1;
	for(int i=1;i<=n;++i){
		if(i>1)for(int j=1;j<=m;++j)M[j][A[i-1][j]]=i;
		for(int j=1;j<=m;++j){
			if(M[j].count(A[i][j]))f[j][j]=std::max(f[j][j],M[j][A[i][j]]);
			ans=std::max(ans,i-f[j][j]+1);
		}
		for(int s=2;s<=m;++s)
			for(int l=1,r=s;r<=m;++l,++r){
				f[l][r]=std::max(f[l][r],std::max(f[l][r-1],f[l+1][r]));
				if(M[l].count(A[i][r]))f[l][r]=std::max(f[l][r],M[l][A[i][r]]);
				if(M[r].count(A[i][l]))f[l][r]=std::max(f[l][r],M[r][A[i][l]]);
				if(A[i][l]==A[i][r])f[l][r]=i+1;
				ans=std::max(ans,s*(i-f[l][r]+1));
			}
	}
	printf("%d\n",ans);
	return 0;
}