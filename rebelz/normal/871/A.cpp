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

int main(){
	int T=readint(),x;
	while(T--){
		x=readint();
		if(x<=3) printf("-1\n");
		else if(x==5||x==7||x==11) printf("-1\n");
		else if(x%4==0) printf("%d\n",x/4);
		else if(x%4==1) printf("%d\n",x/4-1);
		else if(x%4==2) printf("%d\n",x/4);
		else if(x%4==3) printf("%d\n",x/4-1);
	}
	return 0;
}