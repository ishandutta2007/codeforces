#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int x=1;
	int s=0;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
int T,n,k1,k2,w,b;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k1>>k2>>w>>b;
		bool flag=0; 
		int zd=min(k1,k2);
		zd+=(abs(k1-k2)/2);
		if(zd<w)flag=1;
		int hd=min(n-k1,n-k2);
		hd+=abs((k1-k2)/2);
		if(hd<b)flag=1;
		if(flag)puts("NO");
		else puts("YES");
	}
	return 0;
}