#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,k;
int pos[MN],apos[MN];
inline void ask1(int i){
	printf("? ");
	F(j,1,k-1)printf("%d ",j);
	printf("%d\n",i);
	fflush(stdout);
	scanf("%d%d",&pos[i],&apos[i]);
}
int main(){
	int A=0,B=0,C=0,Ai=0,Bi=0,mini=0,maxi=0;
	scanf("%d%d",&n,&k);
	if(k==1){
		puts("! 1");
		fflush(stdout);
		return 0;
	}
	if(k==2){
		int ar[3];
		puts("? 1 2"),fflush(stdout),scanf("%*d%d",&ar[0]);
		puts("? 1 3"),fflush(stdout),scanf("%*d%d",&ar[1]);
		puts("? 2 3"),fflush(stdout),scanf("%*d%d",&ar[2]);
		sort(ar,ar+3);
		if(ar[1]==ar[0])puts("! 1");
		else puts("! 2");
		fflush(stdout);
		return 0;
	}
	F(i,k,n)ask1(i);
	F(i,k,n)if(pos[i]==i){
		++C;
		if(!mini)mini=maxi=i;
		else{
			if(apos[mini]>apos[i])mini=i;
			if(apos[maxi]<apos[i])maxi=i;
		}
	}
	debug("C=%d\n",C);
	if(!C){
		if(*min_element(apos+k,apos+n+1)!=*max_element(apos+k,apos+n+1)){
			Ai=min_element(apos+k,apos+n+1)-apos;
			Bi=max_element(apos+k,apos+n+1)-apos;
			int cnt=1;
			F(i,1,k-1){
				printf("? ");
				F(j,1,k-1)if(j!=i)printf("%d ",j);
				printf("%d %d\n",Ai,Bi);
				fflush(stdout);
				int x,y;
				scanf("%d%d",&x,&y);
				if(x==pos[Bi])++cnt;
			}
			printf("! %d\n",cnt);
			fflush(stdout);
		}else{
			int pos1=k,pos2=n;
			int cnt=0,val=0;
			F(i,1,k-1){
				printf("? ");
				F(j,1,k-1)if(j!=i)printf("%d ",j);
				printf("%d %d\n",pos1,pos2);
				fflush(stdout);
				int x,y;
				scanf("%d%d",&x,&y);
				if(x==pos[pos1])++cnt;
				else val=y;
			}
			if(val<apos[pos1])printf("! %d\n",cnt+2);
			else printf("! %d\n",k-1-cnt);
			fflush(stdout);
		}
		return 0;
	}
	F(i,k,n)if(pos[i]!=i){
		if(apos[i]>apos[maxi])++B,Bi=i;
		else ++A,Ai=i;
	}
	debug("%d %d %d\n",A,B,C);
	int cnt=1;
	if(C){
		if(A){
			F(i,1,k-1){
				printf("? ");
				F(j,1,k-1)if(j!=i)printf("%d ",j);
				printf("%d %d\n",maxi,Ai);
				fflush(stdout);
				int x,y;
				scanf("%d%d",&x,&y);
				if(x==maxi)++cnt;
			}
		}else{
			int posj=B?Bi:maxi;
			F(i,1,k-1){
				printf("? ");
				F(j,1,k-1)if(j!=i)printf("%d ",j);
				printf("%d %d\n",mini,posj);
				fflush(stdout);
				int x,y;
				scanf("%d%d",&x,&y);
				if(x!=mini)++cnt;
			}
		}
	}
	printf("! %d\n",cnt);
	fflush(stdout);
	return 0;
}