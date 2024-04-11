#include<bits/stdc++.h>
#define il inline
#define vd void
#define ll long long
il int gi(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
char A[1000100],B[1000100];
int S[3][3][1000100],n,m;
int main(){
	scanf("%s",A+1),scanf("%s",B+1);
	n=strlen(A+1),m=strlen(B+1);
	for(int i=1;i<=n;++i)
	    if(A[i]=='R')A[i]='A';
	    else if(A[i]=='G')A[i]='B';
	    else A[i]='C';
	for(int i=1;i<=m;++i)
	    if(B[i]=='R')B[i]='A';
	    else if(B[i]=='G')B[i]='B';
	    else B[i]='C';
	for(int i=2;i<=m;++i){
		++S[B[i-1]-'A'][B[i]-'A'][i];
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				S[j][k][i]+=S[j][k][i-1];
	}
	int j1=1,j2=1;
	ll ans=0;
	for(int i=1;i<=n;++i){
		while(j2<m&&A[i]!=B[j2])++j2;
		ll Ans=ans;
		ans+=j2-j1+1;
		if(i!=1&&A[i]!=A[i-1])ans-=S[A[i]-'A'][A[i-1]-'A'][j2]-S[A[i]-'A'][A[i-1]-'A'][j1];
		if(j1<=m&&A[i]==B[j1])++j1;
		if(j2<m&&A[i]==B[j2])++j2;
		if(j1>m)break;
	}
	printf("%lld\n",ans);
	return 0;
}