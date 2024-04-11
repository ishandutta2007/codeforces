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
int a[300005],now[600005],to[300005],nxt[300005],f[300005];
char s[300005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void solve(int l,int r){
	if(l>r) return;
	vector<int> vec(0);
	for(int i=l;i<=r;i=nxt[i]+1) vec.pb(i);
	vec.pb(r+1);
	int now=-1;
	for(int i=vec.size()-1;i>=1;i--){
		int L=vec[i-1]+1,R=vec[i]-2;
		solve(L,R);
		if(now<0) now=i;
		else{
			bool fl=0;
			for(int j=getf(vec[now-1]+1),k=getf(L);j<=vec[now]-2||k<=R;j=getf(j+1),k=getf(k+1)){
				char ch1=j<=vec[now]-2?s[j]:')',ch2=k<=R?s[k]:')';
				if(ch1!=ch2){
					if(ch1<ch2) fl=1;
					break;
				}
			}
			if(!fl) now=i;
		}
		if(now!=i){
			for(int j=L-1;j<=R+1;j=getf(j+1)) f[j]=j+1;
		}
	}
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) a[i]=a[i-1]+(s[i]=='('?1:-1);
	for(int i=0;i<=n+n;i++) now[i]=n+1;
	for(int i=1;i<=n+1;i++) to[i]=i;
	for(int i=n;i>=1;i--){
		if(s[i]=='(') nxt[i]=now[a[i-1]+n];
		else nxt[i]=n+1;
		now[a[i]+n]=i;
		if(nxt[i]<=n) to[i]=to[nxt[i]+1];
	}
	for(int i=1;i<=n+1;i++) f[i]=i;
	vector<char> ans;
	for(int i=1;i<=n;i++){
		if(s[i]==')'){
			ans.pb(')');
			continue;
		}
		int j=to[i]-1;
		if(j==n) break;
		if(i>j||s[j+1]=='('){
			for(int k=1;k<=a[n]-a[i-1];k++) ans.pb('(');
			break;
		}
		solve(i,j);
		for(int k=getf(i);k<=j;k=getf(k+1)) ans.pb(s[k]);
		i=j;
	}
	for(auto r:ans) putchar(r);
	putchar('\n');
	return 0;
}