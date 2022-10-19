#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;
long long n,k;
bool ck[maxn];
int ans[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	long long t=k;
	if (k<n*(n+1)/2){
		cout<<-1<<endl;
		return 0;
	}
	k-=n*(n+1)/2;
	int i=1;
	while (k&&i<=n){
		if (k>=n+1-2*i){
			ans[i]=n+1-i;
			ck[n+1-i]=1;
			k-=max(n+1-2*i,(long long)0);
		}
		else{
			ans[i]=i+k;
			ck[i+k]=1;
			k=0;
		}
		++i;
	}
	int j=1;
	for (;i<=n;++i){
		while (ck[j]){
			j++;
		}
		ans[i]=j;
		++j;
	}
	cout<<t-k<<endl;
	for (int i=1;i<=n;++i){
		cout<<i<<" ";
	}
	cout<<endl;
	for (int i=1;i<=n;++i){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}