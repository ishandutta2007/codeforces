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
char s[100005];
int d[100005][2][2];

int main(){
	int T=readint();
	while(T--){
		scanf("%s",s+1); n=strlen(s+1);
		for(int i=0;i<=n;i++) d[i][0][0]=d[i][0][1]=d[i][1][0]=d[i][1][1]=1<<30;
		d[0][0][0]=0;
		for(int i=1;i<=n;i++){
			if(i>2&&s[i]==s[i-1]&&s[i]==s[i-2]){
				d[i][0][1]=d[i-1][1][1];
				d[i][1][0]=d[i-1][0][1]+1;
				d[i][1][1]=min(d[i-1][1][0],d[i-1][1][1])+1;
			}
			else if(i>1&&s[i]==s[i-1]){
				d[i][0][1]=min(d[i-1][1][0],d[i-1][1][1]);
				d[i][1][0]=min(d[i-1][0][0],d[i-1][0][1])+1;
				d[i][1][1]=min(d[i-1][1][0],d[i-1][1][1])+1;
			}
			else if(i>2&&s[i]==s[i-2]){
				d[i][0][0]=d[i-1][0][1];
				d[i][0][1]=d[i-1][1][1];
				d[i][1][0]=min(d[i-1][0][0],d[i-1][0][1])+1;
				d[i][1][1]=min(d[i-1][1][0],d[i-1][1][1])+1;
			}
			else{
				d[i][0][0]=min(d[i-1][0][0],d[i-1][0][1]);
				d[i][0][1]=min(d[i-1][1][0],d[i-1][1][1]);
				d[i][1][0]=min(d[i-1][0][0],d[i-1][0][1])+1;
				d[i][1][1]=min(d[i-1][1][0],d[i-1][1][1])+1;
			}
		}
		printf("%d\n",min(min(d[n][0][0],d[n][0][1]),min(d[n][1][0],d[n][1][1])));
	}
	return 0;
}