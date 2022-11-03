#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
char s[100];
char S[100];
main(){
	srand(time(NULL));
	int n=gi()-1,l=1,r=1000000000,mid,mxa=0,mnb=1e9;
	printf("%d %d\n",0,0);fflush(stdout);
	if(n==0){
		printf("%d %d %d %d\n",1,0,1,100000);
		fflush(stdout);
		return 0;
	}
	scanf("%s",S+1);
	while(n--){
		mid=(l+r)>>1;
		printf("%d %d\n",mid,mid);
		fflush(stdout);
		scanf("%s",s+1);
		if(s[1]==S[1])mxa=std::max(mxa,mid),l=mid+1;
		else mnb=std::min(mnb,mid),r=mid-1;
	}
	printf("%d %d %d %d\n",mxa,mnb,mnb,mxa);
	fflush(stdout);
	return 0;
}