#include<bits/stdc++.h>

#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cnt,N=100000;
bool ok=false;
char s[100005];
int a[100005],b[100005],d[100005];
pii ans[100005];

void move(int x,int d){
	ans[++cnt]=mp(x,d);
	a[x]+=d,a[x+1]+=d;
	if(cnt==N) ok=true;
}

int main(){
	n=readint();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) a[i]=s[i]-'0';
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) b[i]=s[i]-'0';
	for(int i=1;i<=n;i++) d[i]=b[i]-a[i]-d[i-1];
	if(d[n]) return printf("-1\n"),0;
	int pl,lst;
	for(int i=1;i<=n-1;i++){
		if(a[i]>b[i]){
			int hh=a[i]-b[i];
			for(int num=1;num<=hh;num++){
				pl=i,lst=0;
				while(pl<n&&a[pl+1]==lst) lst=9-lst,pl++;
				if(pl==n) return printf("-1\n"),0;
				for(int j=pl;j>=i;j--){
					move(j,a[j]==0?1:-1);
					if(ok) break;
				}
				if(ok) break;
			}
		}
		else{
			int hh=b[i]-a[i];
			for(int num=1;num<=hh;num++){
				pl=i,lst=9;
				while(pl<n&&a[pl+1]==lst) lst=9-lst,pl++;
				if(pl==n) return printf("-1\n"),0;
				for(int j=pl;j>=i;j--){
					move(j,a[j]==9?-1:1);
					if(ok) break;
				}
				if(ok) break;
			}
		}
		if(ok) break;
	}
	ll sum=0;
	for(int i=1;i<=n;i++) sum+=abs(d[i]);
	printf("%lld\n",sum);
	for(int i=1;i<=cnt;i++) printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}