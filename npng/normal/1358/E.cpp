#include <cstdio>
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	if(f==-1){
		a=-a;
	}
}
const int Maxn=500000;
typedef long long ll;
int n;
int a[Maxn+5];
ll s[Maxn+5],t[Maxn+5];
ll f[Maxn+5];
int x;
int main(){
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=((n+1)>>1);i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	scanf("%d",&x);
	sum+=1ll*x*(n>>1);
	if(sum>0){
		printf("%d\n",n);
		return 0;
	}
	if(x>0){
		puts("-1");
		return 0;
	}
	for(int i=((n+1)>>1)+1;i<=n;i++){
		a[i]=x;
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=n;i>0;i--){
		t[i]=t[i+1]+a[i];
	}
	sum=0;
	for(int i=1;i<=((n+1)>>1);i++){
		f[i]=x-a[i];
		if(f[i-1]>0){
			f[i]+=f[i-1];
		}
		if(f[i]<0){
			f[i]=0;
		}
	}
	for(int i=1;i<=((n+1)>>1);i++){
		if(t[i+1]>f[i]){
			printf("%d\n",n-i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}