#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
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

int n;
int ans[805],pl[805];

bool ask(vector<int> x){
	printf("? ");
	printf("%d ",x.size());
	for(auto r:x) printf("%d ",r);
	printf("\n");
	fflush(stdout);
	char str[10];
	return readint();
}

namespace work1{
	int b[805];
	void work(){
		bool fl=0;
		for(int i=1;i<=n;i++){
			vector<int> tmp(0);
			for(int j=1;j<=n;j++) if(j!=i) tmp.pb(j);
			if(ask(tmp)){
				if(!fl) ans[i]=1,pl[1]=i,fl=1;
				else ans[i]=n,pl[n]=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(!ans[i]){
				vector<int> tmp(0);
				tmp.pb(pl[1]),tmp.pb(i);
				if(ask(tmp)) b[i]=1;
				else b[i]=0;
			}
		}
		for(int k=2;k<=n/2;k++){
			int t[2]={0,0};
			for(int i=1;i<=n;i++){
				if(ans[i]) continue;
				vector<int> tmp(0);
				for(int j=1;j<=n;j++) if(j!=i&&!ans[j]) tmp.pb(j);
				if(ask(tmp)){
					if(b[i]==(k&1)) t[0]=i;
					else t[1]=i;
				}
			}
			ans[t[0]]=k,ans[t[1]]=n-k+1;
			pl[k]=t[0],pl[n-k+1]=t[1];
		}
		if(ans[1]>n/2) for(int i=1;i<=n;i++) ans[i]=n+1-ans[i];
		printf("! ");
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}

namespace work2{
	int div2[805],div3[805],div4[805],div5[805],div7[805],div8[805],nd4[10];
	void init(){
		bool fl=0;
		for(int i=1;i<=n;i++){
			vector<int> tmp(0);
			for(int j=1;j<=n;j++) if(j!=i) tmp.pb(j);
			if(ask(tmp)){
				if(!fl) ans[i]=1,pl[1]=i,fl=1;
				else ans[i]=n,pl[n]=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(!ans[i]){
				vector<int> tmp(0);
				tmp.pb(pl[1]),tmp.pb(i);
				if(ask(tmp)) div2[i]=1;
				else div2[i]=0;
			}
		}
		for(int k=2;k<=4;k++){
			int t[2]={0,0};
			for(int i=1;i<=n;i++){
				if(ans[i]) continue;
				vector<int> tmp(0);
				for(int j=1;j<=n;j++) if(j!=i&&!ans[j]) tmp.pb(j);
				if(ask(tmp)){
					if(div2[i]==(k&1)) t[0]=i;
					else t[1]=i;
				}
			}
			ans[t[0]]=k,ans[t[1]]=n-k+1;
			pl[k]=t[0],pl[n-k+1]=t[1];
		}
	}
	void get3(){
		for(int i=1;i<=n;i++){
			if(ans[i]) continue;
			vector<int> tmp(0);
			tmp.pb(pl[1]); tmp.pb(pl[2]); tmp.pb(i);
			if(ask(tmp)) div3[i]=0;
			else{
				tmp[1]=pl[3];
				if(ask(tmp)) div3[i]=2;
				else div3[i]=1;
			}
		}
	}
	void get5(){
		for(int i=1;i<=n;i++){
			if(ans[i]) continue;
			vector<int> tmp(0);
			tmp.pb(pl[1]); tmp.pb(pl[2]); tmp.pb(pl[3]); tmp.pb(pl[n-3]); tmp.pb(i);
			if(ask(tmp)) div5[i]=(7-n%5)%5;
			else{
				tmp[3]=pl[n-2];
				if(ask(tmp)) div5[i]=(6-n%5)%5;
				else{
					tmp[3]=pl[n-1];
					if(ask(tmp)) div5[i]=(5-n%5)%5;
					else{
						tmp[3]=pl[n];
						if(ask(tmp)) div5[i]=4-n%5;
						else div5[i]=(8-n%5)%5;
					}
				}
			}
		}
	}
	void get7(){
		for(int i=1;i<=n;i++){
			if(ans[i]) continue;
			vector<int> tmp(0);
			tmp.pb(pl[1]); tmp.pb(pl[2]); tmp.pb(pl[3]); tmp.pb(pl[n-3]); tmp.pb(pl[n-2]); tmp.pb(pl[n-1]); tmp.pb(i);
			if(ask(tmp)) div7[i]=(7-(3*n)%7)%7;
			else{
				tmp[2]=pl[4];
				if(ask(tmp)) div7[i]=6-(3*n)%7;
				else{
					tmp[1]=pl[3];
					if(ask(tmp)) div7[i]=(12-(3*n)%7)%7;
					else{
						tmp[0]=pl[2];
						if(ask(tmp)) div7[i]=(11-(3*n)%7)%7;
						else{
							tmp[5]=pl[n];
							if(ask(tmp)) div7[i]=(10-(3*n)%7)%7;
							else{
								tmp[4]=pl[n-1];
								if(ask(tmp)) div7[i]=(9-(3*n)%7)%7;
								else div7[i]=(8-(3*n)%7)%7;
							}
						}
					}
				}
			}
		}
	}
	void get8(){
		for(int i=1;i<=n;i++){
			if(ans[i]) continue;
			if(div2[i]==1){
				vector<int> tmp(0);
				tmp.pb(pl[1]); tmp.pb(pl[2]); tmp.pb(pl[4]); tmp.pb(i);
				if(ask(tmp)) div4[i]=1;
				else div4[i]=3;
			}
			else{
				vector<int> tmp(0);
				tmp.pb(pl[1]); tmp.pb(pl[2]); tmp.pb(pl[3]); tmp.pb(i);
				if(ask(tmp)) div4[i]=2;
				else div4[i]=0;
			}
		}
		int now=1+2+3+n-3+n-2+n-1+n;
		nd4[(4-now%4)%4]=4;
		now++;
		nd4[(4-now%4)%4]=3;
		now++;
		nd4[(4-now%4)%4]=2;
		now++;
		nd4[(4-now%4)%4]=1;
		for(int i=1;i<=n;i++){
			if(ans[i]) continue;
			vector<int> tmp(0);
			for(int j=1;j<=4;j++) if(j!=nd4[div4[i]]) tmp.pb(pl[j]);
			tmp.pb(pl[n-3]); tmp.pb(pl[n-2]); tmp.pb(pl[n-1]); tmp.pb(pl[n]); tmp.pb(i);
			if(ask(tmp)) div8[i]=(8-(1+2+3+4+n-3+n-2+n-1+n-nd4[div4[i]])%8)%8;
			else div8[i]=(12-(1+2+3+4+n-3+n-2+n-1+n-nd4[div4[i]])%8)%8;
		}
	}
	void work(){
		init();
		get3();
		get5();
		get7();
		get8();
		for(int i=1;i<=n;i++){
			if(ans[i]) continue;
			for(int j=1;j<=n;j++) if(j%3==div3[i]&&j%5==div5[i]&&j%7==div7[i]&&j%8==div8[i]) ans[i]=j;
		}
		if(ans[1]>n/2) for(int i=1;i<=n;i++) ans[i]=n+1-ans[i];
		printf("! ");
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}

int main(){
	n=readint();
	if(n<=8) work1::work();
	else work2::work();
	return 0;
}