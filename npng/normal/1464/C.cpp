#include <cstdio>
typedef long long ll;
const int Maxn=100000;
int n;
ll T;
char s[Maxn+5];
int a[Maxn+5];
int num[26];
bool ned[26];
int main(){
	scanf("%d%lld",&n,&T);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'a';
	}
	T-=(1ll<<a[n]);
	T+=(1ll<<a[n-1]);
	n-=2;
	for(int i=1;i<=n;i++){
		num[a[i]]++;
	}
	if(T<0){
		T=-T;
	}
	for(int i=25;i>=0;i--){
		while(num[i]--){
			T-=(1ll<<i);
			if(T<0){
				T=-T;
			}
		}
	}
	if(T==0){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}