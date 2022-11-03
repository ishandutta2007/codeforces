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
char S[233];
main(){
	int n=gi();scanf("%s",S+1);
	for(rg int i=1;i<n;++i)if(S[i]==S[i+1]&&S[i]!='?'){puts("No");return 0;}
	for(rg int i=1;i<=n;++i)
		if(S[i]=='?'){
			if(S[i+1]=='?'){puts("Yes");return 0;}
			else if(S[i-1]==S[i+1]||i==1||i==n){puts("Yes");return 0;}
		}
	puts("No");
    return 0;
}