// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
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

int n;
char s[100005],t[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s%s",s+1,t+1);
		int cnt0[2]={0,0},cnt1[2]={0,0};
		for(int i=1;i<=n;i++){
			if(s[i]!=t[i]) cnt0[s[i]-'0']++;
			else cnt1[s[i]-'0']++;
		}
		int ans=n+1;
		if(cnt0[0]==cnt0[1]) chkmin(ans,cnt0[0]*2);
		if(cnt1[1]==cnt1[0]+1) chkmin(ans,cnt1[0]*2+1);
		if(ans>n) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}