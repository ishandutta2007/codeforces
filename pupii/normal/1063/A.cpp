#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
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
char S[100010];
main(){
#ifndef ONLINE_JUDGE
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	int n=gi();scanf("%s",S+1);
	std::sort(S+1,S+n+1);
	printf("%s",S+1);
	return 0;
}