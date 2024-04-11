#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n,k;
int s[N],f[N];
char c[N];
int read(){
	
}
int main(){
//	freopen("data.in","r",stdin);
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&k);
		scanf("%s",c+1);
		for(int i=1;i<=n;i++)s[i]=s[i-1]+(c[i]=='W');
		int minn=1e9;
		for(int i=k;i<=n;i++){
			minn=min(minn,s[i]-s[i-k]);
		}
		cout<<minn<<'\n';
	}
	return 0;
}