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
const int N=4e5+55;
char a[N],b[N];
int n;
struct Tire{
	int ch[N][26],fail[N],val[N],tot;
	void insert(char a[],int len){
		int u=0;
		for(int i=1;i<=len;i++){
			if(!ch[u][a[i]-'a']){
				tot++;
				ch[u][a[i]-'a']=tot;
			}
			u=ch[u][a[i]-'a'];
		}
		val[u]++;
	}
	void getfail(){
		queue<int>q;
		for(int i=0;i<26;i++)if(ch[0][i])q.push(ch[0][i]);
		while(q.size()){
			int u=q.front();
			q.pop();
			val[u]+=val[fail[u]];
			for(int i=0;i<26;i++){
				if(ch[u][i]){
					fail[ch[u][i]]=ch[fail[u]][i];
					q.push(ch[u][i]);
				}
				else ch[u][i]=ch[fail[u]][i];
			}
		}
	}
}t1,t2;
int f[N];
signed main(){
	scanf("%s",a+1);
	int l=strlen(a+1);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",b+1);
		t1.insert(b,strlen(b+1));
		reverse(b+1,b+strlen(b+1)+1);
		t2.insert(b,strlen(b+1));
	}
	t1.getfail();
	t2.getfail();
	int u=0;
	for(int k=1;k<=l;k++){
		u=t1.ch[u][a[k]-'a'];
		f[k]=t1.val[u];
	}
	u=0;
	long long ans=0;
	for(int k=l;k>=1;k--){
		u=t2.ch[u][a[k]-'a'];
		ans+=1ll*f[k-1]*t2.val[u];
	}
	cout<<ans;
	return 0;
}