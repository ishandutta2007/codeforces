#include<cstdio>
#include<bitset>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
const int N=7010;
bitset<N>now[100010],MU[N];
int n,q,tot,phi[N],mu[N],p[N];
bool v[N];
int main()
{
	scanf("%d%d",&n,&q);
	int i;
	for(mu[1]=phi[1]=1,i=2;i<N;i++){
		if(!v[i])p[tot++]=i,mu[i]=-1,phi[i]=i-1;
		for(int j=0;i*p[j]<N&&j<tot;j++){
			v[i*p[j]]=1;
			if(i%p[j]){
				mu[i*p[j]]=-mu[i];
			} else {
				mu[i*p[j]]=0;
				break;
			}
		}
	}
	rep(i,7000)
	{
		for(int j=1;j*i<=7000;j++)if(mu[j]!=0)MU[i].set(i*j);
	}
	rep(i,q)
	{
		int opt,x,y,z,v;
		scanf("%d%d",&opt,&x);
		if(opt==1)
		{
			scanf("%d",&v);
			now[x].reset();
			for(int j=1;j*j<=v;j++)
			if(v%j==0)
			{
				now[x].set(j);
				if(v/j==j)continue;
				now[x].set(v/j);
			}
		}
		else if(opt==2)
		{
			scanf("%d%d",&y,&z);
			now[x]=now[y]^now[z];
		}
		else if(opt==3)
		{
			scanf("%d%d",&y,&z);
			now[x]=now[y]&now[z];
		}
		else
		{
			scanf("%d",&v);
			printf("%d",(now[x]&MU[v]).count()&1);
		}
	}
	puts("");
	return 0;
}