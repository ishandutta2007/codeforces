#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;

int main(){
	n=readint(); k=readint();
	if(k==1){
		cout<<1;
		for(int i=2;i<=n;i++) cout<<0;
		cout<<endl;
	}
	else if(n>=3*k-2){
		for(int i=1;i<=(n+1)/2-(k+1)/2;i++) cout<<0;
		cout<<1;
		for(int i=1;i<=k-2;i++) cout<<0;
		cout<<1;
		for(int i=1;i<=(n+1)/2-(k+1)/2;i++) cout<<0;
		cout<<endl;
	}
	else{
		int d=(n-k)/2+1;
		for(int i=1;i<=n/d;i++){
			cout<<1;
			for(int j=1;j<=d-1;j++) cout<<0;
		}
		if(n/d*d<n) cout<<1;
		for(int i=n/d*d+2;i<=n;i++) cout<<0;
		cout<<endl;
	}
	return 0;
}