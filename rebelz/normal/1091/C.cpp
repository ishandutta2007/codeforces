#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
ll ans[100005];

int main(){
	n=readint();
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			ans[++tot]=1ll*(n/i)*(n/i-1)/2*i+(n/i);
			if(n/i!=i) ans[++tot]=1ll*i*(i-1)/2*(n/i)+i;
		}
	}
	sort(ans+1,ans+tot+1);
	for(int i=1;i<=tot;i++) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}