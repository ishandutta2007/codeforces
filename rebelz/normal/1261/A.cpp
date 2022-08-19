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

int n,k;
char s[2005];
vector<pii> ans;

void rev(int l,int r){
	reverse(s+l,s+r+1);
	ans.push_back(mp(l,r));
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		scanf("%s",s+1);
		ans.clear();
		for(int i=1;i<=2*(k-1);i+=2){
			if(s[i]!='('){
				for(int j=i+1;j<=n;j++){
					if(s[j]=='('){
						rev(i,j);
						break;
					}
				}
			}
			if(s[i+1]!=')'){
				for(int j=i+2;j<=n;j++){
					if(s[j]==')'){
						rev(i+1,j);
						break;
					}
				}
			}
		}
		for(int i=2*(k-1)+1;i<=2*(k-1)+(n-2*k)/2+1;i++){
			if(s[i]!='('){
				for(int j=i+1;j<=n;j++){
					if(s[j]=='('){
						rev(i,j);
						break;
					}
				}
			}
		}
		printf("%d\n",ans.size());
		for(auto x:ans) printf("%d %d\n",x.fi,x.se);
	}
	return 0;
}