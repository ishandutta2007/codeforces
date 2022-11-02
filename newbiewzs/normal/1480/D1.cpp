#include<bits/stdc++.h>
#define cl fflush(stdout)
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s; 
}
const int N=1e5+55;
int n,top,qz,wz;
int tong[N],s[N],a[N],f[N],st[N],head,bj[N],zhan[N],tou,cd[N];
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){tong[top]++;continue;}
		f[++top]=a[i];
	}
	for(int i=1;i<=top;i++){
		if(f[i-1]!=f[i+1])bj[i]=1;
		s[i]=s[i-1]+bj[i];
	}
	int ans=top;
	for(int i=1;i<=top;i++){
		if(tong[i]){
			if(qz==f[i]){
				if(s[i-1]-s[wz]-cd[f[i]]){
					ans++;wz=i;
					while(tou){
						cd[zhan[tou]]--;
						tou--;
					}
				}
				else if(bj[i]){
					zhan[++tou]=f[i];
					cd[f[i]]++;
				}
			}
			else{
				ans++,wz=i,qz=f[i];
				while(tou){
					cd[zhan[tou]]--;
					tou--;
				}
			}
		}
		else if(bj[i]){
			zhan[++tou]=f[i];
			cd[f[i]]++;
		}
	}
	cout<<ans;
	return 0;
}