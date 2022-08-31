#include<bits/stdc++.h>

#define pii pair<ld,ld>
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const double eps=1e-9;
int n,cnt,tot;
int x[5],y[5],r[5],gs[10];
bool vis[1005];
pii jd[1005];
int sz[3][3][3][3];

ld dist(int i,int j){
	return sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
}

bool bujiao(int i,int j){
	return r[i]+r[j]<dist(i,j)||fabs(r[i]-r[j])>dist(i,j);
}

void getjd(int i,int j){
	if(x[i]>x[j]) swap(i,j);
	if(r[i]+r[j]<dist(i,j)||fabs(r[i]-r[j])>dist(i,j)) return (void)(gs[++tot]=0);
	if(fabs(r[i]+r[j]-dist(i,j))<eps){
		gs[++tot]=1;
		ld alpha=atan2(y[j]-y[i],x[j]-x[i]);
		jd[++cnt]=mp(x[i]+r[i]*cos(alpha),y[i]+r[i]*sin(alpha));
		return;
	}
	else if(fabs(fabs(r[i]-r[j])-dist(i,j))<eps){
		gs[++tot]=1;
		if(r[i]<r[j]) swap(i,j);
		ld dis=dist(i,j);
		jd[++cnt]=mp(x[j]+(x[j]-x[i])/dis*r[j],y[j]+(y[j]-y[i])/dis*r[j]);
		return;
	}
	gs[++tot]=2;
	ld dis=dist(i,j);
	ld alpha=atan2(y[j]-y[i],x[j]-x[i]);
	ld beta=acos((r[i]*r[i]+dis*dis-r[j]*r[j])/(2*r[i]*dis));
	jd[++cnt]=mp(x[i]+r[i]*cos(alpha+beta),y[i]+r[i]*sin(alpha+beta));
	jd[++cnt]=mp(x[i]+r[i]*cos(alpha-beta),y[i]+r[i]*sin(alpha-beta));
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) x[i]=readint(),y[i]=readint(),r[i]=readint();
	if(n==1){
		cout<<2<<endl;
		return 0;
	}
	else if(n==2){
		if(r[1]+r[2]>dist(1,2)) cout<<4<<endl;
		else cout<<3<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			getjd(i,j);
		}
	}
	if(cnt==0){
		cout<<4<<endl;
		return 0;
	}
//	cout<<cnt<<endl;
//	for(int i=1;i<=cnt;i++){
//		cout<<jd[i].fi<<' '<<jd[i].se<<endl;
//	}
	int fl=0;
	for(int i=1;i<=cnt;i++){
		bool jkp=false;
		if(vis[i]) continue;
		for(int j=1;j<=cnt;j++){
			if(j!=i&&!vis[j]){
				if(fabs(jd[i].fi-jd[j].fi)<eps&&fabs(jd[i].se-jd[j].se)<eps){
					jkp=true;
					vis[j]=true;
				}
			}
		}
		if(jkp) fl++;
	}
	sort(gs+1,gs+4);
//	cout<<"TEST "<<gs[1]<<' '<<gs[2]<<' '<<gs[3]<<' '<<fl<<endl;
	sz[0][0][0][0]=4;
	sz[0][0][1][0]=4;
	sz[0][0][2][0]=5;
	sz[0][1][1][0]=4;
	sz[0][1][2][0]=5;
	sz[0][2][2][0]=6;
	sz[1][1][1][0]=5;
	sz[1][1][1][1]=4;
	sz[1][1][2][0]=6;
	sz[1][2][2][0]=7;
	sz[1][2][2][1]=6;
	sz[2][2][2][0]=8;
	sz[2][2][2][1]=7;
	sz[2][2][2][2]=6;
	if(sz[gs[1]][gs[2]][gs[3]][fl]==0) return 1;
	cout<<sz[gs[1]][gs[2]][gs[3]][fl]<<endl;
	return 0;
}