#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define pli pair<LL,int>
#define mp make_pair
#define pb push_back
#define nd second
#define ds first
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
 	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 200020
set<int>bl[30],br[30],S;
int fl[M],fr[M],t[M],c[M],n,L[M],R[M],m,sm[30]; char ch[M];
inline void add(int k,int x){for(;k<=n;k+=(k&-k))c[k]+=x;}
inline int qry(int k,int tt=0){for(;k;k-=(k&-k))tt+=c[k];return tt;}
inline int fdl(int x){return x==fl[x]?x:fl[x]=fdl(fl[x]);}
inline int fdr(int x){return x==fr[x]?x:fr[x]=fdr(fr[x]);}
#define IT set<int>::iterator
inline void _Ins(int a,int b){
	if(t[a]!=t[b]){
		// printf("Ins: %d %d [ %d %d ]",a,b,t[a],t[b]);cerr el;
		bl[t[a]].insert(a),br[t[b]].insert(b);
	}
}
inline void _Del(int a,int b){
	if(t[a]!=t[b]){
		// printf("Del: %d %d [ %d %d ]",a,b,t[a],t[b]);cerr el;
		bl[t[a]].erase(a),br[t[b]].erase(b);
	}
}
inline void Ins(int a){
	++sm[t[a]],S.insert(a); IT it=S.find(a); int pr,sf;
	--it,pr=(*it),++it,++it,sf=(*it);
	if(pr>=1&&sf<=n) _Del(pr,sf);
	if(pr>=1) _Ins(pr,a); if(sf<=n) _Ins(a,sf);
}
inline void Del(int a){
	--sm[t[a]]; IT it=S.find(a); int pr,sf;
	--it,pr=(*it),++it,++it,sf=(*it),--it,S.erase(it);
	if(pr>=1) _Del(pr,a); if(sf<=n) _Del(a,sf);
	if(pr>=1&&sf<=n) _Ins(pr,sf);
}
inline void del(int x){
	int l=fdl(x-1),r=fdr(x+1); if(t[l]==t[x]) Del(l); if(t[x]==t[r]) Del(x);
	if(t[l]==t[r]) Ins(l); fl[x]=x-1,fr[x]=x+1,add(x,-1);
}
inline void calc(int w){
	// debug(w)sp,debug(bl[w].size())sp,debug(br[w].size())sp,debug(m)el;
	if(!bl[w].empty()){
		int x=(*bl[w].begin()),y; x=fdr(x+1),L[m]=R[m]=qry(x),del(x);
		// debug(x)sp,debug(qry(x))el;
		for(y=fdr(x);y<=n&&t[y]!=t[x];x=y,del(y),y=fdr(y)) R[m]++;
	}
	else{
		int x=(*br[w].begin()),y; L[m]=R[m]=qry(x),del(x);
		for(y=fdl(x);y>=1&&t[y]!=t[x];x=y,del(y),y=fdl(y)) L[m]--;
	}
}
inline void solve(){
	scanf("%s",ch+1),n=strlen(ch+1),S.clear(),m=0;
	for(int i=1;i<=n;i++) c[i]=0,t[i]=ch[i]-'a',fl[i]=fr[i]=i;
	for(int i=1;i<=n;i++) add(i,1);
	t[0]=-1,t[n+1]=-2,fr[n+1]=n+1,S.insert(0),S.insert(n+1);
	for(int i=0;i<26;i++) bl[i].clear(),br[i].clear(),sm[i]=0;
	// fgx;
	for(int i=1;i<n;i++) if(t[i]==t[i+1]) Ins(i);
	// fgx;fgx;
	while(fdr(1)<=n){
		int w=-1,mx=-1,sum=0; ++m;
		for(int i=0;i<26;sum+=sm[i],i++) if(sm[i]>mx) mx=sm[i],w=i;
		// debug(m)sp,debug(mx)sp,debug(sum)el;
		if(sum<2||sum==mx){
			int x=fdr(1),las=x; del(x),L[m]=R[m]=1;
			for(int y=fdr(las);y<=n&&t[y]!=t[las];las=y,del(y),y=fdr(las),++R[m]);
		} else calc(w);
	} printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%d %d\n",L[i],R[i]);
}
int main(){
	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}