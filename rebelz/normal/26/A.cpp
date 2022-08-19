#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cnt,tot,ans;
bool flag[3005];
int prime[3005];

void getprime(int x){
	flag[1]=true;
	for(int i=2;i<=x;i++){
		if(!flag[i]) prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=x;j++){
			flag[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}

int main(){
	getprime(3000);
	n=readint();
	for(int i=2;i<=n;i++){
		cnt=0;
		for(int j=1;j<=tot;j++) if(i%prime[j]==0) cnt++;
		if(cnt==2) ans++;
	}
	cout<<ans<<endl;
	return 0;
}