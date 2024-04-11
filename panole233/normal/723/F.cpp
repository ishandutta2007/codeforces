#include<cstdio>
#include<cstring>

int q[200001],anss,ans1[200001],ans2[200001],bs[200001],bt[200001],n,m,s,t,ds,dt,head[200001],cnt,x,y,l,r,b[200001],anse[200001];
bool bo[200001],bb;

struct node
{
	int next,to,from;
}e[800001];

int main()
{
	scanf("%d%d",&n,&m);
	cnt=0; bb=0;
	memset(head,0,sizeof(head));
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		e[++cnt].to=y; e[cnt].next=head[x]; head[x]=cnt; e[cnt].from=x;
		e[++cnt].to=x; e[cnt].next=head[y]; head[y]=cnt; e[cnt].from=y;
	}
	m=m*2;
	scanf("%d%d%d%d",&s,&t,&ds,&dt);
	if (s==t) bb=1;
	memset(bo,0,sizeof(bo)); bo[s]=bo[t]=1; anss=n; anse[0]=0;
	memset(bs,0,sizeof(bs)); memset(bt,0,sizeof(bt));
	for (int i=1; i<=n; i++) b[i]=i;
	for (int i=1; i<=n; i++)
		if (!bo[i]) 
		{
			q[1]=i; l=1; r=1;
			bo[i]=1; 
			while (l<=r)
			{
				for (int j=head[q[l]]; j; j=e[j].next) 
				{
					if (e[j].to==s) bs[i]=j;
					if (e[j].to==t) bt[i]=j;
					if (!bo[e[j].to]) q[++r]=e[j].to,anss--,anse[++anse[0]]=j,bo[q[r]]=1; b[q[r]]=i;
				}
				l++;
			}
		}
	ans1[0]=ans2[0]=0;
	for (int i=1; i<=n; i++)
		if (b[i]==i&&i!=s&&i!=t)
		{
			if (bs[i]&&!bt[i])
			{
				if ((ds&&bb)||(ds>1&&(!bb))) ans1[++ans1[0]]=e[bs[i]].from,ds--,anss--,b[i]=s;
				else {printf("No"); return 0;}
			}else
			if (!bs[i]&&bt[i])
			{
				if ((dt&&bb)||(dt>1&&(!bb))) ans2[++ans2[0]]=e[bt[i]].from,dt--,anss--,b[i]=t;
				else {printf("No"); return 0;}
			}
		}
	for (int i=1; i<=n; i++)
		if (b[i]==i&&i!=s&&i!=t) 
		{
			if ((!bs[i])&&(!bt[i])) {printf("No"); return 0;}
			if (bs[i]&&bt[i])
			{
				if (bb) 
				{
					if ((bb&&ds)||((!bb)&&ds>1)) ans1[++ans1[0]]=e[bs[i]].from,ds--,anss--,b[i]=s;
					else if ((bb&&dt)||((!bb)&dt>1)) ans2[++ans2[0]]=e[bt[i]].from,dt--,anss--,b[i]=t;
						else {printf("No"); return 0;}
				}
				else
				{
					if (ds&&dt) 
					{
						ans1[++ans1[0]]=e[bs[i]].from,ds--,anss--,b[i]=s;
						ans2[++ans2[0]]=e[bt[i]].from,dt--,anss--;
						bb=1;
					}
					else {printf("No"); return 0;}
				}
			}
			if (anss<=1) break;
		}
	if ((!bb)&&ds&&dt) 
	{
		for (int i=1; i<=m; i++) 
			if (e[i].from==s&&e[i].to==t) {ans1[++ans1[0]]=t,bb=1,anss--; break;}
	}
	if (anss>1||(!bb)) printf("No");
	else
	{
		printf("Yes\n");
		for (int i=1; i<=anse[0]; i++) printf("%d %d\n",e[anse[i]].from,e[anse[i]].to);
		for (int i=1; i<=ans1[0]; i++) printf("%d %d\n",s,ans1[i]);
		for (int i=1; i<=ans2[0]; i++) printf("%d %d\n",t,ans2[i]);
	}
	return 0;
}