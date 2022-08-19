#include<bits/stdc++.h>

using namespace std;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,ans;
int a[2005],d[2005][2],f[2005][2],t[2005][2],s[2005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		if(a[i]==2) d[i][0]=d[i-1][0],d[i][1]=max(d[i-1][0],d[i-1][1])+1;
		else d[i][1]=d[i-1][1],d[i][0]=d[i-1][0]+1;
	}
	for(int i=n;i>=1;i--){
		if(a[i]==1) f[i][1]=f[i+1][1],f[i][0]=max(f[i+1][0],f[i+1][1])+1;
		else f[i][0]=f[i+1][0],f[i][1]=f[i+1][1]+1;
	}
	for(int i=1;i<=n;i++) s[i]=s[i-1]+(a[i]==2);
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(d));
		for(int j=i;j<=n;j++){
			if(a[j]==1) t[j][1]=t[j-1][1],t[j][0]=max(t[j-1][0],t[j-1][1])+1;
			else t[j][0]=t[j-1][0],t[j][1]=t[j-1][1]+1;
			ans=max(ans,max(i-1-s[i-1]+t[j][0]+s[n]-s[j],j-s[j]+f[j+1][1]));
			ans=max(ans,d[i-1][1]+s[n]-s[i-1]);
//			cout<<"TEST "<<i<<' '<<j<<' '<<ans<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}