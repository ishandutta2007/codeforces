#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5,m=1e6+5,maxs=(1<<14)+5;
int sz[maxs];
bool np[m];
vector<int> p,w[m];
map<int,int> f[m];
int n,a[maxn],mn[m],mn2[m];
bool vis[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	for(int i=2;i<m;i++){
		if(!np[i]){
			p.push_back(i);
			w[i].push_back(i);
			f[i][i]=1;
			for(int j=2;i*j<m;j++){
				w[i*j].push_back(i);
				f[i*j][i]=f[j][i]+1;
			}
		}
		for(int j:p){
			if(i*j>=m) break;
			np[i*j]=1;
			if(i%j==0) break;
		}
	}
	for(int i=1;i<maxs;i++) sz[i]=sz[i>>1]+(i&1);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=2;i<m;i++) if(!np[i]) mn[i]=1;
	for(int i=2;i<=n;i++)
		for(int j:w[a[1]])
			if(f[a[i]][j]<f[a[mn[j]]][j]) mn[j]=i;
	vector<int> vec;
	for(int i:w[a[1]]) mn2[i]=f[a[1]][i];
	for(int i:w[a[1]])
		if(mn2[i]>f[a[mn[i]]][i]&&!vis[mn[i]]){
			vec.push_back(mn[i]);
			vis[mn[i]]=1;
			for(int j:w[a[1]])
				mn2[j]=min(mn2[j],f[a[mn[i]]][j]);
		}
	if(vec.size()<7){
		vec.push_back(1);
		vis[1]=1;
	}
	int x=1;
	while(x<=n&&vis[x]) x++;
	if(x<=n){
		for(int i=2;i<m;i++) if(!np[i]) mn[i]=x;
		for(int i=x+1;i<=n;i++) if(!vis[i])
			for(int j:w[a[x]])
				if(f[a[i]][j]<f[a[mn[j]]][j]) mn[j]=i;
		for(int i:w[a[x]]) mn2[i]=f[a[x]][i];
		int cnt=0;
		for(int i:w[a[x]])
			if(mn2[i]>f[a[mn[i]]][i]&&!vis[mn[i]]){
				vec.push_back(mn[i]);
				vis[mn[i]]=1;
				cnt++;
				for(int j:w[a[x]])
					mn2[j]=min(mn2[j],f[a[mn[i]]][j]);
			}
		if(cnt<7) vec.push_back(x);
	}
	sort(vec.begin(),vec.end());
	vector<vector<int>> ans0,ans1;
	for(int i=1;i<(1<<vec.size());i++){
		vector<int> vec2;
		for(int j=0;j<(int)vec.size();j++)
			if(i>>j&1) vec2.push_back(vec[j]);
		int c=(sz[i]-2)*(sz[i]%2==0?1:-1);
		for(int j=0;j<abs(c);j++)
			if(c>0) ans0.push_back(vec2);
			else ans1.push_back(vec2);
	}
	printf("%d\n",(int)(ans0.size()+ans1.size()));
	for(auto x:ans0){
		printf("0 %d ",(int)x.size());
		for(int i:x) printf("%d ",i);
		printf("\n");
	}
	for(auto x:ans1){
		printf("1 %d ",(int)x.size());
		for(int i:x) printf("%d ",i);
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}