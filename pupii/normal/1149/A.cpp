// ZSY NIUBI
#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	int n=gi(),cnt[3]={0};
	for(int i=1;i<=n;++i)++cnt[gi()];
	if(!cnt[2])while(cnt[1]--)printf("1 ");
	else if(cnt[1]==0)for(int i=1;i<=n;++i)printf("2 ");
	else if(cnt[1]==1){
		printf("2 ");--cnt[2];printf("1 ");
		while(cnt[2]--)printf("2 ");
	}else if(cnt[1]==2){
		printf("2 ");--cnt[2];printf("1 ");
		while(cnt[2]--)printf("2 ");
		printf("1 ");
	}else{
		printf("1 1 1 ");cnt[1]-=3;
		while(cnt[2]--)printf("2 ");
		while(cnt[1]--)printf("1 ");
	}
	return 0;
}