#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,mn1=1<<30,mn2=1<<30,mx1,mx2,mn1x,mn2x,mx1x,mx2x,ans;
int mina[300005],maxa[300005],a[300005];

int main(){
	n=readint();
	memset(mina,0x3f,sizeof(mina));
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) mina[a[i]]=min(mina[a[i]],i),maxa[a[i]]=max(maxa[a[i]],i);
	for(int i=1;i<=n;i++){
		if(mina[i]<mn1) mn2=mn1,mn2x=mn1x,mn1=mina[i],mn1x=i;
		else if(mina[i]<mn2) mn2=mina[i],mn2x=i;
		if(maxa[i]>mx1) mx2=mx1,mx2x=mx1x,mx1=maxa[i],mx1x=i;
		else if(maxa[i]>mx2) mx2=maxa[i],mx2x=i;
	}
	if(mn1x&&mx1x&&mn1x!=mx1x) ans=max(ans,mx1-mn1);
	if(mn1x&&mx2x&&mn1x!=mx2x) ans=max(ans,mx2-mn1);
	if(mn2x&&mx1x&&mn2x!=mx1x) ans=max(ans,mx1-mn2);
	if(mn2x&&mx2x&&mn2x!=mx2x) ans=max(ans,mx2-mn2);
	cout<<ans<<endl;
	return 0;
}