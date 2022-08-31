#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int lst[300005],a[300005];

bool check(int x){
	for(int i=1;i<=n;i++){
		if(a[i]<lst[i-1]){
			if(a[i]+x<lst[i-1]) return false;
			lst[i]=lst[i-1];
		}
		else{
			if(a[i]+x-m>=lst[i-1]) lst[i]=lst[i-1];
			else lst[i]=a[i];
		}
	}
	return true;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int l=0,r=m,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}