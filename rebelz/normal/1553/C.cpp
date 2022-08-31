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

char s[15];

int main(){
	int T=readint();
	while(T--){
		scanf("%s",s+1);
		int ans=10;
		for(int i=0;i<2;i++){
			int cnt[2]={0,0},rem[2]={5,5};
			for(int j=1;j<=10;j++){
				if((j&1)==(i&1)) cnt[j&1]+=s[j]!='0';
				else cnt[j&1]+=s[j]=='1';
				rem[j&1]--;
				if(cnt[!(i&1)]+rem[!(i&1)]<cnt[i&1]) chkmin(ans,j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}