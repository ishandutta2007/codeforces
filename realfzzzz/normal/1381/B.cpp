#include<algorithm>
#include<vector>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
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
const int maxn=2e3+5;
int n,p[maxn*2];
vector<int> w;
bool dp[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t=readint();
	while(t--){
		n=readint();
		for(int i=0;i<n*2;i++) p[i]=readint();
		p[n*2]=n*2+1;
		w.clear();
		int res=0,lst=-1;
		for(int i=0;i<n*2;i++){
			res=max(res,p[i]);
			if(res<p[i+1]){
				w.push_back(i-lst);
				lst=i;
			}
		}
		if(lst<n*2-1) w.push_back(n*2-lst);
		dp[0]=1;
		for(int i=1;i<=n;i++) dp[i]=0;
		for(int i=0;i<(int)w.size();i++) for(int j=n;j>=0;j--)
			if(j>=w[i]) dp[j]|=dp[j-w[i]];
		printf(dp[n]?"YES\n":"NO\n");
	}
	return 0;
}