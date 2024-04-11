#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k,cnt,ncnt; ll ans;
int tmp[6],nxt[125][125],now[125],A[6],plc[125][6],p[100005],a[200005],q[125],chg[125];
pii pl[125];
bool vis[125];

ll gethsh(int A[]){
	ll hsh=0;
	for(int i=1;i<=k;i++) hsh=hsh*6+A[i];
	return hsh;
}

void init(){
	for(int i=1;i<=k;i++) A[i]=i;
	do{
		cnt++;
		for(int i=1;i<=k;i++) plc[cnt][i]=A[i];
		p[gethsh(A)]=cnt;
	}while(next_permutation(A+1,A+k+1));
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			for(int l=1;l<=k;l++) tmp[l]=plc[i][plc[j][l]];
			nxt[i][j]=p[gethsh(tmp)];
		}
	}
}

int main(){
	n=readint(); k=readint();
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++) tmp[j]=readint();
		a[i]=p[gethsh(tmp)];
	}
	for(int i=1;i<=n;i++){
		now[a[i]]=i;
		for(int j=1;j<=cnt;j++) pl[j]=mp(now[j],j);
		sort(pl+1,pl+cnt+1);
		memset(vis,0,sizeof(vis));
		int front=0,rear=0,lst=i;
		q[rear++]=1; vis[1]=true; ncnt=0;
		for(int j=cnt;j>=1;j--){
			ans+=(lst-pl[j].fi)*rear;
			lst=pl[j].fi;
			if(pl[j].fi==0) break;
			if(vis[pl[j].se]) continue;
			chg[++ncnt]=pl[j].se;
			front=0;
			while(front<rear){
				int t=q[front++];
				for(int l=1;l<=ncnt;l++){
					if(!vis[nxt[t][chg[l]]]){
						vis[nxt[t][chg[l]]]=true;
						q[rear++]=nxt[t][chg[l]];
					}
				}
			}
		}
		if(lst!=0) ans+=lst*rear;
	}
	cout<<ans<<endl;
	return 0;
}