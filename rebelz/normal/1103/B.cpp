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

char s[10005];

int ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",s+1);
	return s[1]=='y';
}

void answer(int x){
	printf("! %d\n",x);
	fflush(stdout);
}

int main(){
	while(scanf("%s",s+1)){
		if(s[1]=='s'){
			if(!ask(0,1)){
				answer(1);
				continue;
			}
			int l=2,r=1e9;
			while(l<r){
				if(l+1==r){
					if(!ask(l,r)) l=r;
					break;
				}
				if(2*(l-1)<r){
					if(ask(l-1,2*(l-1))) l=((l-1)<<1)+1;
					else r=l-1+l-1;
				}
				else{
					int mid=(l+r+1)/4;
					if(ask(mid,2*mid)) l=(mid<<1)+1;
					else r=mid+mid;
				}
			}
			answer(l);
		}
		else if(s[1]=='e') break;
	}
	return 0;
}