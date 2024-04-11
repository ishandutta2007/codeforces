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
const int maxn=2e5+5;
int n;
bool a[maxn];
vector<int> ans;
void solve(int l,int r){
	for(int i=l;i<r;i+=2) ans.push_back(i);
	for(int i=r-4;i>=l;i-=2) ans.push_back(i);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		bool s=0;
		for(int i=1;i<=n;i++) s^=a[i];
		if(s){
			printf("NO\n");
			continue;
		}
		vector<int>().swap(ans);
		if(n%2==1) solve(1,n);
		else{
			bool flag=s=0;
			for(int i=1;i<=n;i++){
				s^=a[i];
				if(i%2==1&&!s){
					solve(1,i);
					solve(i+1,n);
					flag=1;
					break;
				}
			}
			if(!flag){
				printf("NO\n");
				continue;
			}
		}
		printf("YES\n%d\n",(int)ans.size());
		for(int i:ans) printf("%d ",i);
		printf("\n");
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}