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
char s[100005],t[100005];
int a[20][20];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s%s",s+1,t+1);
		for(int i=0;i<20;i++) for(int j=0;j<20;j++) a[i][j]=0;
		bool fl=0;
		for(int i=1;i<=n;i++){
			if(s[i]>t[i]) fl=1;
			else a[s[i]-'a'][t[i]-'a']++;
		}
		if(fl){
			printf("-1\n");
			continue;
		}
		int cnt=0;
		for(int i=0;i<20;i++){
			for(int j=i+1;j<20;j++){
				if(a[i][j]){
					cnt++;
					for(int k=j+1;k<20;k++) a[j][k]+=a[i][k];
					break;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}