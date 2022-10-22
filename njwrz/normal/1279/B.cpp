#include<bits/stdc++.h>
using namespace std;
int a[100005];
void solve(){
	int n,maxi=-1,maxt=0,s=0,t,an1,an2,sh=0;
	scanf("%d%d",&n,&t);an1=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		s+=a[i];
		if(a[i]>maxt){
			maxt=a[i];
			maxi=i;
		}
		if(s>t){
			if(sh){
				cout<<sh<<'\n';return ;
			}
			an1=i-1;
			s-=maxt;sh=maxi;
			if(s>t){
				puts("0");return ;
			}
		}
	}
	if(sh){
		cout<<sh<<'\n';
	}else{
		puts("0");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}