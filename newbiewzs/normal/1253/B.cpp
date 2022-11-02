#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<math.h>
//#include<unordered_map>
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
#define da(x) cout<<"sese:"<<x<<endl;
#define db(x,y) cout<<"???"<<x<<" "<<y<<endl;
#define dc(x,y,z) cout<<"!!!!:"<<x<<" "<<y<<" "<<z<<endl;
#define dd(x,y,z,w) cout<<"yiw:"<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
	char c=getchar();
	ll x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=1e6+55;
int n,a[N],st[N],top,tong[N],cs[N],zs,pre;
int main(){
//	freopen("data.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	bool flag=0;
	for(int i=1;i<=n;i++){
		if(a[i]<0){
			if(!tong[-a[i]]){
				cout<<"-1";return 0;
			}
			tong[-a[i]]--;zs--;
		}
		else{
			if(cs[a[i]]){
				cout<<"-1";return 0;
			}
			cs[a[i]]=1;
			if(tong[a[i]]){
				cout<<"-1";return 0;
			}
			tong[a[i]]++;zs++;
		}
		if(!zs){
			for(int k=pre+1;k<=i;k++)if(a[k]>0)cs[a[k]]=0;
			st[++top]=i-pre;
			pre=i;
		}
	}
	if(pre!=n){
		cout<<"-1";return 0;
	}
	cout<<top<<endl;
	for(int i=1;i<=top;i++){
		printf("%d ",st[i]);
	}
	return 0;
}