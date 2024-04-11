 #include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,s;
int a[255555],b[255555];
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
int tonga[255555],tongb[255555];
map<int,int>ma[200005];
signed main(){
	cin>>T;
	while(T--){
		n=read();m=read();s=read();
		
		for(int i=1;i<=s;i++)a[i]=read(),tonga[a[i]]++;
		for(int i=1;i<=s;i++)b[i]=read(),tongb[b[i]]++,ma[a[i]][b[i]]++;
		int ans=0;
		for(int i=1;i<=s;i++){
			ans+=s;
			ans-=tonga[a[i]];
			ans-=tongb[b[i]];
			ans+=ma[a[i]][b[i]];
		}
		ans/=2;
		printf("%lld\n",ans);
		for(int i=1;i<=s;i++)tongb[b[i]]--,tonga[a[i]]--,ma[a[i]][b[i]]--;
	}
	return 0;
}