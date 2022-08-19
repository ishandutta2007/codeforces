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

int n,cnta,cntb;
int a[5],b[5],x[5],y[5],now[5],cnt[5],t[5];
pii t1[5],t2[5],ans[5];

int getdiv(ll d,bool kp){
	if(a[1]>a[2]) swap(a[1],a[2]);
	if(b[1]>b[2]) swap(b[1],b[2]);
	int l=0,r=1e9,ret=-1,st=0;
	while(l<=r){
		int mid=(l+r)/2;
		int l1=a[1]-mid,r1=a[1]+mid;
		int l2=b[1]-mid,r2=b[1]+mid;
		int l3=a[2]-d-mid,r3=a[2]-d+mid;
		int l4=b[2]-d-mid,r4=b[2]-d+mid;
		if(max(max(l1,l2),max(l3,l4))<=min(min(r1,r2),min(r3,r4))){
			ret=mid,r=mid-1;
			if(kp) st=max(max(l1,l2),max(l3,l4));
		}
		else l=mid+1;
	}
	if(kp){
//		cout<<"kp "<<st<<' '<<ret<<' '<<d<<' '<<endl;
		for(int i=0;i<4;i++) if(x[i]==t[0]&&y[i]==a[1]) ans[i]=mp(x[i],st);
		for(int i=0;i<4;i++) if(x[i]==t[0]&&y[i]==a[2]) ans[i]=mp(x[i],st+d);
		for(int i=0;i<4;i++) if(x[i]==t[2]&&y[i]==b[1]) ans[i]=mp(x[i],st);
		for(int i=0;i<4;i++) if(x[i]==t[2]&&y[i]==b[2]) ans[i]=mp(x[i],st+d);
	}
	return ret;
}

int solve(int tx,bool kp){
	for(int i=0;i<4;i++) now[i]=(tx>>i)&1;
	cnt[0]=cnt[1]=0;
	for(int i=0;i<4;i++) cnt[now[i]]++;
	if(cnt[0]==2&&cnt[1]==2){
		int cnt1=0,cnt2=0;
		for(int i=0;i<4;i++){
			if(!now[i]) t1[++cnt1]=mp(x[i],y[i]);
			else t2[++cnt2]=mp(x[i],y[i]);
		}
		if(t1[1].fi==t1[2].fi){
			for(int i=0;i<4;i++) swap(x[i],y[i]);
			for(int i=1;i<=cnt1;i++) swap(t1[i].fi,t1[i].se);
			for(int i=1;i<=cnt2;i++) swap(t2[i].fi,t2[i].se);
			swap(t1,t2);
			for(int i=0;i<4;i++) now[i]^=1;
			int res=max(abs(min(t2[1].fi,t2[2].fi)-min(t1[1].fi,t1[2].fi)),abs(max(t2[1].fi,t2[2].fi)-max(t1[1].fi,t1[2].fi)));
			int tres=1<<30,opt=0,ty=t2[1].se+fabs(t1[1].fi-t1[2].fi);
//			if(kp) cout<<"res "<<res<<endl;
//			if(kp) cout<<"ty1 "<<ty<<endl;
			if(chkmin(tres,max(abs(t1[1].se-ty),abs(t1[2].se-ty)))) opt=1;
			ty=t2[1].se-fabs(t1[1].fi-t1[2].fi);
//			if(kp) cout<<"ty2 "<<ty<<endl;
			if(chkmin(tres,max(abs(t1[1].se-ty),abs(t1[2].se-ty)))) opt=2;
			if(kp){
				if(opt==1){
					ty=t2[1].se+fabs(t1[1].fi-t1[2].fi);
					for(int i=0;i<4;i++) if(now[i]&&x[i]==min(t2[1].fi,t2[2].fi)) ans[i]=mp(min(t1[1].fi,t1[2].fi),y[i]);
					for(int i=0;i<4;i++) if(now[i]&&x[i]==max(t2[1].fi,t2[2].fi)) ans[i]=mp(max(t1[1].fi,t1[2].fi),y[i]);
					for(int i=0;i<4;i++) if(!now[i]) ans[i]=mp(x[i],ty);
					for(int i=0;i<4;i++) if(!now[i]) ans[i]=mp(x[i],ty);
				}
				else{
					ty=t2[1].se-fabs(t1[1].fi-t1[2].fi);
					for(int i=0;i<4;i++) if(now[i]&&x[i]==min(t2[1].fi,t2[2].fi)) ans[i]=mp(min(t1[1].fi,t1[2].fi),y[i]);
					for(int i=0;i<4;i++) if(now[i]&&x[i]==max(t2[1].fi,t2[2].fi)) ans[i]=mp(max(t1[1].fi,t1[2].fi),y[i]);
					for(int i=0;i<4;i++) if(!now[i]) ans[i]=mp(x[i],ty);
					for(int i=0;i<4;i++) if(!now[i]) ans[i]=mp(x[i],ty);
				}
				for(int i=0;i<4;i++) printf("%d %d\n",ans[i].se,ans[i].fi);
			}
			for(int i=0;i<4;i++) swap(x[i],y[i]);
			return max(tres,res);
		}
		else if(t2[1].se==t2[2].se){
			int res=max(fabs(min(t2[1].fi,t2[2].fi)-min(t1[1].fi,t1[2].fi)),fabs(max(t2[1].fi,t2[2].fi)-max(t1[1].fi,t1[2].fi)));
//			cout<<"test "<<res<<endl;
			int tres=1<<30,opt=0,ty=t2[1].se+fabs(t1[1].fi-t1[2].fi);
//			cout<<"ty1 "<<ty<<endl;
			if(chkmin(tres,max(abs(t1[1].se-ty),abs(t1[2].se-ty)))) opt=1;
			ty=t2[1].se-fabs(t1[1].fi-t1[2].fi);
//			cout<<"ty2 "<<ty<<endl;
			if(chkmin(tres,max(abs(t1[1].se-ty),abs(t1[2].se-ty)))) opt=2;
			if(kp){
				if(opt==1){
					ty=t2[1].se+fabs(t1[1].fi-t1[2].fi);
					for(int i=0;i<4;i++) if(now[i]&&x[i]==min(t2[1].fi,t2[2].fi)) ans[i]=mp(min(t1[1].fi,t1[2].fi),y[i]);
					for(int i=0;i<4;i++) if(now[i]&&x[i]==max(t2[1].fi,t2[2].fi)) ans[i]=mp(max(t1[1].fi,t1[2].fi),y[i]);
					for(int i=0;i<4;i++) if(!now[i]) ans[i]=mp(x[i],ty);
					for(int i=0;i<4;i++) if(!now[i]) ans[i]=mp(x[i],ty);
				}
				else{
					ty=t2[1].se-fabs(t1[1].fi-t1[2].fi);
					for(int i=0;i<4;i++) if(now[i]&&x[i]==min(t2[1].fi,t2[2].fi)) ans[i]=mp(min(t1[1].fi,t1[2].fi),y[i]);
					for(int i=0;i<4;i++) if(now[i]&&x[i]==max(t2[1].fi,t2[2].fi)) ans[i]=mp(max(t1[1].fi,t1[2].fi),y[i]);
					for(int i=0;i<4;i++) if(!now[i]) ans[i]=mp(x[i],ty);
					for(int i=0;i<4;i++) if(!now[i]) ans[i]=mp(x[i],ty);
				}
				for(int i=0;i<4;i++) printf("%d %d\n",ans[i].fi,ans[i].se);
			}
			return max(tres,res);
		}
		if(fabs(t1[2].fi-t1[1].fi)!=fabs(t2[2].se-t2[1].se)) return 1<<30;
		int res=1<<30,opt=0;
		if(chkmin(res,max(max(abs(t1[1].se-t2[1].se),abs(t1[2].se-t2[2].se)),max(abs(t2[1].fi-t1[2].fi),abs(t2[2].fi-t1[1].fi))))) opt=1;
		if(chkmin(res,max(max(abs(t1[1].se-t2[2].se),abs(t1[2].se-t2[1].se)),max(abs(t2[1].fi-t1[1].fi),abs(t2[2].fi-t1[2].fi))))) opt=2;
		if(kp){
			if(opt==1){
				for(int i=0;i<4;i++) if(mp(x[i],y[i])==t1[1]) ans[i]=mp(t1[1].fi,t2[1].se);
				for(int i=0;i<4;i++) if(mp(x[i],y[i])==t1[2]) ans[i]=mp(t1[2].fi,t2[2].se);
				for(int i=0;i<4;i++) if(mp(x[i],y[i])==t2[1]) ans[i]=mp(t1[2].fi,t2[1].se);
				for(int i=0;i<4;i++) if(mp(x[i],y[i])==t2[2]) ans[i]=mp(t1[1].fi,t2[2].se);
			}
			else{
				for(int i=0;i<4;i++) if(mp(x[i],y[i])==t1[1]) ans[i]=mp(t1[1].fi,t2[2].se);
				for(int i=0;i<4;i++) if(mp(x[i],y[i])==t1[2]) ans[i]=mp(t1[2].fi,t2[1].se);
				for(int i=0;i<4;i++) if(mp(x[i],y[i])==t2[1]) ans[i]=mp(t1[1].fi,t2[1].se);
				for(int i=0;i<4;i++) if(mp(x[i],y[i])==t2[2]) ans[i]=mp(t1[2].fi,t2[2].se);
			}
			for(int i=0;i<4;i++) printf("%d %d\n",ans[i].fi,ans[i].se);
		}
		return res;
	}
	else if(cnt[0]>cnt[1]){
		if(cnt[0]==4){
			for(int i=0;i<4;i++) t[i]=x[i];
			sort(t,t+4);
			if(t[0]!=t[1]||t[2]!=t[3]||t[1]==t[2]) return 1<<30;
			cnta=cntb=0;
			for(int i=0;i<4;i++){
				if(x[i]==t[1]) a[++cnta]=y[i];
				else b[++cntb]=y[i];
			}
			int ret=getdiv(fabs(t[2]-t[0]),kp);
			if(kp){
				for(int i=0;i<4;i++) printf("%d %d\n",ans[i].fi,ans[i].se);
			}
			return ret;
		}
		else{
			int tcnt=0,pl=0,ply=0;
			for(int i=0;i<4;i++){
				if(!now[i]) t[tcnt++]=x[i];
				else pl=x[i],ply=y[i];
			}
			sort(t,t+3);
			if(t[0]!=t[1]&&t[1]!=t[2]) return 1<<30;
			if(t[0]!=t[1]) swap(t[0],t[2]);
			cnta=cntb=0;
			for(int i=0;i<4;i++){
				if(now[i]) continue;
				if(x[i]==t[0]) a[++cnta]=y[i];
				else b[++cntb]=y[i];
			}
			int res=fabs(pl-t[2]),tres=1<<30;
			int ty=ply-fabs(t[0]-t[2]),opt=0;
			if(chkmin(tres,max(abs(b[1]-ty),min(max(abs(a[1]-ply),abs(a[2]-ty)),max(abs(a[2]-ply),abs(a[1]-ty)))))) opt=1;
			ty=ply+fabs(t[0]-t[2]);
			if(chkmin(tres,max(abs(b[1]-ty),min(max(abs(a[1]-ply),abs(a[2]-ty)),max(abs(a[2]-ply),abs(a[1]-ty)))))) opt=2;
			if(kp){
				if(opt==1){
					ty=ply-fabs(t[0]-t[2]);
					if(max(abs(a[1]-ply),abs(a[2]-ty))<max(abs(a[2]-ply),abs(a[1]-ty))){
						for(int i=0;i<4;i++) if(now[i]) ans[i]=mp(t[2],y[i]);
						for(int i=0;i<4;i++){
							if(now[i]) continue;
							if(x[i]==t[2]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[1]) ans[i]=mp(x[i],ply);
							else if(x[i]==t[0]&&y[i]==a[2]) ans[i]=mp(x[i],ty);
						}
					}
					else{
						for(int i=0;i<4;i++) if(now[i]) ans[i]=mp(t[2],y[i]);
						for(int i=0;i<4;i++){
							if(now[i]) continue;
							if(x[i]==t[2]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[1]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[2]) ans[i]=mp(x[i],ply);
						}
					}
				}
				else{
					ty=ply+fabs(t[0]-t[2]);
					if(max(abs(a[1]-ply),abs(a[2]-ty))<max(abs(a[2]-ply),abs(a[1]-ty))){
						for(int i=0;i<4;i++) if(now[i]) ans[i]=mp(t[2],y[i]);
						for(int i=0;i<4;i++){
							if(now[i]) continue;
							if(x[i]==t[2]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[1]) ans[i]=mp(x[i],ply);
							else if(x[i]==t[0]&&y[i]==a[2]) ans[i]=mp(x[i],ty);
						}
					}
					else{
						for(int i=0;i<4;i++) if(now[i]) ans[i]=mp(t[2],y[i]);
						for(int i=0;i<4;i++){
							if(now[i]) continue;
							if(x[i]==t[2]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[1]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[2]) ans[i]=mp(x[i],ply);
						}
					}
				}
				for(int i=0;i<4;i++) printf("%d %d\n",ans[i].fi,ans[i].se);
			}
			return max(tres,res);
		}
	}
	else{
		for(int i=0;i<4;i++) now[i]^=1;
		swap(cnt[0],cnt[1]);
		for(int i=0;i<4;i++) swap(x[i],y[i]);
		if(cnt[0]==4){
			for(int i=0;i<4;i++) t[i]=x[i];
			sort(t,t+4);
			if(t[0]!=t[1]||t[2]!=t[3]||t[1]==t[2]){
				for(int i=0;i<4;i++) swap(x[i],y[i]);
				return 1<<30;
			}
			cnta=cntb=0;
			for(int i=0;i<4;i++){
				if(x[i]==t[1]) a[++cnta]=y[i];
				else b[++cntb]=y[i];
			}
			int ret=getdiv(fabs(t[2]-t[0]),kp);
			for(int i=0;i<4;i++) swap(x[i],y[i]);
			if(kp){
				for(int i=0;i<4;i++) printf("%d %d\n",ans[i].se,ans[i].fi);
			}
			return ret;
		}
		else{
			int tcnt=0,pl=0,ply=0;
			for(int i=0;i<4;i++){
				if(!now[i]) t[tcnt++]=x[i];
				else pl=x[i],ply=y[i];
			}
			sort(t,t+3);
			if(t[0]!=t[1]&&t[1]!=t[2]){
				for(int i=0;i<4;i++) swap(x[i],y[i]);
				return 1<<30;
			}
			if(t[0]!=t[1]) swap(t[0],t[2]);
			cnta=cntb=0;
			for(int i=0;i<4;i++){
				if(now[i]) continue;
				if(x[i]==t[0]) a[++cnta]=y[i];
				else b[++cntb]=y[i];
			}
			int res=fabs(pl-t[2]),tres=1<<30;
			int ty=ply-fabs(t[0]-t[2]),opt=0;
			if(chkmin(tres,max(abs(b[1]-ty),min(max(abs(a[1]-ply),abs(a[2]-ty)),max(abs(a[2]-ply),abs(a[1]-ty)))))) opt=1;
			ty=ply+fabs(t[0]-t[2]);
			if(chkmin(tres,max(abs(b[1]-ty),min(max(abs(a[1]-ply),abs(a[2]-ty)),max(abs(a[2]-ply),abs(a[1]-ty)))))) opt=2;
//			if(kp) cout<<"opt "<<opt<<' '<<tres<<' '<<res<<endl;
			if(kp){
				if(opt==1){
					ty=ply-fabs(t[0]-t[2]);
					if(max(abs(a[1]-ply),abs(a[2]-ty))<max(abs(a[2]-ply),abs(a[1]-ty))){
						for(int i=0;i<4;i++) if(now[i]) ans[i]=mp(t[2],y[i]);
						for(int i=0;i<4;i++){
							if(now[i]) continue;
							if(x[i]==t[2]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[1]) ans[i]=mp(x[i],ply);
							else if(x[i]==t[0]&&y[i]==a[2]) ans[i]=mp(x[i],ty);
						}
					}
					else{
						for(int i=0;i<4;i++) if(now[i]) ans[i]=mp(t[2],y[i]);
						for(int i=0;i<4;i++){
							if(now[i]) continue;
							if(x[i]==t[2]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[1]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[2]) ans[i]=mp(x[i],ply);
						}
					}
				}
				else{
					ty=ply+fabs(t[0]-t[2]);
//					cout<<"test "<<res<<' '<<tres<<' '<<ty<<endl;
					if(max(abs(a[1]-ply),abs(a[2]-ty))<max(abs(a[2]-ply),abs(a[1]-ty))){
						for(int i=0;i<4;i++) if(now[i]) ans[i]=mp(t[2],y[i]);
						for(int i=0;i<4;i++){
							if(now[i]) continue;
							if(x[i]==t[2]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[1]) ans[i]=mp(x[i],ply);
							else if(x[i]==t[0]&&y[i]==a[2]) ans[i]=mp(x[i],ty);
						}
					}
					else{
						for(int i=0;i<4;i++) if(now[i]) ans[i]=mp(t[2],y[i]);
						for(int i=0;i<4;i++){
							if(now[i]) continue;
							if(x[i]==t[2]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[1]) ans[i]=mp(x[i],ty);
							else if(x[i]==t[0]&&y[i]==a[2]) ans[i]=mp(x[i],ply);
						}
					}
				}
				for(int i=0;i<4;i++) printf("%d %d\n",ans[i].se,ans[i].fi);
			}
			for(int i=0;i<4;i++) swap(x[i],y[i]);
			return max(tres,res);
		}
	}
}

int main(){
	int T=readint();
	while(T--){
		for(int i=0;i<4;i++) x[i]=readint(),y[i]=readint();
		int cho=0,res=1<<30;
		for(int i=0;i<(1<<4);i++) if(chkmin(res,solve(i,0))) cho=i;
//		for(int i=0;i<(1<<4);i++) cout<<"solve "<<i<<' '<<solve(i,0)<<endl;
//		cout<<"test "<<cho<<endl;
		if(res==(1<<30)) printf("-1\n");
		else{
			printf("%d\n",res);
			solve(cho,1);
		}
	}
	return 0;
}