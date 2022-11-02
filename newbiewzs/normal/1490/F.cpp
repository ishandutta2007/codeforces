#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=2e5+55;
int T,n;
int a[N];
int tong[N],s[N];
signed main(){
	T=read();
	while(T--){
		n=read();
		map<int,int>ma,pd;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++){
			ma[a[i]]++;
		}
		int minn=1e9;
		for(int i=1;i<=n;i++){
			if(pd[a[i]])continue;
			tong[ma[a[i]]]+=ma[a[i]];
			pd[a[i]]=1;
		}
		for(int i=1;i<=n;i++)s[i]=s[i-1]+tong[i];
		int qz=0;int gs=0;
		for(int i=n;i>=1;i--){
			minn=min(minn,gs+s[i-1]);
			qz+=tong[i]/i;
			gs+=qz;
		}
		if(gs!=n){
			cout<<"???";
		}
		minn=min(minn,n);
		for(int i=1;i<=n;i++){s[i]=0;
			if(!pd[a[i]])continue;
			tong[ma[a[i]]]-=ma[a[i]];
			pd[a[i]]=0;
		}
		cout<<minn<<endl;
		ma.clear();
	}
	return 0;
}