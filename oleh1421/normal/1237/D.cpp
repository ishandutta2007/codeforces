#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
int a[300001];
const int L=19;
int dp[L+1][300001];
int c[300001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
  	int n;cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=n+1;i<=n+n+n;i++) a[i]=(a[i-n]);
	for (int i=1;i<=n+n+n;i++) dp[0][i]=a[i];
	for (int i=1;i<=L;i++){
		for (int j=1;j+(1<<i)-1<=n+n+n;j++){
			dp[i][j]=min(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
		}
	}
	c[n]=1;
	int maxx=a[n];
	for (int i=n+1;i<=n+n+n;i++){
		if (maxx>2*a[i]) break;
		c[n]++;
		maxx=max(maxx,a[i]); 
	}
	if (c[n]==n+n+1){
		for (int i=1;i<=n;i++) cout<<-1<<" ";
		return 0;
	}
	for (int i=n-1;i>=1;i--){
		int pos=i;
		for (int j=L;j>=0;j--){
			if (pos+(1<<j)>n+n+n) continue;
			if (dp[j][pos+1]*2>=a[i]) pos+=(1<<j);
		}
		int cur=pos-i+1;
		c[i]=min(c[i+1]+1,cur);
	}
	for (int i=1;i<=n;i++) cout<<c[i]<<" ";
	cout<<endl;
    return 0;
}