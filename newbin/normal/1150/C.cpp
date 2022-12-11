#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 4e5 + 50;
int he[maxn];
int a1,a2;
int a[maxn];
int s[maxn];
int main(){
	he[0] = he[1] = 1;
	for(int i = 4;i < maxn;i+=2) he[i] = 1;
	for(int i = 3;i*i < maxn;i+=2){
		if(!he[i])
		for(int j = i*i;j < maxn;j+=2*i){
			he[j] = 1;
		}
	}
	int n;cin>>n;
	for(int i = 0;i < n;++i){
		int t;scanf("%d",&t);
		if(t == 1) a1++;
		else a2++;
	}
	a[0] = s[0] = 0;
	for(int i = 1;i <= n;++i){
		if(!he[s[i-1] + 2] && a2){
			s[i] = s[i-1] + 2;
			a[i] = 2;a2--;
		}
		else if(!he[s[i-1] + 1] && a1){
			s[i] = s[i-1] + 1;
			a[i] = 1;a1--;
		}
		else if(a2){
			s[i] = s[i-1] + 2;
			a[i] = 2;a2--;
		}
		else {
			s[i] = s[i-1] + 1;
			a[i] = 1;a1--;
		}
	}
	printf("%d",a[1]);
	for(int i = 2;i <= n;++i) printf(" %d",a[i]);
	printf("\n");
}