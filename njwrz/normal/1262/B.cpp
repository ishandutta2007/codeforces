#include<bits/stdc++.h>
using namespace std;
int a[100005],v[100005],f[100005];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],v[i]=0,f[i]=0;
	f[a[1]]=1;int l=1;v[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			v[i]=a[i];
			if(f[a[i]]){
				puts("-1");return ;
			}
			f[a[i]]=1;
		}else{
			while(f[l])l++;
			v[i]=l;f[l]=1;
		}
	}
	int maxi=0;
	for(int i=1;i<=n;i++){
		maxi=max(maxi,v[i]);
		if(maxi!=a[i]){
			puts("-1");return ;
		}
	}
	for(int i=1;i<=n;i++)cout<<v[i]<<' ';
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)solve(); 
	return 0;
}