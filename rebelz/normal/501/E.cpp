#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[200005],chk[200005],cnt[200005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),cnt[a[i]]^=1;
	int num=0,fl=0,st;
	for(int i=1;i<=n;i++) if(cnt[i]==1) num++;
	if(num>1) return printf("0\n"),0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n-i+1]){
			fl=1,st=i;
			break;
		}
	}
	if(!fl) return printf("%lld\n",1ll*n*(n+1)/2),0;
	if(n%2==0&&num==1) return printf("0\n"),0;
	int mx=n/2+1,nowans=0,pre=-1,suf=-1;
	for(int i=(n+1)/2;i>=1;i--){
		if(a[i]==a[n-i+1]) mx=i;
		else break;
	}
	for(int i=st;i<=n/2;i++){
		chk[a[i]]++;
		if(chk[a[i]]==1) nowans++;
		else if(chk[a[i]]==0) nowans--;
		chk[a[n-i+1]]--;
		if(chk[a[n-i+1]]==-1) nowans++;
		else if(chk[a[n-i+1]]==0) nowans--;
		if(i<mx-1) continue;
		if(!nowans){
			pre=n-st+1-i+1;
			break;
		}
	}
	if(pre<0){
		nowans=0;
		for(int i=1;i<=n;i++) if(chk[i]<0) nowans++;
		for(int i=n/2+1;i<=n-st+1;i++){
			chk[a[i]]++;
			if(chk[a[i]]==0) nowans--;
			if(n%2!=1||i!=n/2+1){
				chk[a[i]]++;
				if(chk[a[i]]==0) nowans--;
			}
			if(!nowans){
				pre=n-st+1-i+1;
				break;
			}
		}
	}
	assert(pre>0);
	memset(chk,0,sizeof(chk)); nowans=0;
	for(int i=n-st+1;i>=n-n/2+1;i--){
		chk[a[i]]++;
		if(chk[a[i]]==1) nowans++;
		else if(chk[a[i]]==0) nowans--;
		chk[a[n-i+1]]--;
		if(chk[a[n-i+1]]==-1) nowans++;
		else if(chk[a[n-i+1]]==0) nowans--;
		if(n-i+1<mx-1) continue;
		if(!nowans){
			suf=i-st+1;
			break;
		}
	}
	if(suf<0){
		nowans=0;
		for(int i=1;i<=n;i++) if(chk[i]<0) nowans++;
		for(int i=n-n/2;i>=st;i--){
			chk[a[i]]++;
			if(chk[a[i]]==0) nowans--;
			if(n%2!=1||i!=n/2+1){
				chk[a[i]]++;
				if(chk[a[i]]==0) nowans--;
			}
			if(!nowans){
				suf=i-st+1;
				break;
			}
		}
	}
	assert(suf>0);
	cout<<1ll*st*(pre+suf)-1+1ll*(st-1)*(st-1)<<endl;
	return 0;
}