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

int n,m,k;
ll pl[505][505],val[505][505],d[505][505][2],aval[505][505],nval[505][505],cnt[500005];
vector<pii> bef[500005];
vector<pii> v[505][505];

bool inmat(int x,int y){return x>=0&&x<n&&y>=0&&y<m;}

int main(){
	n=readint(); m=readint(); k=readint();
	int x,y,z,t,e;
	for(int i=1;i<=k;i++){
		x=readint(); y=readint(); z=readint(); t=readint(); e=readint();
		int x1=x,y1=y,x2=x+z,y2=y-z,x3=x+z,y3=y,x4=x,y4=y+z,t1=0,t2=0,t3=0,t4=0;
		if(inmat(x1,y1)&&(x1+y1)%4==t%4&&x1+y1>=t) v[x1][y1].push_back(mp(e,i));
		if(inmat(x2,y2)&&(x2+y2)%4==(t+1)%4&&x2+y2>=t+1) v[x2][y2].push_back(mp(e,i));
		if(inmat(x3,y3)&&(x3+y3)%4==(t+2)%4&&x3+y3>=t+2) v[x3][y3].push_back(mp(e,i));
		if(inmat(x4,y4)&&(x4+y4)%4==(t+3)%4&&x4+y4>=t+3) v[x4][y4].push_back(mp(e,i));
		cnt[i]=-1;
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			cout<<"test "<<i<<' '<<j<<endl;
//			for(auto r:v[i][j]) cout<<r.fi<<' '<<r.se<<endl;
//		}
//	}
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) for(auto r:v[i][j]) pl[i][j]+=r.fi;
	memset(d,0x3f,sizeof(d));
	d[0][0][0]=d[0][0][1]=pl[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(auto r:v[i][j]){
				if(bef[r.se].size()>=0){
					int pos=-1;
					for(auto tr:bef[r.se]){
						if(tr.se==j){
							pos=tr.fi;
							break;
						}
					}
					if(pos>=0) for(int k=pos+1;k<=i;k++) aval[j][k]+=r.fi;
					else for(int k=i;k>=0;k--) aval[j][k]+=r.fi;
				}
				else{
					for(int k=i;k>=0;k--) aval[j][k]+=r.fi;
				}
				bef[r.se].push_back(mp(i,j));
			}
		}
		for(int j=0;j<m;j++) for(int k=0;k<i;k++) chkmin(d[i][j][0],d[k][j][1]+aval[j][k]-pl[k][j]);
		memset(val,0,sizeof(val));
		memset(nval,0,sizeof(nval));
		for(int j=0;j<m;j++){
			for(auto r:v[i][j]){
				if(cnt[r.se]>=0){
					val[0][cnt[r.se]]-=r.fi,val[0][m]+=r.fi,val[cnt[r.se]+1][cnt[r.se]]+=r.fi,val[cnt[r.se]+1][m]-=r.fi;
					val[0][j]+=r.fi,val[0][m]-=r.fi,val[cnt[r.se]+1][j]-=r.fi,val[cnt[r.se]+1][m]+=r.fi;
					val[0][cnt[r.se]]+=r.fi,val[0][j]-=r.fi,val[cnt[r.se]+1][cnt[r.se]]-=r.fi,val[cnt[r.se]+1][j]+=r.fi;
					val[cnt[r.se]+1][j]+=r.fi,val[cnt[r.se]+1][m]-=r.fi,val[j+1][j]-=r.fi,val[j+1][m]+=r.fi;
				}
				else{
					val[0][j]+=r.fi,val[0][m]-=r.fi,val[j+1][j]-=r.fi,val[j+1][m]+=r.fi;
					cnt[r.se]=j;
				}
			}
		}
		for(int j=0;j<m;j++) for(auto r:v[i][j]) cnt[r.se]=-1;
		for(int j=0;j<m;j++) for(int k=0;k<m;k++) val[j][k]+=(k?val[j][k-1]:0)+(j?val[j-1][k]:0)-(j&&k?val[j-1][k-1]:0);
		for(int j=0;j<m;j++) for(int k=0;k<j;k++) chkmin(d[i][j][1],d[i][k][0]+val[k][j]+nval[k][j]-pl[i][k]);
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++) cout<<d[i][j][0]<<' ';
//		cout<<endl;
//	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++) cout<<d[i][j][1]<<' ';
//		cout<<endl;
//	}
	printf("%lld\n",min(d[n-1][m-1][0],d[n-1][m-1][1]));
	return 0;
}