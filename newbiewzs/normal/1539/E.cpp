#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int N=2e5+500,INF=1000000002;
vector<pair<int,int> >opt[N];
int curi;
multiset<int>S[2];
int n,m,cho[N],al[N],ar[N],bl[N],br[N],K[N],pd3[N],pd4[N];
void ins(int tp,int x)
{
	opt[curi].push_back(make_pair(tp,x));
	S[tp].insert(x);
}
void del(int tp,int x)
{
	opt[curi].push_back(make_pair(tp,x+INF));
	S[tp].erase(S[tp].find(x));
}
int main()
{
//	freopen("data.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",K+i);
		scanf("%d%d",&al[i],&bl[i]);
		scanf("%d%d",&ar[i],&br[i]);
	}
	K[0]=0;S[0].insert(0),S[1].insert(0);
	for(int i=1;i<=n;i++)
	{
		curi=i;
		pd3[i]=0,pd4[i]=0;
		if(S[0].size()&&ar[i]<=K[i]&&K[i]<=br[i]&&al[i]<=K[i-1]&&K[i-1]<=bl[i])pd3[i]=1;
		if(S[1].size()&&al[i]<=K[i]&&K[i]<=bl[i]&&ar[i]<=K[i-1]&&K[i-1]<=br[i])pd4[i]=1;
		if(!(ar[i]<=K[i]&&K[i]<=br[i]))
		{
			while(S[1].size())del(1,*S[1].begin());
		}
		else
		{
			while(S[1].size()&&*S[1].begin()<al[i])del(1,*S[1].begin());
			while(S[1].size()&&*--S[1].end()>bl[i])del(1,*--S[1].end());
		}
		if(!(al[i]<=K[i]&&K[i]<=bl[i]))
		{
			while(S[0].size())del(0,*S[0].begin());
		}
		else
		{
			while(S[0].size()&&*S[0].begin()<ar[i])del(0,*S[0].begin());
			while(S[0].size()&&*--S[0].end()>br[i])del(0,*--S[0].end());
		}
		if(pd3[i])ins(1,K[i-1]);
		if(pd4[i])ins(0,K[i-1]);
	}
	if(!S[0].size()&&!S[1].size()){puts("No");return 0;}
	int anstp,ansx;
	if(S[0].size())anstp=0,ansx=*S[0].begin();
	else anstp=1,ansx=*S[1].begin();
	for(int i=n;i>=1;i--)
	{
		for(vector<pair<int,int> >::iterator it=opt[i].begin();it!=opt[i].end();++it)
		{
			int tp=it->first,x=it->second;
			if(x<=1000000000)S[tp].erase(S[tp].find(x));
			else S[tp].insert(x-INF);
		}
		if(anstp==0)
		{
			cho[i]=0;
			if(pd4[i]&&ansx==K[i-1])anstp^=1,ansx=*S[1].begin();
		}
		else
		{
			cho[i]=1;
			if(pd3[i]&&ansx==K[i-1])anstp^=1,ansx=*S[0].begin();
		}
	}
	puts("Yes");
	for(int i=1;i<=n;i++)printf("%d ",cho[i]);
}