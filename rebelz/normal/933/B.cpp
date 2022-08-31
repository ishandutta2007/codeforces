#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll p,k,cnt;
ll ans[10000005];

int main(){
	p=readint(); k=readint();
	while(p>=k||p<0){
//		cout<<"TEST "<<cnt<<' '<<p<<endl;
		ans[++cnt]=(p%k+k)%k;
		p=(ans[cnt]-p)/k;
	}
	ans[++cnt]=p;
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}