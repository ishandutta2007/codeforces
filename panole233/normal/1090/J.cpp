#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
const int N=200001;
namespace sttable{
	template <typename T,int S> class st{public:
		int p[S];T a[S],f[S][21];
		void set(int t,T s){a[t]=s;}
		void init(int sz){
			p[0]=p[1]=0;ref(i,2,sz)p[i]=p[i>>1]+1;
			ref(i,1,sz)f[i][0]=a[i];
			ref(i,1,sz)ref(j,1,p[i])if(i-(1<<j)+1>=1)
				f[i][j]=min(f[i][j-1],f[i-(1<<j-1)][j-1]);
		}
		T ask(int x,int y){
			int L=y-x+1,t=p[L];if((1<<t)==L)return f[y][t];
			return min(f[y][t],f[x+(1<<t)-1][t]);
		}
	};
}
using namespace sttable;
namespace sam{
	int n;
	int s[N*2];st<int,N> he2;
	int rk2[N*2],sa2[N];
	void buildsf(){
		static int s1[N],s2[N],u,v,la;
		memset(s1,0,sizeof s1);
		ref(i,1,n)s1[s[i]]++;ref(i,1,26)s1[i]+=s1[i-1];
		ref(i,1,n)sa2[s1[s[i]]--]=i;
		ref(i,1,n){
			u=sa2[i-1],v=sa2[i];
			rk2[v]=rk2[u]+(s[v]!=la||i==1);la=s[v];
		}
		int S=rk2[sa2[n]];
		for(int I=1;S<n;I<<=1){
			memset(s1,0,sizeof s1);
			ref(i,1,n)s1[rk2[i+I]]++;ref(i,1,S)s1[i]+=s1[i-1];
			ref(i,1,n)s2[s1[rk2[i+I]]--]=i;
			memset(s1,0,sizeof s1);
			ref(i,1,n)s1[rk2[i]]++;ref(i,1,S)s1[i]+=s1[i-1];
			def(i,n,1)sa2[s1[rk2[s2[i]]]--]=s2[i];
			ref(i,1,n){
				u=sa2[i-1],v=sa2[i];
				s1[v]=s1[u]+(rk2[v]!=rk2[u]||rk2[v+I]!=rk2[u+I]||i==1);
			}
			ref(i,1,n)rk2[i]=s1[i];S=rk2[sa2[n]];
		}
	}
	void buildhe(){
		int h=0;
		ref(i,1,n){
			if(h)h--;int j=sa2[rk2[i]-1];
			while(s[i+h]==s[j+h])h++;he2.set(rk2[i],h);
		}
		he2.init(n);
	}
	void build(){
		buildsf();buildhe();
	}
}
void getfa(int* fa,char* s,int n){
	memset(fa,0,sizeof fa);
	ref(i,2,n){
		int x=fa[i-1];
		while(x&&s[i]!=s[x+1])x=fa[x];
		if(s[i]==s[x+1])x++;
		fa[i]=x;
	}
}
char s1[N+1],s2[N+1];
int n,m,fa2[N+1],f[N+1],S[N+1];
int main(){
	scanf("%s",s1+1); scanf("%s",s2+1);
	n=strlen(s1+1); m=strlen(s2+1);
	getfa(fa2,s2,m);
	ref(i,1,n)sam::s[i]=s1[i]-'a'+1;
	ref(i,n+2,n+m+1)sam::s[i]=s2[i-n-1]-'a'+1;
	sam::n=n+m+1;
	sam::build();
	ref(i,1,n){
		int a=sam::rk2[i],b=sam::rk2[n+2];
		if(a>b)swap(a,b);
		f[i]=sam::he2.ask(a+1,b);
	}
	ref(i,1,m){
		if(!fa2[i])S[N]++;
		else S[i-fa2[i]]++;
	}
	def(i,N-1,0)S[i]+=S[i+1];
	long long ans=0;
	ref(i,1,n){
		ans+=S[f[i+1]+1];
	//	cout<<i<<" "<<S[f[i+1]+1]<<endl;
	}
	cout<<ans<<endl;
}