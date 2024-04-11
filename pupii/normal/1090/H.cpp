#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
int s[18][200010],c[200010];
char S[200010];
int main(){
	int n,m;scanf("%d%s%d",&n,S+1,&m);
	for(int i=n-1;i;--i){
		c[i]=(S[i]-'0')^(S[i+1]-'0');
		for(int j=1;j<18;++j)s[j][i]=c[i];
		for(int j=1;i+(1<<j)<n&&j<18;++j)s[j][i]+=s[j][i+(1<<j)];
	}
	while(m--){
		int l,r,res=0;scanf("%d%d",&l,&r),++l;
		for(int i=1,len=(r-l+2)>>1;i<18&&1<<i<=r-l+1;++i,len>>=1){
			int t=s[i][l+(1<<i-1)-1]-s[i][r-(1<<i-1)+1]+c[r-(1<<i-1)+1];
			res+=std::min(t,len-t);
		}
		printf("%d\n",res+1>>1);
	}
	return 0;
}