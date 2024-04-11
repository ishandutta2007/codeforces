#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q,blo,cnt;
int a[4100],pos[4100],l[70000],r[70000],lab[20][260][260],ans[70000],t[600][260][260],tl[260],tr[260];
vector<int> tmp[20];
vector<pii> vec;

void work(int id,int l,int r,vector<int> &x){
	if(l==r){
		x.pb(pos[l]),t[id][0][0]=pos[l];
		return;
	}
	int mid=(l+r)/2;
	vector<int> lson(0),rson(0);
	work(id<<1,l,mid,lson),work(id<<1|1,mid+1,r,rson);
	int now1=0,now2=0;
	while(now1<lson.size()&&now2<rson.size()){
		if(lson[now1]<rson[now2]) x.pb(lson[now1]),now1++;
		else x.pb(rson[now2]),now2++;
	}
	while(now1<lson.size()) x.pb(lson[now1]),now1++;
	while(now2<rson.size()) x.pb(rson[now2]),now2++;
	for(int i=0;i<x.size();i++){
		tl[i]=lower_bound(lson.begin(),lson.end(),x[i])-lson.begin();
		tr[i]=lower_bound(rson.begin(),rson.end(),x[i])-rson.begin();
	}
	for(int i=0;i<x.size();i++){
		for(int j=i;j<x.size();j++){
			int L1=tl[i],R1=tl[j],L2=tr[i],R2=tr[j];
			if(R1>=lson.size()||lson[R1]!=x[j]) R1--;
			if(R2>=rson.size()||rson[R2]!=x[j]) R2--;
			if(L1<=R1&&L2<=R2){
				vec.pb(mp(t[id<<1][L1][R1],t[id<<1|1][L2][R2]));
				cnt++,t[id][i][j]=cnt+n;
			}
			else t[id][i][j]=L1<=R1?t[id<<1][L1][R1]:t[id<<1|1][L2][R2];
		}
	}
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),pos[a[i]]=i;
	for(int i=1;i<=q;i++) l[i]=readint(),r[i]=readint();
	blo=256;
	for(int i=1;i<=n;i+=blo){
		int b=(i-1)/blo+1;
		work(1,i,min(n,i+blo-1),tmp[b]);
		for(int j=0;j<tmp[b].size();j++)
			for(int k=j;k<tmp[b].size();k++)
				lab[b][j][k]=t[1][j][k];
	}
	for(int i=1;i<=q;i++){
		int now=0;
		for(int j=1;j<=n;j+=blo){
			int b=(j-1)/blo+1;
			int L=lower_bound(tmp[b].begin(),tmp[b].end(),l[i])-tmp[b].begin();
			int R=upper_bound(tmp[b].begin(),tmp[b].end(),r[i])-tmp[b].begin()-1;
			if(L<=R){
				if(!now) now=lab[b][L][R];
				else{
					vec.pb(mp(now,lab[b][L][R]));
					cnt++,now=cnt+n;
				}
			}
		}
		ans[i]=now;
	}
	printf("%d\n",vec.size()+n);
	for(auto x:vec) printf("%d %d\n",x.fi,x.se);
	for(int i=1;i<=q;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}