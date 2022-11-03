// It is made by XZZ
#include<bits/stdc++.h>
#define int long long
#define il inline
#define rg register
#define vd void
#define sta static
typedef long long ll;
using namespace std;
il int gi(){
    rg int x=0,f=1;rg char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char S[100010];
main(){
	int T=gi();
	while(T--){
		int n=gi();
		scanf("%s",S+1);
		for(int i=1;i<=n;++i)if(abs(S[i]-S[n-i+1])==1||abs(S[i]-S[n-i+1])>2){puts("NO");goto gg;}
		puts("YES");
		gg:;
	}
    return 0;
}