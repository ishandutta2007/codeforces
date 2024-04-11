#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

char s[100005];
bool vis[30];

int main(){
	int n=readint(),res=0,ans=-1;
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch!='.'&&ch!='!'&&ch!='?') ch=getchar();
		if(ch=='.'){
			scanf("%s",s+1);
			int l=strlen(s+1);
			for(int i=1;i<=l;i++) vis[s[i]-'a']=1;
		}
		else if(ch=='!'){
			scanf("%s",s+1);
			int l=strlen(s+1);
			int cnt[26]={0};
			for(int i=1;i<=l;i++) cnt[s[i]-'a']=1;
			for(int i=0;i<26;i++) if(!cnt[i]) vis[i]=1;
			if(ans>=0) res++;
		}
		else{
			scanf("%s",s+1);
			if(ans>=0&&s[1]-'a'!=ans) res++;
			if(ans<0) vis[s[1]-'a']=1;
		}
		int cnt=0,knd=-1;
		for(int i=0;i<26;i++) if(!vis[i]) cnt++,knd=i;
		if(cnt==1) ans=knd;
	}
	printf("%d\n",res);
	return 0;
}