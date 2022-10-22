#include <bits/stdc++.h>
using namespace std;
#define pd push_back
#define ve vector
#define ll long long 
#define qu queue
#define pq priority_queue
void voi(){
	int n,m,k,t,a[1005];
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		t=max(0,a[i+1]-k);
		if(a[i]<t){
			if(t-a[i]>m){
				cout<<"NO\n";return ;
			}else m-=(t-a[i]);
		}else m+=(a[i]-t);
	}
	cout<<"YES\n";
}
int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)voi();
	return 0;
}