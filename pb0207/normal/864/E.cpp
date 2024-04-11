#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 1e5+1;
const int inf = 0x7fffffff;


ll n,m;
int tmp[2001];
int in[2001][101];
ll w[2001];
struct nd{
	int t,d,p,id;
}a[N];
bool cmp(nd a,nd b){
	return (a.d<b.d);
}


int id[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i].t>>a[i].d>>a[i].p,a[i].id=i;
	sort(a+1,a+n+1,cmp);
	w[0]=0;
	for(int i=1;i<=n;++i)
	for(int j=2000;j>=0;--j)
	if(j<a[i].d&&j>=a[i].t){
		if(w[j-a[i].t]+a[i].p>w[j]){
			w[j]=w[j-a[i].t]+a[i].p;
			for(int k=1;k<=tmp[j-a[i].t];++k)in[j][k]=in[j-a[i].t][k];
			tmp[j]=tmp[j-a[i].t];
			in[j][++tmp[j]]=i;
		}
	}
	ll ans=0,now=0,ret=0;
	for(int i=0;i<=2000;++i)if(w[i]>ans)ans=w[i],now=i;
	cout<<ans<<endl;
	cout<<tmp[now]<<endl;
	static int q[N];q[0]=0;
	for(int i=1;i<=tmp[now];++i)q[++q[0]]=a[in[now][i]].id;
	for(int i=1;i<=q[0];++i)cout<<q[i]<<" ";
}
/*
2
2 6 5
2 3 3
*/