#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int q,a,b,c;

int main(){
	q=readint();
	while(q--){
		a=readint(); b=readint(); c=readint();
		if(c>=a) cout<<(b/c+1)*c<<endl;
		else cout<<c<<endl;
	}
	return 0;
}