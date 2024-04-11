#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,int> pdd;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct heap{
	priority_queue<pdd> q1,q2;
	void clear(){while(!q1.empty()) q1.pop(); while(!q2.empty()) q2.pop();}
	void update(){while(!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();}
	void push(pdd x){q1.push(x);}
	void del(pdd x){q2.push(x); update();}
	pdd top(){return q1.empty()?mp(-1e9,0):q1.top();}
}s[4][4];

struct node{
	double x[4];
	bool operator<(const node c)const{return x[3]>c.x[3];}
}t[2005];

int n,a,b;

void change(int id,int x,int y){
	if(x==0) s[0][1].del(mp(t[id].x[1],id)),s[0][2].del(mp(t[id].x[2],id)),s[0][3].del(mp(t[id].x[3],id));
	else for(int j=1;j<x;j++) s[j][x].del(mp(t[id].x[j]-t[id].x[x],id));
	if(x==2) s[3][2].del(mp(t[id].x[3]-t[id].x[2],id));
	for(int j=1;j<y;j++) s[j][y].push(mp(t[id].x[j]-t[id].x[y],id));
	if(y==2) s[3][2].push(mp(t[id].x[3]-t[id].x[2],id));
}

int main(){
	n=readint(); a=readint(); b=readint();
	for(int i=1;i<=n;i++) scanf("%lf",&t[i].x[1]);
	for(int i=1;i<=n;i++) scanf("%lf",&t[i].x[2]);
	for(int i=1;i<=n;i++) t[i].x[3]=1-(1-t[i].x[1])*(1-t[i].x[2]);
	sort(t+1,t+n+1);
	double res=0;
	for(int i=0;i<=min(a,b);i++){
		double ans=0;
		for(int j=1;j<=i;j++) ans+=t[j].x[3];
		for(int j=i+1;j<=n;j++) s[0][1].push(mp(t[j].x[1],j)),s[0][2].push(mp(t[j].x[2],j)),s[0][3].push(mp(t[j].x[3],j));
		for(int j=1;j<=i;j++) s[1][3].push(mp(t[j].x[1]-t[j].x[3],j)),s[2][3].push(mp(t[j].x[2]-t[j].x[3],j));
		for(int j=1;j<=b-i;j++){
			pdd t1=s[0][2].top(),t2=s[0][3].top(),t3=s[2][3].top();
			if(t1.fi>=t2.fi+t3.fi) change(t1.se,0,2);
			else change(t2.se,0,3),change(t3.se,3,2);
			ans+=max(t1.fi,t2.fi+t3.fi);
		}
		for(int j=1;j<=a-i;j++){
			pdd t1=s[0][1].top(),t2=s[0][2].top(),t3=s[0][3].top(),t4=s[1][2].top(),t5=s[1][3].top(),t6=s[2][3].top(),t7=s[3][2].top();
			double v1=t1.fi,v2=t4.fi+t2.fi,v3=t5.fi+t3.fi,v4=t4.fi+t6.fi+t3.fi,v5=t5.fi+t7.fi+t2.fi;
			if(v1>=v2&&v1>=v3&&v1>=v4&&v1>=v5) change(t1.se,0,1);
			else if(v2>=v3&&v2>=v4&&v2>=v5) change(t2.se,0,2),change(t4.se,2,1);
			else if(v3>=v4&&v3>=v5) change(t3.se,0,3),change(t5.se,3,1);
			else if(v4>=v5) change(t3.se,0,3),change(t6.se,3,2),change(t4.se,2,1);
			else change(t2.se,0,2),change(t5.se,3,1),change(t7.se,2,3);
			ans+=max(v1,max(v2,max(v3,max(v4,v5))));
		}
		s[0][1].clear(),s[0][2].clear(),s[0][3].clear(),s[1][2].clear(),s[1][3].clear(),s[2][3].clear(),s[3][2].clear();
		chkmax(res,ans);
	}
	printf("%.10lf\n",res);
	return 0;
}