#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,m,sum,t,ans;
ll a[200005],pre[200005],nxt[200005];

ll readint(){
	ll x=0; char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x;
}

int main(){
	n=readint(); t=readint();
	ll mina=1<<30;
	for(int i=1;i<=n;i++){
		a[i]=readint();
		sum+=a[i];
		mina=min(mina,a[i]);
	}
	ans+=(t/sum)*n;
	t%=sum;
	for(int i=1;i<=n;i++)
		pre[i]=i-1,nxt[i]=i+1;
	nxt[0]=1,pre[n+1]=n;
	int lnum=n;
	while(t>=mina){
		int now=nxt[0];
		while(now<=n){
			if(t>=a[now])
				t-=a[now],ans++;
			now=nxt[now];
		}
		if(t<mina)
			break;
		while(t>=mina){
			now=nxt[0],sum=0;
			bool flag=false;
			while(now<=n){
				if(t<a[now]){
					flag=true;
					lnum--;
					pre[nxt[now]]=pre[now];
					nxt[pre[now]]=nxt[now];
				}
				else
					sum+=a[now];
				now=nxt[now];
			}
			ans+=(t/sum)*lnum;
			t%=sum;
			if(!flag)
				break;
		}
	}
	cout<<ans<<endl;
	return 0;
}