#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back()
#define all(a) a.begin(),a.end()
using namespace std;
void voi(){
	int n,a[205];
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int g=0;bool f=1;
		for(int j=i;j<=n;j++){
			if(a[j]!=++g){
				f=0;break;
			}
		}
		for(int j=1;j<i;j++){
			if(a[j]!=++g){
				f=0;break;
			}
		}
		if(f){
			puts("YES");return ;
		}
		g=n+1;f=1;
		for(int j=i;j<=n;j++){
			if(a[j]!=--g){
				f=0;break;
			}
		}
		for(int j=1;j<i;j++){
			if(a[j]!=--g){
				f=0;break;
			}
		}
		if(f){
			puts("YES");return ;
		}
	}
	puts("NO");
}
int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)voi();
	return 0;
}