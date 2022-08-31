#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int cnt=0,n;
bool fl[100005];
int prm[100005];

void getprime(int g){
	fl[1]=true;
	for(int i=2;i<=g;i++){
		if(!fl[i]) prm[++cnt]=i;
		for(int j=1;j<=cnt&&i*prm[j]<=g;j++){
			fl[i*prm[j]]=true;
			if(i%prm[j]==0) break;
		}
	}
}

int main(){
	getprime(2000);
	n=readint();
	for(int i=0;i<=n-3;i++){
		if(!fl[2+i]&&!fl[n+i]){
			cout<<n+i<<endl;
			for(int j=1;j<=n;j++) cout<<j<<' '<<j%n+1<<endl;
			for(int j=1;j<=i;j++) cout<<1<<' '<<j+2<<endl;
			return 0;
		}
	}
	for(int i=0;i<=n/2;i++){
		if(!fl[n+i]){
			cout<<n+i<<endl;
			for(int j=1;j<=n;j++) cout<<j<<' '<<j%n+1<<endl;
			for(int j=1;j<=i;j++) cout<<j<<' '<<(j+n/2-1)%n+1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}