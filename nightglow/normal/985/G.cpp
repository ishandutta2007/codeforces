#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<iostream>

#define ul unsigned long long

#define N 200005

using namespace std;
int i,j,m,n,p,k,deg[N],fox[N],A,B,C;
int x,y,z,k1,col[N],ucol[N],bcol[N],Q[N];
struct Node{int x,y,col,Sum;}Bian[N];
struct B{int ed,col,before;}s[N*2];
vector<int>v[N],vec[N];
ul ans;
inline int read()
{
     int x; char c;
     while (c=getchar(),c<'0'||c>'9');
     x=c-'0';
     while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
     return x;
}
void add(int x,int y,int z)
{
     s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].col=z;
}
inline bool cmp(int a,int b)
{
     return Bian[a].Sum<Bian[b].Sum;
}
inline int check(int A,int B)
{
     if (Bian[A].x==Bian[B].x) return Bian[A].x;
     if (Bian[A].x==Bian[B].y) return Bian[A].x;
     return Bian[A].y;
}

ul Cal(int a,int b,int c)
{
	 --a; --b; --c;
	 ul T[3];
	 T[0]=a; T[1]=b; T[2]=c;
	 sort(T,T+3);
	 return A*T[0]+B*T[1]+C*T[2];
}
ul cal(int x,int y)
{
		return (ul)(x+y)*(y-x+1)/2;
}
int main()
{
         memset(deg,0,sizeof(deg));
         memset(fox,0,sizeof(fox)); k1=0;
         for (i=1;i<=n;++i) v[i].clear();
         scanf("%d%d",&n,&m);
		 scanf("%d%d%d",&A,&B,&C); 
         for (i=1;i<=m;++i)
         {
              x=read(); y=read(); x++; y++;
              vec[x-1].push_back(y-1); vec[y-1].push_back(x-1);
              add(x,y,0); add(y,x,0); deg[x]++; deg[y]++;
              Bian[i]=(Node){x,y,0};
         }
         for (i=1;i<=m;++i) 
         {
              if (Bian[i].x>Bian[i].y) swap(Bian[i].x,Bian[i].y);
             Bian[i].Sum=deg[Bian[i].x]<deg[Bian[i].y]?Bian[i].y:Bian[i].x;
         }
         for (i=1;i<=m;++i)
           if (deg[Bian[i].x]<deg[Bian[i].y])
             v[Bian[i].x].push_back(i);
             else v[Bian[i].y].push_back(i);
         for (i=1;i<=n;++i) sort(v[i].begin(),v[i].end(),cmp);
         for (i=1;i<=m;++i)
         {
               x=Bian[i].x,y=Bian[i].y;
               int l=0,L=0,r=v[x].size(),Rx=v[y].size();
               while (l<r&&L<Rx)
               {
                    if (Bian[v[x][l]].Sum<Bian[v[y][L]].Sum) ++l;
                    else if (Bian[v[x][l]].Sum>Bian[v[y][L]].Sum) ++L;
                    else 
                    {
                          int A=x,B=y,C=Bian[v[x][l]].Sum;
                          ans-=Cal(A,B,C);
                     	  l++; L++;
                 }
               }
         }
         for (i=1;i<=n;++i) 
		 	ans+=(ul)A*(n-i)*(n-i-1)/2*(i-1),ans+=(ul)B*(i-1)*(i-1)*(n-i),ans+=(ul)C*(i-1)*(i-2)/2*(i-1);
			 for (i=1;i<=m;++i)
		 {
		 		int x=Bian[i].x,y=Bian[i].y;
		 		if (x>y) swap(x,y);
		 //		for (j=1;j<=n;++j)
		 //			if (j!=x&&j!=y) ans-=Cal(x,y,j); 
		 		ans-=(ul)((ul)A*(x-1)+(ul)B*(y-1))*(n-y)+(ul)C*(cal(y+1,n)-(ul)(n-y)); 
		 		ans-=(ul)((ul)A*(x-1)+(ul)C*(y-1))*(y-x-1)+(ul)B*(cal(x+1,y-1)-(ul)(y-x-1));
		 		ans-=(ul)((ul)B*(x-1)+(ul)C*(y-1))*(x-1)+(ul)A*(cal(1,x-1)-(ul)(x-1));
	  }
		 for (i=0;i<n;++i)
		 	if (vec[i].size()>1)
		 {
		 		ul xx=0,gg=0,yy=0,pp=0,xxs=0,yys=0,ggs=0,pps=0,sk1=0,sk2=0;
		 		sort(vec[i].begin(),vec[i].end());
		 		for (j=0;j<(int)vec[i].size();++j)
				 	if(vec[i][j]<i) sk1+=xx+xxs*B*vec[i][j],xx+=(ul)A*vec[i][j],xxs++,gg+=(ul)B*vec[i][j],ggs++;
					else			sk2+=yy+yys*C*vec[i][j],yy+=(ul)B*vec[i][j],yys++,pp+=(ul)C*vec[i][j],pps++;  
				ans+=sk1+ggs*(ggs-1)/2*C*i;
				ans+=xx*pps+pp*xxs+pps*xxs*B*i;
				ans+=sk2+yys*(yys-1)/2*A*i; 
		 }
		 cout<<ans<<endl;	
}