#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
typedef long long ll;
const int Maxn=100000;
const int Maxm=1000000;
int f[Maxm+5];
void add(int x,int a){
	for(int i=x;i<=Maxm;i+=(i&(-i))){
		f[i]+=a;
	}
}
int query(int x){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f[i];
	}
	return ans;
}
int x[Maxn+5],l_x[Maxn+5],r_x[Maxn+5];
int y[Maxn+5],l_y[Maxn+5],r_y[Maxn+5];
vector<pair<int,int> > a[Maxm+5];
vector<pair<int,int> > q[Maxm+5];
int main(){
	int n,m;
	read(n),read(m);
	ll ans=1;
	for(int i=1;i<=n;i++){
		read(x[i]),read(l_x[i]),read(r_x[i]);
		if(l_x[i]==0&&r_x[i]==Maxm){
			ans++;
		}
		a[l_x[i]].push_back(make_pair(x[i],1));
		a[r_x[i]+1].push_back(make_pair(x[i],-1));
	}
	for(int i=1;i<=m;i++){
		read(y[i]),read(l_y[i]),read(r_y[i]);
		if(l_y[i]==0&&r_y[i]==Maxm){
			ans++;
		}
		q[y[i]].push_back(make_pair(l_y[i],r_y[i]));
	}
	for(int i=0;i<=Maxm;i++){
		for(int j=0;j<(int)a[i].size();j++){
			add(a[i][j].first,a[i][j].second);
		}
		for(int j=0;j<(int)q[i].size();j++){
			if(q[i][j].first==0){
				ans+=query(q[i][j].second);
			}
			else{
				ans+=query(Maxm)-query(q[i][j].first-1);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}