#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int b,k,x,cnt;

int main(){
	b=readint(); k=readint();
	for(int i=1;i<=k;i++){
		x=readint();
		if(b&1) cnt^=x&1;
	}
	if(!(b&1)) cnt^=x&1;
	if(cnt==0) cout<<"even"<<endl;
	else cout<<"odd"<<endl;
	return 0;
}