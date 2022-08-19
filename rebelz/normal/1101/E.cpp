#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,x,y,maxx,maxy;
char opt;

int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		cin>>opt; x=readint(); y=readint();
		if(opt=='+'){
			if(x>y) swap(x,y);
			maxx=max(maxx,x);
			maxy=max(maxy,y);
		}
		else{
			if(x>y) swap(x,y);
			if(maxx<=x&&maxy<=y) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}