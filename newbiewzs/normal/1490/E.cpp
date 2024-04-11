#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=2e5+55;
int T,n;
int s[N],da[N];
struct node{
	int val,id;
}a[N];
int cmp(node x,node y){
	return x.val<y.val;
}
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i].val=read(),a[i].id=i;
		sort(a+1,a+n+1,cmp);
		int head=1;int qz=0;
		for(int i=1;i<=n;i++)s[i]=a[i].val+s[i-1];
		int ans=1;
		for(int i=n-1;i>=1;i--){
			if(s[i]<a[i+1].val)break;
			ans++;
		}
		cout<<ans<<endl;
		int top=0;
		for(int i=n-ans+1;i<=n;i++){
			da[++top]=a[i].id;
		}
		sort(da+1,da+top+1);
		for(int i=1;i<=top;i++)printf("%d ",da[i]);
		puts("");
	}
	return 0;
}