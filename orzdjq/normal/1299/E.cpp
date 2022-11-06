#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
#define _ 0
using namespace std;
#ifndef MY
	#define putchar IO::_putchar
	#define getchar IO::_getchar
#endif
namespace IO
{
    const int sz=1<<15;
    char inbuf[sz],outbuf[sz];
    char *pinbuf=inbuf+sz;
    char *poutbuf=outbuf;
    inline char _getchar()
    {
        if (pinbuf==inbuf+sz)fread(inbuf,1,sz,stdin),pinbuf=inbuf;
        return *(pinbuf++);
    }
    inline void _putchar(char x)
    {
        if (poutbuf==outbuf+sz)fwrite(outbuf,1,sz,stdout),poutbuf=outbuf;
        *(poutbuf++)=x;
    }
    inline void flush()
    {
        if (poutbuf!=outbuf)fwrite(outbuf,1,poutbuf-outbuf,stdout),poutbuf=outbuf;
    }
}
inline int read()
{
    int x=0,p=1;
	char c=getchar();
    while (c<'0' || c>'9'){
    	if (c=='-') p=-1;
    	c=getchar();
	}
    while (c>='0' && c<='9') x=x*10+c-48,c=getchar();
    return x*p;
}
const int Maxn=808;
int n;
int ask(vector<int> V){
	printf("? %d ",V.size());
	for (int i=0;i<V.size();i++){
		printf("%d ",V[i]);
	}
	printf("\n");
	fflush(stdout);
	int t;
	int ret=0;
//	for (int i=0;i<V.size();i++) ret+=V[i];
//	if (ret%V.size()==0) return 1;
//	return 0;
	scanf("%d",&t);
	return t; 
}
int ans[Maxn],M[Maxn],M3[Maxn],M5[Maxn],M7[Maxn],M8[Maxn],M4[Maxn];
int pos[Maxn];
bool Fd[Maxn];
void Output(){
	printf("! ");
	if (ans[1]>n/2){
		for (int i=1;i<=n;i++) ans[i]=n+1-ans[i];
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	fflush(stdout);
}
int main(){
	scanf("%d",&n);
	if (n<=15){
		vector<int> S;
		for (int i=1;i<=n;i++){
			vector<int> tmp;
			for (int j=1;j<=n;j++){
				if (i==j) continue;
				tmp.pb(j);
			}
			if (ask(tmp)){
				S.pb(i);
			}
		}
		ans[S[0]]=1;ans[S[1]]=n;
		for (int i=1;i<=n;i++){
			if (ans[i]) continue;
			vector<int> tmp;
			tmp.pb(i);tmp.pb(S[0]);
			M[i]=ask(tmp);
		}
		for (int i=2,j=n-1;i<j;i++,j--){
			vector<int> D;
			for (int k=1;k<=n;k++){
				if (ans[k]) continue;
				vector<int> tmp;
				for (int l=1;l<=n;l++){
					if (ans[l] || k==l) continue;
					tmp.pb(l);
				}
				if (ask(tmp)){
					D.pb(k);
				}
			}
			if (M[D[0]]==(i&1)){
				ans[D[0]]=i,ans[D[1]]=j; 
			}
			else{
				ans[D[0]]=j;ans[D[1]]=i;
			}
		}
		Output();
		return 0;
	}
	vector<int> S;
	for (int i=1;i<=n;i++){
		vector<int> tmp;
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			tmp.pb(j);
		}
		if (ask(tmp)){
			S.pb(i);
		}
	}
	ans[S[0]]=1;ans[S[1]]=n;
	for (int i=1;i<=n;i++){
		if (ans[i]) continue;
		vector<int> tmp;
		tmp.pb(i);tmp.pb(S[0]);
		M[i]=ask(tmp);
	}
	for (int i=2,j=n-1;i<=4;i++,j--){
		vector<int> D;
		for (int k=1;k<=n;k++){
			if (ans[k]) continue;
			vector<int> tmp;
			for (int l=1;l<=n;l++){
				if (ans[l] || k==l) continue;
				tmp.pb(l);
			}
			if (ask(tmp)){
				D.pb(k);
			}
		}
		if (M[D[0]]==(i&1)){
			ans[D[0]]=i,ans[D[1]]=j; 
		}
		else{
			ans[D[0]]=j;ans[D[1]]=i;
		}
	}

	vector<int> Al;
	for (int i=1;i<=n;i++){
		if (ans[i]) pos[ans[i]]=i;
		else Al.pb(i);
	}
	assert(pos[1]);assert(pos[2]);assert(pos[3]);assert(pos[4]);
	assert(pos[n-3]);assert(pos[n-2]);assert(pos[n-1]);assert(pos[n]);
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(x);
		if (ask(tmp)){
			//cout<<"FUCK"<<' '<<x<<endl;
			M3[x]=0;
			Fd[x]=1;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (Fd[x]) continue;
		tmp.pb(pos[1]);tmp.pb(pos[3]);tmp.pb(x);
		if (ask(tmp)){
			M3[x]=2;
			Fd[x]=1;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		if (Fd[x]) continue;
		M3[x]=1;
	} 
	
	//get remainder of 5
	memset(Fd,0,sizeof(Fd));
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (Fd[x]) continue;
		tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(pos[3]);tmp.pb(pos[n-3]);
		tmp.pb(x);
		if (ask(tmp)){
			M5[x]=(1145140-(n+3))%5;
			Fd[x]=true;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (Fd[x]) continue;
		tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(pos[4]);tmp.pb(pos[n-3]);
		tmp.pb(x);
		if (ask(tmp)){
			M5[x]=(1145140-(n+4))%5;
			Fd[x]=true;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (Fd[x]) continue;
		tmp.pb(pos[1]);tmp.pb(pos[3]);tmp.pb(pos[4]);tmp.pb(pos[n-3]);
		tmp.pb(x);
		if (ask(tmp)){
			M5[x]=(1145140-(n+5))%5;
			Fd[x]=true;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (Fd[x]) continue;
		tmp.pb(pos[2]);tmp.pb(pos[3]);tmp.pb(pos[4]);tmp.pb(pos[n-3]);
		tmp.pb(x);
		if (ask(tmp)){
			M5[x]=(1145140-(n+6))%5;
			Fd[x]=true;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		if (Fd[x]) continue;
		M5[x]=(1145140-(n+7))%5;
	}
	
	//get remainder of 7
	memset(Fd,0,sizeof(Fd));
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (Fd[x]) continue;
		tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(pos[3]);tmp.pb(pos[n-3]);tmp.pb(pos[n-2]);tmp.pb(pos[n-1]);
		tmp.pb(x);
		if (ask(tmp)){
			M7[x]=(1145144-(3*n))%7;
			Fd[x]=true;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (Fd[x]) continue;
		tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(pos[3]);tmp.pb(pos[n-3]);tmp.pb(pos[n-2]);tmp.pb(pos[n]);
		tmp.pb(x);
		if (ask(tmp)){
			M7[x]=(1145144-(3*n+1))%7;
			Fd[x]=true;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (Fd[x]) continue;
		tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(pos[3]);tmp.pb(pos[n-3]);tmp.pb(pos[n-1]);tmp.pb(pos[n]);
		tmp.pb(x);
		if (ask(tmp)){
			M7[x]=(1145144-(3*n+2))%7;
			Fd[x]=true;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (Fd[x]) continue;
		tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(pos[3]);tmp.pb(pos[n-2]);tmp.pb(pos[n-1]);tmp.pb(pos[n]);
		tmp.pb(x);
		if (ask(tmp)){
			M7[x]=(1145144-(3*n+3))%7;
			Fd[x]=true;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (Fd[x]) continue;
		tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(pos[4]);tmp.pb(pos[n-2]);tmp.pb(pos[n-1]);tmp.pb(pos[n]);
		tmp.pb(x);
		if (ask(tmp)){
			M7[x]=(1145144-(3*n+4))%7;
			Fd[x]=true;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (Fd[x]) continue;
		tmp.pb(pos[1]);tmp.pb(pos[3]);tmp.pb(pos[4]);tmp.pb(pos[n-2]);tmp.pb(pos[n-1]);tmp.pb(pos[n]);
		tmp.pb(x);
		if (ask(tmp)){
			M7[x]=(1145144-(3*n+5))%7;
			Fd[x]=true;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		if (Fd[x]) continue;
		M7[x]=(1145144-(3*n+6))%7;
	}
	//get the remainder of 8
	
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (M[x]){
			tmp.pb(x);tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(pos[4]);
			if (ask(tmp)) M4[x]=1;
			else M4[x]=3;
		}
		else{
			tmp.pb(x);tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(pos[3]);
			if (ask(tmp)) M4[x]=2;
			else M4[x]=0;
		}
		
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		vector<int> tmp;
		if (M4[x]==0){
			tmp.pb(x);tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(pos[3]);
			tmp.pb(pos[n]);tmp.pb(pos[n-1]);tmp.pb(pos[n-2]);tmp.pb(pos[n-3]);
			if (ask(tmp)) M8[x]=0;
			else M8[x]=4;
		}
		else if (M4[x]==1){
			tmp.pb(x);tmp.pb(pos[2]);tmp.pb(pos[3]);tmp.pb(pos[4]);
			tmp.pb(pos[n]);tmp.pb(pos[n-1]);tmp.pb(pos[n-2]);tmp.pb(pos[n-3]);
			if (ask(tmp)) M8[x]=5;
			else M8[x]=1;
		}
		else if (M4[x]==2){
			tmp.pb(x);tmp.pb(pos[1]);tmp.pb(pos[3]);tmp.pb(pos[4]);
			tmp.pb(pos[n]);tmp.pb(pos[n-1]);tmp.pb(pos[n-2]);tmp.pb(pos[n-3]);
			if (ask(tmp)) M8[x]=6;
			else M8[x]=2;
		}
		else{
			tmp.pb(x);tmp.pb(pos[1]);tmp.pb(pos[2]);tmp.pb(pos[4]);
			tmp.pb(pos[n]);tmp.pb(pos[n-1]);tmp.pb(pos[n-2]);tmp.pb(pos[n-3]);
			if (ask(tmp)) M8[x]=7;
			else M8[x]=3;
		}
	}
	for (int i=0;i<Al.size();i++){
		int x=Al[i];
		for (int j=1;j<=n;j++){
			if (j%8==M8[x] && j%3==M3[x] && j%5==M5[x] && j%7==M7[x]){
				ans[x]=j;
			}
		}
	}
	Output();
	return ~~(0^_^0);
}