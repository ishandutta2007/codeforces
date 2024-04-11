#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll k;

int main(){
	k=readint();
	int n=1500,ns=n+k+1;
	cout<<n+1<<endl;
	cout<<-1<<' ';
	for(int i=1;i<=n;i++){
		int tmp=min(1000000,ns);
		ns-=tmp;
		cout<<tmp<<' ';
	}
	cout<<endl;
	return 0;
}