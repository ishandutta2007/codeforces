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
char s[1005];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	int now0=0,now1=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			if(!now0) printf("3 1\n"),now0=1;
			else printf("1 1\n"),now0=0;
		}
		else{
			if(!now1) printf("1 3\n"),now1=1;
			else printf("1 1\n"),now1=0;
		}
	}
	return 0;
}