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
int a[1005][1005];
int q[1000005][2];
const int dir[6][2]={0,-2,-1,-1,-2,0,0,2,1,1,2,0};

int ask(int ax,int ay,int bx,int by){
	printf("? %d %d %d %d\n",ax,ay,bx,by);
	fflush(stdout);
	int ret=readint();
	assert(ret!=-1);
	return ret;
}

void getans(int sx,int sy){
	int front=0,rear=0;
	q[rear][0]=sx,q[rear][1]=sy; rear++;
	while(front<rear){
		int nx=q[front][0],ny=q[front][1]; front++;
		for(int i=0;i<6;i++){
			int dx=nx+dir[i][0],dy=ny+dir[i][1];
			if(dx<=0||dy<=0||dx>n||dy>n) continue;
			if(a[dx][dy]!=-1) continue;
			if(dx<=nx&&dy<=ny){
				int res=ask(dx,dy,nx,ny);
				if(res==1) a[dx][dy]=a[nx][ny];
				else a[dx][dy]=a[nx][ny]^1;
			}
			else{
				int res=ask(nx,ny,dx,dy);
				if(res==1) a[dx][dy]=a[nx][ny];
				else a[dx][dy]=a[nx][ny]^1;
			}
			q[rear][0]=dx,q[rear][1]=dy; rear++;
		}
	}
	printf("!\n");
	fflush(stdout);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) printf("%d",a[i][j]);
		printf("\n");
		fflush(stdout);
	}
}

void findans1(int sx,int sy){
	int tmp=ask(sx+1,sy,sx+2,sy+1);
	if(tmp==1){
		int res=ask(sx,sy,sx+2,sy+1);
		if(res==1) a[sx+2][sy+1]=a[sx+1][sy]=a[sx][sy];
		else a[sx+2][sy+1]=a[sx+1][sy]=a[sx][sy]^1;
		getans(sx+2,sy+1);
		return;
	}
	else{
		int res=ask(sx+1,sy,sx+2,sy+2);
		if(res==1) a[sx+1][sy]=a[sx][sy]^1,a[sx+2][sy+1]=a[sx][sy];
		else a[sx+1][sy]=a[sx][sy],a[sx+2][sy+1]=a[sx][sy]^1;
		getans(sx+2,sy+1);
		return;
	}
}

void findans2(int sx,int sy){
	int tmp=ask(sx,sy+1,sx+1,sy+2);
	if(tmp==1){
		int res=ask(sx,sy+1,sx+2,sy+2);
		if(res==1) a[sx][sy+1]=a[sx+1][sy+2]=a[sx+2][sy+2];
		else a[sx][sy+1]=a[sx+1][sy+2]=a[sx+2][sy+2]^1;
		getans(sx,sy+1);
		return;
	}
	else{
		int res=ask(sx,sy,sx+1,sy+2);
		if(res==1) a[sx][sy+1]=a[sx+2][sy+2],a[sx+1][sy+2]=a[sx+2][sy+2]^1;
		else a[sx][sy+1]=a[sx+2][sy+2]^1,a[sx+1][sy+2]=a[sx+2][sy+2];
		getans(sx,sy+1);
		return;
	}
}

int main(){
	n=readint();
	memset(a,-1,sizeof(a));
	a[1][1]=1,a[n][n]=0;
	bool hv1=false,hv0=false;
	for(int i=4;i<=n+n-2;i+=2){
		for(int j=max(i-n,1);j<=min(n,i-1);j++){
			if(j==1){
				if(ask(j,i-j-2,j,i-j)) a[j][i-j]=a[j][i-j-2];
				else a[j][i-j]=a[j][i-j-2]^1;
			}
			else if(i-j==1){
				if(ask(j-2,i-j,j,i-j)) a[j][i-j]=a[j-2][i-j];
				else a[j][i-j]=a[j-2][i-j]^1;
			}
			else{
				if(ask(j-1,i-j-1,j,i-j)) a[j][i-j]=a[j-1][i-j-1];
				else a[j][i-j]=a[j-1][i-j-1]^1;
			}
			if(a[j][i-j]==1) hv1=true;
			else hv0=true;
		}
	}
	if(hv0&&hv1){
		for(int i=1;i<=n-1;i++){
			for(int j=2;j<=n;j++){
				if((i+j)%2!=0) continue;
				if(a[i][j]==a[i+1][j-1]) continue;
				if(j>2){
					int res=ask(i,j-2,i+1,j);
					a[i+1][j]=(res^1)^a[i][j-2];
					getans(i+1,j);
					return 0;
				}
				else{
					int res=ask(i-1,j-1,i+1,j);
					a[i+1][j]=(res^1)^a[i-1][j-1];
					getans(i+1,j);
					return 0;
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			if(a[i][i]==a[i+1][i+1]&&a[i+1][i+1]!=a[i+2][i+2]){
				findans1(i,i);
				return 0;
			}
		}
		for(int i=n-2;i>=1;i--){
			if(a[i][i]!=a[i+1][i+1]&&a[i+1][i+1]==a[i+2][i+2]){
				findans2(i,i);
				return 0;
			}
		}
	}
	else if(hv1){
		findans1(n-2,n-2);
	}
	else{
		findans2(1,1);
	}
	return 0;
}