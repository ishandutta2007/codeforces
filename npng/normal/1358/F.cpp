#include <cstdio>
template<typename Elem>
void swap(Elem &a,Elem &b){
	Elem t=a;
	a=b;
	b=t;
}
typedef long long ll;
const int Maxn=200000;
char s[3000005];
ll cnt,cnt2,n;
ll a[Maxn+5],b[Maxn+5];
int judge(){
	int i;
	if(b[1]==b[2]){
		return 0;
	}
	if(b[1]<b[2]){
		for(int i=2;i<n;i++){
			if(b[i]>=b[i+1]){
				return 0;
			}
		}
		return 1;
	}
	for(int i=2;i<n;i++){
		if(b[i]<=b[i+1]){
			return 0;
		}
	}
	return 2;
}
bool equal(){
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			flag=0;
			break;
		}
	}
	if(flag){
		return 1;
	}
	for(int i=1;i<=n;i++){
		if(a[n-i+1]!=b[i]){
			return 0;
		}
	}
	s[++cnt]='R';
	return 1;
}
void reverse(){
	for(int i=1,j=n;i<j;i++,j--){
		swap(b[i],b[j]);
	}
	return;
}
void diff(){
	for(int i=n;i>1;i--){
		b[i]=b[i]-b[i-1];
	}
	return;
}
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	if(n==1){
		if(a[1]==b[1]){
			puts("SMALL");
			puts("0");
		}
		else{
			puts("IMPOSSIBLE");
		}
		return 0;
	}
	if(n==2){
		ll a1=a[1],a2=a[2],b1=b[1],b2=b[2];
		if(a1>a2){
			swap(a1,a2);
		}
		if(b1>b2){
			swap(b1,b2);
		}
		while(a1!=b1&&b1>0){
			ll t=b1;
			cnt2+=b2/b1;
			b1=b2%b1;
			b2=t;
		}
		if(!b1||b2<a2){
			puts("IMPOSSIBLE");
			return 0;
		}
		else if((b2-a2)%b1==0){
			cnt2+=(b2-a2)/b1;
			if(cnt2>Maxn){
				puts("BIG");
				printf("%lld\n",cnt2);
				return 0;
			}
		}
		else{
			puts("IMPOSSIBLE");
			return 0;
		}
		cnt2=0;
	} 
	while(1){
		if(equal()){
			if(cnt2<=Maxn){
				puts("SMALL");
				printf("%lld\n",cnt);
				for(int i=cnt;i>0;i--){
					putchar(s[i]);
				}
			}
			else{
				puts("BIG");
				printf("%lld\n",cnt2);
			}
			return 0;
		}
		int t=judge();
		if(!t){
			puts("IMPOSSIBLE");
			return 0;
		}
		if(t==2){
			reverse();
			s[++cnt]='R';
		}
		diff();
		s[++cnt]='P';
		cnt2++;
	}
	return 0;
}