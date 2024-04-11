#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
#define int long long
using namespace std;
typedef long long ll;
const int N=2e7+5;
int T,c,d,x;
int vis[N],st[N],f[N],top;
void init(){
	for(int i=2;i<N;i++){
		if(!vis[i])st[++top]=i,f[i]=2;
		for(int k=1;k<=top and i*st[k]<N;k++){
			vis[i*st[k]]=1;
			if(i%st[k]!=0)f[i*st[k]]=f[i]*f[st[k]];
			else f[i*st[k]]=f[i];
			if(i%st[k]==0)break;
		}
	}
}
int calc(int u){
	if((u+d)%c!=0)return 0;
	int g=(u+d)/c;
	return f[g];
}
signed main(){
	init();
	f[1]=1;
	cin>>T;
	while(T--){
		cin>>c>>d>>x;
		int ans=0;
		for(int i=1;i*i<=x;i++){
			if(x%i==0){
				ans+=calc(i);
				if(i*i!=x)ans+=calc(x/i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}