#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e5+5,maxa=1e6+5;
int n,a[maxn];
int cnt1[maxa],cnt2[maxa];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=0;i<n;i++) a[i]=readint();
		int ans1=0;
		for(int i=0;i<n;i++){
			vector<int> f;
			for(int j=2;j*j<=a[i];j++){
				bool flag=0;
				while(a[i]%j==0){
					a[i]/=j;
					flag^=1;
				}
				if(flag) f.push_back(j);
			}
			for(int j:f) a[i]*=j;
			ans1=max(ans1,++cnt1[a[i]]);
		}
		int ans2=0;
		for(int i=0;i<n;i++)
			if(cnt1[a[i]]%2==1) ans2=max(ans2,++cnt2[a[i]]);
			else ans2=max(ans2,++cnt2[1]);
		for(int i=0;i<n;i++)
			if(cnt1[a[i]]%2==1) cnt2[a[i]]--;
			else cnt2[1]--;
		for(int i=0;i<n;i++) cnt1[a[i]]--;
		int q=readint();
		while(q--) printf("%d\n",readint()?ans2:ans1);
	}
	return 0;
}