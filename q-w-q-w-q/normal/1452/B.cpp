#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n,a[100001];
ll ans,sum,tp;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++) scanf("%d",a+i),sum+=a[i];
		sort(a+1,a+1+n);
		ans=0;
		if(sum%(n-1)) ans=n-1-sum%(n-1),sum+=n-1-sum%(n-1);
		if(1ll*a[n]*(n-1)>sum){
			tp=1ll*a[n]*(n-1);
			ans+=tp-sum;
		}
		cout<<ans<<endl;
	}
}