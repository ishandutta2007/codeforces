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

int n;
int a[2005],b[2005];
char s[2005],t[2005];
vector<int> v[30],ans;

void shift(int x){
	for(int i=n;i>=n-x+1;i--) b[n-i+1]=a[i];
	for(int i=1;i<=n-x;i++) b[i+x]=a[i];
	memcpy(a,b,sizeof(a));
}

int main(){
	n=readint();
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++) v[s[i]-'a'].push_back(i);
	for(int i=1;i<=n;i++){
		if(!v[t[i]-'a'].size()) return printf("-1\n"),0;
		a[v[t[i]-'a'].back()]=i,v[t[i]-'a'].pop_back();
	}
	int pl=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) if(a[j]==i) pl=j;
		ans.push_back(n-pl);
		shift(n-pl);
		ans.push_back(1);
		shift(1);
		ans.push_back(n);
		shift(n);
	}
	printf("%d\n",ans.size());
	for(auto x:ans) printf("%d ",x);
	printf("\n");
	return 0;
}