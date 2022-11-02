#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define DB long double
#define LDB long double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define rint register int 
#define M 1160010
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
LL k;
inline LL fd(LL kwt){
	if(!kwt) return k*(k+1)>>1;
	LL w=kwt/k,las=fd(w); LL t=kwt%k,cnt=0;
	if(las<=w*(k*k+1)+t*k+1) cnt=k;
	else if(las<=w*(k*k+1)+t*k+k) cnt=w*(k*k+1)+t*k+k-las+1;
//	LL res=kwt*(k*k+1)+((k*(k+1))>>1)-t+cnt;
//	debug(kwt)sp,debug(res)sp,debug(las)el;
	return kwt*(k*k+1)+((k*(k+1))>>1)-t+cnt;
}
inline LL getpos(LL n){
	LL rw=fd((n-1)/(k*k+1));
	if(rw!=n){
		LL hv=((n-1)/(k*k+1))*k;
//		debug(hv)el;
		hv+=((n-1)%(k*k+1)-(rw<n))/k;
//		debug(hv)el;
		hv-=(n-1)/(k*k+1);
//		debug(hv)el;
		if(rw<n) hv--;
		return n+hv;
	} LL kwt=n/(k*k+1);
	LL w=kwt/k,t=kwt%k,cnt;
	cnt=n-kwt*(k*k+1)-((k*(k+1))>>1)+t;
	if(cnt>0) return getpos(w*(k*k+1)+t*k+k+1)+1;
	return getpos(w*(k*k+1)+t*k+k)+1;
	
}
int main(){
	LL n;
	for(int Cas=read();Cas;--Cas)
		n=read(),k=read(),printf("%lld\n",getpos(n));
	return 0;
}