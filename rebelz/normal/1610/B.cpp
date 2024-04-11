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
int a[200005];

bool check(int x){
	int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]) l++,r--;
		else if(a[l]==x) l++;
		else if(a[r]==x) r--;
		else return false;
	}
	return true;
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		int fl=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n-i+1]){
				if(check(a[i])) fl=1;
				else if(check(a[n-i+1])) fl=1;
				else fl=-1;
				break;
			}
			if(fl) break;
		}
		if(fl>=0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}