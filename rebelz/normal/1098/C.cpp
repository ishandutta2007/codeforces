#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,s,cnt;
ll ans[300005];

int main(){
	n=readint(); s=readint();
	if(n*(n+1)/2<s||(n-1)*2+1>s) return printf("No\n"),0;
	printf("Yes\n");
	ll l=1,r=n,ret,mid,num,dep;
	while(l<=r){
		mid=(l+r)/2,cnt=num=dep=0;
		for(ll j=1,k=1;num<n;j*=mid,k++) cnt+=j*k,num+=j,dep=k;
		if(cnt-(num-n)*dep<=s) ret=mid,r=mid-1;
		else l=mid+1;
	}
//	cout<<ret<<endl;
	dep=cnt=num=0;
	for(ll j=1,k=1;num<n;j*=ret,k++) cnt+=j*k,num+=j,dep=k,ans[k]=j;
	cnt-=dep*(num-n),ans[dep]-=num-n;
//	cout<<s-cnt<<endl;
//	for(int i=1;i<=dep;i++) cout<<ans[i]<<' ';
//	cout<<endl;
	ll pl=dep,nres,maxdep=dep;
	while(cnt<s){
		while(ans[pl]==1) pl--;
		if(cnt+maxdep+1-pl<=s){
			ans[maxdep+1]++,ans[pl]--;
			cnt+=maxdep+1-pl;
			maxdep++;
		}
		else{
			ans[s-cnt+pl]++,ans[pl]--;
			cnt=s;
			break;
		}
	}
//	for(int i=1;i<=dep;i++) cout<<ans[i]<<' ';
//	cout<<endl;
	ll lst=1,pk=ret,ck=1,tmp;
	for(int i=2;i<=maxdep;i++){
		pk=ret;
		for(int j=1;j<=ans[i];j++){
			printf("%lld ",lst);
			pk--;
			if(pk==0) lst++,pk=ret;
			ck++;
			if(j==1) tmp=ck;
		}
		lst=tmp;
	}
	printf("\n");
	return 0;
}