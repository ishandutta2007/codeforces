#include<bits/stdc++.h>

#define y1 dmytsdy
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld,ld> pdd;
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

const double eps=1e-12;
int n;
ll x1[5],x2[5],y1[5],y2[5];

ll dist(pll x,pll y){return (x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se);}

pll getp(int i,int j){
	if(x1[i]==x2[i]&&x1[j]==x2[j]){
		return mp(1<<30,1<<30);
	}
	if(x1[i]==x2[i]){
		if(x1[j]==x1[i]){
			if(y1[j]<min(y1[i],y2[i])||y1[j]>max(y1[i],y2[i])) return mp(1<<30,1<<30);
			return mp(x1[i],y1[j]);
		}
		else if(x2[j]==x1[i]){
			if(y2[j]<min(y1[i],y2[i])||y2[j]>max(y1[i],y2[i])) return mp(1<<30,1<<30);
			return mp(x1[i],y2[j]);
		}
		else return mp(1<<30,1<<30);
	}
	if(x1[j]==x2[j]){
		if(x1[i]==x1[j]){
			if(y1[i]<min(y1[j],y2[j])||y1[i]>max(y1[j],y2[j])) return mp(1<<30,1<<30);
			return mp(x1[j],y1[i]);
		}
		else if(x2[i]==x1[j]){
			if(y2[i]<min(y1[j],y2[j])||y2[i]>max(y1[j],y2[j])) return mp(1<<30,1<<30);
			return mp(x1[j],y2[i]);
		}
		else return mp(1<<30,1<<30);
	}
	ld k1=(y2[i]-y1[i]),b1=(x2[i]*y1[i]-x1[i]*y2[i]);
//	cout<<"test "<<i<<' '<<j<<' '<<k1<<' '<<b1<<endl;
	if(k1*x1[j]+b1!=y1[j]*(x2[i]-x1[i])&&k1*x2[j]+b1!=y2[j]*(x2[i]-x1[i])) return mp(1<<30,1<<30);
	if(k1*x1[j]+b1==y1[j]*(x2[i]-x1[i])){
		if(x1[j]<min(x1[i],x2[i])||x1[j]>max(x1[i],x2[i])||y1[j]<min(y1[i],y2[i])||y1[j]>max(y1[i],y2[i])) return mp(1<<30,1<<30);
		return mp(x1[j],y1[j]);
	}
	else{
		if(x2[j]<min(x1[i],x2[i])||x2[j]>max(x1[i],x2[i])||y2[j]<min(y1[i],y2[i])||y2[j]>max(y1[i],y2[i])) return mp(1<<30,1<<30);
		return mp(x2[j],y2[j]);
	}
}

bool getans(int i,int j){
	if((x2[i]-x1[i])*(y2[j]-y1[j])-(y2[i]-y1[i])*(x2[j]-x1[j])==0) return false;
	if((x2[i]-x1[i])*(x2[j]-x1[j])+(y2[i]-y1[i])*(y2[j]-y1[j])<0) return false;
	int now=0;
	for(int k=1;k<=3;k++) if(i!=k&&j!=k) now=k;
	pdd p1=getp(i,now),p2=getp(j,now);
//	cout<<"p "<<p1.fi<<' '<<p1.se<<' '<<p2.fi<<' '<<p2.se<<endl;
	if(p1.fi==(1<<30)||p2.fi==(1<<30)) return false;
	ll dis1=dist(p1,mp(x1[i],y1[i])),dis2=dist(p1,mp(x2[i],y2[i]));
	if(16*min(dis1,dis2)<max(dis1,dis2)) return false;
	dis1=dist(p2,mp(x1[j],y1[j])),dis2=dist(p2,mp(x2[j],y2[j]));
	if(16*min(dis1,dis2)<max(dis1,dis2)) return false;
	return true;
}

int main(){
	int T=readint();
	while(T--){
		for(int i=1;i<=3;i++) x1[i]=readint(),y1[i]=readint(),x2[i]=readint(),y2[i]=readint();
		for(int i=1;i<=3;i++) if(x1[i]>x2[i]) swap(x1[i],x2[i]),swap(y1[i],y2[i]);
		bool fl=0;
		for(int i=1;i<=3;i++){
			for(int j=i+1;j<=3;j++){
				if(x1[i]==x2[j]&&y1[i]==y2[j]){
					swap(x1[j],x2[j]),swap(y1[j],y2[j]);
					if(getans(i,j)) fl=1;
					swap(x1[j],x2[j]),swap(y1[j],y2[j]);
				}
				if(x2[i]==x1[j]&&y2[i]==y1[j]){
					swap(x1[i],x2[i]),swap(y1[i],y2[i]);
					if(getans(i,j)) fl=1;
					swap(x1[i],x2[i]),swap(y1[i],y2[i]);
				}
				if(x2[i]==x2[j]&&y2[i]==y2[j]){
					swap(x1[i],x2[i]),swap(y1[i],y2[i]),swap(x1[j],x2[j]),swap(y1[j],y2[j]);
					if(getans(i,j)) fl=1;
					swap(x1[i],x2[i]),swap(y1[i],y2[i]),swap(x1[j],x2[j]),swap(y1[j],y2[j]);
				}
				if(x1[i]==x1[j]&&y1[i]==y1[j]){
					if(getans(i,j)) fl=1;
				}
			}
		}
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}