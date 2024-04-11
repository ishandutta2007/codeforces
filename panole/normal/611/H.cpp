#include<bits/stdc++.h>
using namespace std;

int mi[7]={1,10,100,1000,10000,100000,1000000};
int f[65],n,e[200010][2],cnt[7],po[7],F[65],Cnt[65],ord[7],fa[200010],q[10],l,r,x,len[200010];
char s1[10],s2[10];
vector<int> v[7];
bool bo[7];

bool check(int x,int y)
{
	memcpy(F,f,sizeof(F)),Cnt[0]=0;
	for (int i=0; i<6; i++) Cnt[1<<i]=cnt[i+1];
	Cnt[1<<x-1]--;
	for (int i=0; i<64; i++)
		if ((i>>(x-1)&1)||(i>>(y-1)&1)) F[i]--;
	for (int i=1; i<64; i++) Cnt[i]=Cnt[i^(i&-i)]+Cnt[i&-i];
	for (int i=0; i<64; i++) if (F[i]<Cnt[i]) return 0;
	memcpy(f,F,sizeof(f));
	return cnt[x]--,1;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<n; i++) 
	{
		scanf("%s%s",s1,s2),e[i][0]=strlen(s1),e[i][1]=strlen(s2);
		f[1<<e[i][0]-1]++,f[1<<e[i][1]-1]++,f[(1<<e[i][0]-1)|(1<<e[i][1]-1)]--;
	} 
	for (int i=0; i<6; i++)
		for (int j=0; j<64; j++)
			if (j>>i&1) f[j]+=f[j^(1<<i)];
	for (int i=1; i<=9; i++) len[i]=1;
	for (int i=10; i<=n; i++) len[i]=len[i/10]+1;
	for (int i=1; i<=6; i++) cnt[i]=(n>=mi[i]?mi[i]-mi[i-1]:(n<mi[i-1]?0:n-mi[i-1]+1));
	for (int i=1; i<=6; i++) po[i]=mi[i-1];
	cnt[1]--,po[1]++;
	for (int i=1; i<n; i++)
	{
		if (!check(e[i][0],e[i][1])) 
		{
			if (!check(e[i][1],e[i][0])) return puts("-1"),0;
			swap(e[i][0],e[i][1]),e[i][0]=(po[e[i][0]]++);
		}
		else e[i][0]=(po[e[i][0]]++);
		v[e[i][1]].push_back(e[i][0]);
	}
	q[l=r=1]=1,memset(bo,0,sizeof(bo)),bo[1]=1,ord[1]=1;
	while (l<=r)
	{
		x=q[l++];
		for (int i=0,sz=v[x].size(); i<sz; i++)
		{
			fa[v[x][i]]=ord[x];
			if (!bo[len[v[x][i]]]) 
			{
				q[++r]=len[v[x][i]];
				bo[q[r]]=1,ord[q[r]]=v[x][i];
			}
		}
	}
	for (int i=2; i<=n; i++) if (!fa[i]) return puts("-1"),0;
	for (int i=2; i<=n; i++) printf("%d %d\n",i,fa[i]);
	return 0;
}