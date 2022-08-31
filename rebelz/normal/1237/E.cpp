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

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int siz[1000005];

int main(){
	n=readint();
	if(n==1) printf("1\n");
	else if(n==2) printf("1\n");
	else if(n==3) printf("0\n");
	else if(n==4) printf("1\n");
	else{
		int cnt=0,tmp=n+1;
		while(tmp) tmp>>=1,cnt++;
		cnt--;
		for(int i=(1<<(cnt-1));i<(1<<cnt);i++){
			if(i&1) siz[i]=2;
			else siz[i]=1;
		}
		for(int i=(1<<(cnt-1))-1;i>=2;i--){
			if(i&1){
				if(siz[i<<1]%2==0) siz[i<<1]^=1;
			}
			siz[i]=siz[i<<1]+siz[i<<1|1]+1;
		}
		siz[1]=siz[2]+siz[3]+1;
		if(siz[1]==n||siz[1]+1==n) printf("1\n");
		else printf("0\n");
	}
	return 0;
}