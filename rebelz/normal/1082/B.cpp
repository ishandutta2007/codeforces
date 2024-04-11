#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
char s[100005];
int cnt[100005],lst[100005],nxt[100005];

int main(){
	scanf("%d",&n); cin>>s+1;
	for(int i=1;i<=n;i++)
		cnt[i]=cnt[i-1]+(s[i]=='S');
	int now=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='S'){
			lst[i]=now;
			now=i;
		}
	now=n+1;
	for(int i=n;i>=1;i--)
		if(s[i]=='S'){
			nxt[i]=now;
			now=i;
		}
	int x,ans=0;
	if(cnt[n]==0){
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		x=nxt[i]-lst[i]-2;
		if(n-cnt[n]==x)
			x--;
		ans=max(ans,x+1);
	}
	cout<<ans<<endl;
	return 0;
}