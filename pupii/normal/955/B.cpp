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
char S[100002];
int n;
map<char,int>fafa;
main(){
	scanf("%s",S+1);
	n=strlen(S+1);
	for(rg int i=1;i<=n;++i)++fafa[S[i]];
	if(fafa.size()==1)puts("No");
	else if(fafa.size()==2){
		if(fafa.begin()->second==1||(++fafa.begin())->second==1)puts("No");
		else puts("Yes"); 
	}else if(fafa.size()==3){
		if(fafa.begin()->second!=1||(++fafa.begin())->second!=1||(++(++fafa.begin()))->second!=1)puts("Yes");
		else puts("No"); 
	}else if(fafa.size()==4)puts("Yes");
	else puts("No");
    return 0;
}