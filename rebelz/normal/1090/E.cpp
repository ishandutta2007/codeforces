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
	int x,y;
	bool operator<(const node c)const{
		if(y==c.y) return x<c.x;
		return y>c.y;
	}
}k[100];

const char ch[]=" abcdefgh";
const int dir[8][2]={1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1};
int n,tot,hyc,fk;
char tmp[100],x1[20000],x2[20000];
int x[100],y[100],ansx[100],ansy[100],mp[100][100],yy[20000],y2[20000];
int q[10005][10];
bool vis[100][100],v[100];

void print(int id){
	if(id==-1) return;
	print(q[id][3]);
	ansx[++tot]=q[id][0],ansy[tot]=q[id][1];
}

bool bfs(int sx,int sy,int ex,int ey){
	tot=0,q[0][0]=sx,q[0][1]=sy,q[0][2]=1,q[0][3]=-1;
	if(sx==ex&&sy==ey) return true;
	if(mp[ex][ey]==1) return false;
	memset(vis,false,sizeof(vis)); vis[sx][sy]=true;
	int front=0,rear=1;
	while(front<rear){
		int tx=q[front][0],ty=q[front][1],step=q[front][2]; front++;
//		cout<<"TEST "<<front-1<<' '<<tx<<' '<<ty<<' '<<q[front-1][3]<<endl;
		for(int i=0;i<8;i++){
			int dx=tx+dir[i][0],dy=ty+dir[i][1];
			if(dx==ex&&dy==ey){
				print(front-1);
				ansx[++tot]=dx,ansy[tot]=dy;
				return true;
			}
			if(dx<1||dx>8||dy<1||dy>8||vis[dx][dy]||mp[dx][dy]==1) continue;
			vis[dx][dy]=true;
			q[rear][0]=dx,q[rear][1]=dy,q[rear][2]=step+1,q[rear][3]=front-1;
			rear++;
		}
	}
	return false;
}

int main(){
	n=readint();
	if(n>32) for(int i=1;i<=8;i++) for(int j=1;j<=8;j++) mp[i][j]=1;
	for(int i=1;i<=n;i++) cin>>tmp[i]>>k[i].y;
	for(int i=1;i<=n;i++){
		k[i].x=tmp[i]-'a'+1;
		if(n<=32) mp[k[i].x][k[i].y]=1;
		else mp[9-k[i].x][9-k[i].y]=0;
	}
	fk=0;
	for(int i=1;i<=8;i++) for(int j=1;j<=8;j++) if(mp[i][j]) k[++fk].x=i,k[fk].y=j;
	sort(k+1,k+fk+1);
	int nowx=1,nowy=1,cnt=0;
	while(cnt<fk){
		for(int i=1;i<=fk;i++){
			if(!v[i]&&bfs(k[i].x,k[i].y,nowx,nowy)){
				v[i]=true;
//				cerr<<"TEST "<<k[i].x<<' '<<k[i].y<<' '<<nowx<<' '<<nowy<<endl;
//				for(int ii=1;ii<=8;ii++){
//					for(int jj=1;jj<=8;jj++) cerr<<mp[ii][jj];
//					cerr<<endl;
//				}
//				for(int j=1;j<=tot;j++) cout<<ansx[j]<<' '<<ansy[j]<<endl;
				for(int j=2;j<=tot;j++) x1[++hyc]=ch[ansx[j-1]],yy[hyc]=ansy[j-1],x2[hyc]=ch[ansx[j]],y2[hyc]=ansy[j];
				mp[k[i].x][k[i].y]=0,mp[nowx][nowy]=1;
				nowx++,cnt++;
				if(nowx==9) nowy++,nowx=1;
			}
		}
	}
	printf("%d\n",hyc);
	for(int i=1;i<=hyc;i++){
		if(n<=32) printf("%c%d-%c%d\n",x1[i],yy[i],x2[i],y2[i]);
		else printf("%c%d-%c%d\n",'h'-(x2[i]-'a'),9-y2[i],'h'-(x1[i]-'a'),9-yy[i]);
	}
	return 0;
}