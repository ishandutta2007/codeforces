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
const int maxn=1e3+5;
int n;
bool np[maxn];
vector<int> p;
int mx[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=2;i<=n;i++){
		if(!np[i]) p.push_back(i);
		for(int j:p){
			if(i*j>n) break;
			np[i*j]=1;
			if(i%j==0) break;
		}
	}
	for(int i=1;i<=n;i++){
		int x=i;
		for(int j:p){
			int cnt=0;
			while(x%j==0){
				x/=j;
				cnt++;
			}
			mx[j]=max(mx[j],cnt);
		}
	}
	vector<int> ans;
	for(int i=1;i<=n;i++){
		int x=1;
		for(int j=0;j<mx[i];j++) ans.push_back(x*=i);
	}
	printf("%d\n",(int)ans.size());
	for(int i:ans) printf("%d ",i);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}