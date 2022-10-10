#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read() {
	int tot=0,fh=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') fh=-1;c=getchar();}
	while (c>='0'&&c<='9') {tot=tot*10+c-'0';c=getchar();}
	return tot*fh;
}
int n,cnt,a[20000],ha[20000],b[20000],c[20000],ans,f[200][20000];
int main() {
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) ha[a[i]]++;
	for (int i=1;i<=100;i++) if (ha[i]) {b[++cnt]=ha[i];c[cnt]=i;}
	if (cnt==1||cnt==2) cout<<n<<"\n";
	else {
		for (int i=1;i<=cnt;i++) {
			if (b[i]<=ans) continue;
			for (int j=1;j<=10000;j++) 
				for (int k=1;k<=100;k++)
					f[k][j]=0;
			f[0][0]=1;
			for (int j=1;j<=n;j++) if (a[j]!=c[i]) {
				for (int k=j-1;k>=0;k--)
					for (int p=10000-a[j];p>=0;p--)
						if (f[k][p]) f[k+1][p+a[j]]=1;
			}
			for (int j=b[i];j>ans&&j>=1;j--) {
				bool flag=true;
				for (int k=0;k<j;k++)
					if (f[j-k][j*c[i]-k*c[i]]==1) flag=false;
				if (flag) ans=j;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}