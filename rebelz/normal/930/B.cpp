#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n; ld ans;
char s[5005];
int vis[5005];
vector<int> v[30];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=1;i<=n;i++) v[s[i]-'a'].push_back(i);
	for(int i=0;i<26;i++){
		if(!v[i].size()) continue;
		int now=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k<26;k++) vis[k]=0;
			for(auto x:v[i]) vis[s[(x+j-1)%n+1]-'a']++;
			int cnt=0;
			for(int k=0;k<26;k++) if(vis[k]==1) cnt++;
			chkmax(now,cnt);
		}
		ans+=now;
	}
	printf("%.10Lf\n",1.0*ans/n);
	return 0;
}