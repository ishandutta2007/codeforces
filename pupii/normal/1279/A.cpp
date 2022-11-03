#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int main(){
	int T=gi();
	while(T--){
		std::vector<ll>a;
		for(int i=0;i<3;++i)a.push_back(gi());
		std::sort(a.begin(),a.end());
		if(a[0]+a[1]+1<a[2])puts("No");
		else puts("Yes");
	}
	return 0;
}