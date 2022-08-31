#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
char a[21][100005];
ll A[1100000],B[1100000],d[1100000];

void fwt(ll *A,int n,int f){
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;j+=(i<<1)){
			for(int k=j;k<j+i;k++){
				ll x=A[k],y=A[k+i];
				A[k]=(x+y)/(f>0?1:2),A[k+i]=(x-y)/(f>0?1:2);
			}
		}
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	int now=0;
	for(int i=1;i<=m;i++){
		now=0;
		for(int j=1;j<=n;j++) now=now<<1|(a[j][i]-'0');
		A[now]++;
	}
	d[0]=0;
	for(int i=1;i<(1<<n);i++) d[i]=d[i-(i&(-i))]+1;
	for(int i=0;i<(1<<n);i++) B[i]=min(d[i],n-d[i]);
	fwt(A,1<<n,1); fwt(B,1<<n,1);
	for(int i=0;i<(1<<n);i++) A[i]=A[i]*B[i];
	fwt(A,1<<n,-1);
	ll ans=1ll<<60;
	for(int i=0;i<(1<<n);i++) ans=min(ans,A[i]);
	cout<<ans<<endl;
	return 0;
}