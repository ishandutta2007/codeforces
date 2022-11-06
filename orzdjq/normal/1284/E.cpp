#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=5005;
struct P{
    LL x,y;
    double ang;
    int id;
    P(LL _x=0,LL _y=0,int _id=0){
    	x=_x,y=_y;id=_id;
	}
    P operator +(P p){
    	return P(x+p.x,y+p.y);
	}
	P operator -(P p){
		return P(x-p.x,y-p.y);
	}
	LL det(P p){
		return x*p.y-y*p.x;
	}
	void D(){
		ang=atan2(y,x);
	}
	bool operator <(P p){
		if (fabs(ang-p.ang)>1e-4) return ang<p.ang;
		return this->det(p)>0;
	}
};
P A[Maxn];
int S[Maxn];
vector<int> pos[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		A[i]=P(x,y);
	}
	LL res=0;
	for (int i=0;i<n;i++){
		LL ans=0;
		vector<P> V;
		for (int j=0;j<n;j++){
			if (i==j) continue;
			V.pb(A[j]-A[i]);
			V.back().id=(j+1);
			V.pb(A[i]-A[j]);
			V.back().id=-(j+1);
		}
		for (int j=0;j<V.size();j++){
			V[j].D();
		}
		sort(V.begin(),V.end());
		memset(S,0,sizeof(S));
		for (int j=0;j<Maxn;j++) pos[j].clear();
		for (int j=0;j<V.size();j++){
			int vv;
			if (V[j].id<0){vv=0;
			}
			else vv=1;
			if (j==0) S[j]=vv;
			else S[j]=S[j-1]+vv;
			pos[abs(V[j].id)-1].pb(j);
		}
		for (int j=0;j<n;j++){
			if (j==i) continue;
			int a=pos[j][0],b=pos[j][1];
			if (a>b) swap(a,b);
			int cc=S[b-1]-S[a];
			int rem=n-2-cc;
			ans+=1ll*(rem)*(rem-1)*(rem-2)/6;
			ans+=1ll*(cc)*(cc-1)*(cc-2)/6;
		}
		ans/=2;
		LL tot=1ll*(n-1)*(n-2)*(n-3)*(n-4)/24;
		//cout<<tot<<' '<<ans<<endl;
		res+=tot-ans;
	}
	printf("%lld\n",res);
	return 0;
}