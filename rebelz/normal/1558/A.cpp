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

int a,b;
bool ans[200005];

int main(){
	int T=readint();
	while(T--){
		a=readint(); b=readint();
		for(int i=0;i<=a+b;i++) ans[i]=0;
		for(int i=0;i<=min(a,(a+b+1)/2);i++){
			int t=(a+b)/2-(a-i);
			if(t>=0) ans[i+t]=1;
			if((a+b)%2==0||i!=(a+b+1)/2){
				t=(a+b+1)/2-(a-i);
				if(t>=0) ans[i+t]=1;
			}
		}
		vector<int> res(0);
		for(int i=0;i<=a+b;i++) if(ans[i]) res.pb(i);
		printf("%d\n",res.size());
		for(auto r:res) printf("%d ",r);
		printf("\n");
	}
	return 0;
}