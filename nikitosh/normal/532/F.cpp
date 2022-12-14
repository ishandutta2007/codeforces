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

const int MAX_L=2e5+100,DELTA=60;
char S[MAX_L],T[MAX_L];
char A[30][MAX_L],B[30][MAX_L];
int q[30];

inline int Mod(int a,int m){
	return a>=m?a-m:a;
}
const int M1=1e9+9, M2=1e9+7;
struct h{
	int x,y;
	h():x(0),y(0){}
	h(int x):x(x),y(x){}
	h(int x,int y):x(x),y(y){}
	inline h operator +(const h &B) const{return h(Mod(x+B.x,M1),Mod(y+B.y,M2));}
	inline h operator -(const h &B) const{return h(Mod(x+M1-B.x,M1),Mod(y+M2-B.y,M2));}
	inline h operator *(LL k) const{return h(int((x*k)%M1),int((y*k)%M2));}
	inline h operator *(const h &B) const{return h(int((LL(x)*B.x)%M1),int((LL(y)*B.y)%M2));}
	inline bool operator ==(const h &B) const{return x==B.x && y==B.y;}
	inline bool operator !=(const h &B) const{return x!=B.x || y!=B.y;}
};
const int P=239017;
h Deg[MAX_L], HashT[30], Hash[30][MAX_L];
inline h Get(int k,int a,int l){
	return Hash[k][a+l]-Hash[k][a]*Deg[l];
}

vi ListA[30],ListB[30];
vi V;


int main(){
#ifdef LOCAL
	assert(freopen("test.in","r",stdin));
	assert(freopen("test.out","w",stdout));
#endif

	int N,M;
	scanf("%d%d\n",&N,&M);
	gets(S);
	gets(T);
	forn(i,N)
		ListA[S[i]-'a'].pb(i);
	forn(i,M)
		ListB[T[i]-'a'].pb(i);
	
	Deg[0]=1;
	forn(k,26){
		forn(i,N){
			A[k][i]=(S[i]=='a'+k)+DELTA;
			Hash[k][i+1]=Hash[k][i]*P+A[k][i];
			Deg[i+1]=Deg[i]*P;
		}
		forn(i,M){
			B[k][i]=(T[i]=='a'+k)+DELTA;
			HashT[k]=HashT[k]*P+B[k][i];
		}
	}
	
	forn(i,N-M+1){
		forn(k,26)
			q[k]=k;
		forn(k,26){
			auto it=lower_bound(all(ListA[k]),i);
			if(it!=ListA[k].end()){
				int a=*it;
				if(a<i+M)
					q[k]=T[a-i]-'a', q[T[a-i]-'a']=k;
			}
		}
		bool ok=1;
		forn(k,26)
			if(q[q[k]]!=k){
				ok=0;
				break;
			}
		if(!ok)
			continue;
		forn(k,26)
			if(Get(k,i,M)!=HashT[q[k]]){
				ok=0;
				break;
			}
		if(ok)
			V.pb(i);
	}
	printf("%d\n",V.size());
	forit(i,V)
		printf("%d ",*i+1);
	puts("");
	

	return 0;
}