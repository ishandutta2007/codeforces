#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int id,x,y;
	bool operator<(const node c)const{
		if(x==c.x) return y<c.y;
		return x<c.x;
	}
}a[2005];

int n;
int ans[2005];
char s[2005];
bool vis[2005];

bool rgt(int k,int x,int y){
	return 1ll*(a[x].x-a[k].x)*(a[y].y-a[k].y)-1ll*(a[x].y-a[k].y)*(a[y].x-a[k].x)<0;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].x=readint(),a[i].y=readint(),a[i].id=i;
	scanf("%s",s+2);
	sort(a+1,a+n+1);
	ans[1]=a[1].id; vis[1]=true;
	int now=1,xx;
	for(int i=2;i<=n-1;i++){
		xx=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&!xx) xx=j;
			else if(!vis[j]&&(rgt(now,j,xx)^s[i]=='L')) xx=j;
		}
		ans[i]=a[xx].id,now=xx,vis[xx]=true;
	}
	for(int i=1;i<=n;i++) if(!vis[i]) ans[n]=a[i].id;
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}