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

int n,q;
int a[205],m[205];
char s[105],st[205][17],en[205][17];
vector<bool> t[205][17];

int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int tm=strlen(s+1);
		a[i]=-1;
		for(int j=1;j<=min(16,tm);j++){
			bool fl3=1;
			t[i][j].resize(1<<j);
			for(int k=1;k<=tm-j+1;k++){
				int tt=0;
				for(int l=k;l<=k+j-1;l++) tt+=(s[l]-'0')*(1<<(l-k));
				t[i][j][tt]=1;
			}
			for(int k=0;k<(1<<j);k++){
				if(!t[i][j][k]){
					fl3=0;
					break;
				}
			}
			if(!fl3&&a[i]<0) a[i]=j-1;
		}
		m[i]=min(16,tm);
		for(int j=1;j<=m[i];j++) st[i][j]=s[j];
		for(int j=1;j<=m[i];j++) en[i][j]=s[tm-m[i]+j];
	}
	q=readint();
	int cnt=n,x,y;
	for(int i=1;i<=q;i++){
		x=readint(); y=readint();
		cnt++;
		a[cnt]=max(a[x],a[y]);
		bool fl2=1;
		for(int j=a[cnt]+1;j<=min(16,m[x]+m[y]);j++){
			for(int tt=0;tt<(1<<j);tt++){
				int tx=t[x][j].size()?t[x][j][tt]:0,ty=t[y][j].size()?t[y][j][tt]:0;
				t[cnt][j].push_back(tx|ty);
			}
		}
		for(int j=1;j<=m[x];j++){
			for(int k=1;k<=m[y];k++){
				int len=m[x]-j+1+k,tt=0;
				if(len>16||len<=a[cnt]) continue;
				for(int l=j;l<=m[x];l++) tt+=(en[x][l]-'0')*(1<<(l-j));
				for(int l=1;l<=k;l++) tt+=(st[y][l]-'0')*(1<<(l+m[x]-j));
				t[cnt][len][tt]=1;
			}
		}
		m[cnt]=min(16,m[x]+m[y]);
		for(int j=1;j<=m[x];j++) st[cnt][j]=st[x][j];
		for(int j=m[x]+1;j<=m[cnt];j++) st[cnt][j]=st[y][j-m[x]];
		for(int j=m[cnt]-m[y]+1;j<=m[cnt];j++) en[cnt][j]=en[y][j-m[cnt]+m[y]];
		for(int j=1;j<=m[cnt]-m[y];j++) en[cnt][j]=en[x][j-m[cnt]+m[y]+m[x]];
		for(int j=a[cnt]+1;j<=16;j++){
			bool fl=1;
			for(int k=0;k<(1<<j);k++){
				if(!t[cnt][j][k]){
					fl=0;
					break;
				}
			}
			if(!fl) break;
			else a[cnt]=j;
		}
		printf("%d\n",a[cnt]);
	}
	return 0;
}