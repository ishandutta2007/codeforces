#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cctype>

#include<iostream>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<deque>
using namespace std;

#ifdef WIN32
	#define lld "%I64d"
	#define llu "%I64u"
#else
	#define lld "%lld"
	#define llu "%llu"
#endif

typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define forn(i,n) for(int i=0;i<(n);++i)
#define fornr(i,n) for(int i=(n)-1;i>=0;--i)
#define forab(i,a,b) for(int i=(a);i<(b);++i)
#define forba(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define forit(i,A) for(__typeof((A).begin()) i=(A).begin();i!=(A).end();++i)
#define all(A) (A).begin(),(A).end()

struct ev{
	int x,id,type;
	ev():x(0),id(-1),type(-1){}
	ev(int _x,int _id,int _type):x(_x),id(_id),type(_type){}
	bool operator <(const ev &B) const{
		return x<B.x || (x==B.x && type<B.type);
	}
};

const int MAX_N=2e5+100, MAX_T=4*MAX_N;
const LL INFLONG=LL(1e18)+100;
int L[MAX_N], R[MAX_N], A[MAX_N], B[MAX_N], C[MAX_N];

set<pair<int,int> > Left,Right;

vector<ev> Ev;

LL Ans=-INFLONG;
int Id1=-1, Id2=-1;
inline void relax(int id1,int id2,LL ans){
	assert(id1>=0 && id2>=0);
	if(ans>Ans)
		Ans=ans, Id1=id1, Id2=id2;
}
LL Sum[MAX_T];

vector<pair<int,pii> > c;


const int ST_SZ=1<<20, ST_SZ2=2*ST_SZ,INF=1e9;
pii ST[ST_SZ2];
pii Get(int qL,int qR,int cV=1,int cL=0,int cR=ST_SZ){
	if(cL>=qL && cR<=qR)
		return ST[cV];
	if(cL>=qR || cR<=qL)
		return mp(-INF,-1);
	int cM=(cL+cR)/2, v1=cV*2, v2=v1+1;
	return max(Get(qL,qR,v1,cL,cM), Get(qL,qR,v2,cM,cR));
}
void Add(int k,const pii &p){
	k+=ST_SZ;
	assert(ST[k]==mp(-INF,-1));
	ST[k]=p;
	for(k/=2;k>=1;k/=2)
		ST[k]=max(ST[k*2],ST[k*2+1]);
}
void Del(int k,const pii &p){
	k+=ST_SZ;
	assert(ST[k]==p);
	ST[k]=mp(-INF,-1);
	for(k/=2;k>=1;k/=2)
		ST[k]=max(ST[k*2],ST[k*2+1]);
}

inline LL Len(int r,int l){
	return Sum[r]-Sum[l];
}


int main(){
#ifdef LOCAL
	assert(freopen("test.in","r",stdin));
	assert(freopen("test.out","w",stdout));
#endif

	int N,M;
	scanf("%d%d",&N,&M);
	forn(i,N)
		scanf("%d%d",&L[i],&R[i]), c.pb(mp(L[i],mp(i,0))), c.pb(mp(R[i],mp(i,1)));
	forn(i,M)
		scanf("%d%d%d",&A[i],&B[i],&C[i]), c.pb(mp(A[i],mp(i,2))), c.pb(mp(B[i],mp(i,3)));
	sort(all(c));
	forit(i,c){
		int t=i->snd.snd, id=i->snd.fst, x=i-c.begin();
		if(t==0)
			L[id]=x;
		else if(t==1)
			R[id]=x;
		else if(t==2)
			A[id]=x;
		else if(t==3)
			B[id]=x;
		if(x)
			Sum[x]=Sum[x-1]+i->fst-(i-1)->fst;
	}
	int Max=c.size();

	forn(i,N){
		Ev.pb(ev(L[i],i,0));
		Ev.pb(ev(R[i],i,3));
	}
	forn(i,M){
		Ev.pb(ev(A[i],i,1));
		Ev.pb(ev(B[i],i,2));
	}
	
	forab(i,1,ST_SZ2)
		ST[i]=mp(-INF,-1);
	
	sort(all(Ev));
	forit(e,Ev){
		int id=e->id;
		if(e->type==0){
			Left.insert(mp(L[id],id));
			Right.insert(mp(R[id],id));
			pii p=Get(R[id],Max);
			if(p.snd!=-1)
				relax(id,p.snd,p.fst*Len(R[id],L[id]));
		}else if(e->type==3){
			Left.erase(mp(L[id],id));
			Right.erase(mp(R[id],id));
		}else if(e->type==1){
			if(!Right.empty()){
				pii p=*Right.rbegin();
				relax(p.snd,id,C[id]*Len(min(p.fst,B[id]),A[id]));
			}
			Add(B[id],mp(C[id],id));
		}else if(e->type==2){
			if(!Left.empty()){
				pii p=*Left.begin();
				relax(p.snd,id,C[id]*Len(B[id],max(p.fst,A[id])));
			}
			Del(B[id],mp(C[id],id));
		}
	}
	
	if(Ans<=0)
		puts("0");
	else
		printf(lld"\n%d %d\n",Ans,Id1+1,Id2+1);

	return 0;
}