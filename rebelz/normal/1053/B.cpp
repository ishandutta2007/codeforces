#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,maxa,num,ans;
ll a[300005],b[300005],k[5],s[300005],cnt[300005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) b[i]=a[i]=readint();
	for(int i=1;i<=n;i++)
		for(;b[i];b[i]&=(b[i]-1),cnt[i]++);
	for(int i=1;i<=n;i++) s[i]=(s[i-1]+cnt[i])&1;
	k[0]=1;
	for(int i=1;i<=n;i++){
		ans+=k[s[i]];
		k[s[i]]++;
	}
//	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		maxa=num=cnt[i]; if(cnt[i]%2==0) ans--;
		for(int j=i-1;j>=1;j--){
			num+=cnt[j],maxa=max(maxa,cnt[j]);
			if(num%2==0&&maxa>num/2) ans--;
			if(num>=125) break;
		}
	}
	cout<<ans<<endl;
	return 0;
}