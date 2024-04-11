#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
struct Node
{
    ll x,y;
    Node operator - (Node A) {return (Node){x-A.x,y-A.y};}
    Node operator + (Node A) {return (Node){x+A.x,y+A.y};}
    long double operator * (Node A) const 
	{
		return floor((long double)x*A.y-(long double)y*A.x+0.5);
	}
    long double len() const {return (long double)x*x+(long double)y*y;}
    bool operator < (Node A) {return x<A.x||x==A.x&&y<A.y;}
}A[N],C1[N],C2[N],s1[N],s2[N],bs;
ll cmp1(const Node&A,const Node&B) {return A.y<B.y||(A.y==B.y&&A.x<B.x);}
ll cmp2(const Node&A,const Node&B) {return A*B>0||(A*B==0&&A.len()<B.len());}
ll n,m,sta[N],top,q,tot;
void Convex(Node *A,ll &n)
{
    sort(A+1,A+n+1,cmp1);
    bs=A[1];sta[top=1]=1;
    for(ll i=1;i<=n;i++) A[i]=A[i]-bs;
    sort(A+2,A+n+1,cmp2);
    for(ll i=2;i<=n;sta[++top]=i,i++)
        while(top>=2&&(A[i]-A[sta[top-1]])*(A[sta[top]]-A[sta[top-1]])>=0) top--;
    for(ll i=1;i<=top;i++) A[i]=A[sta[i]]+bs;
    n=top;A[n+1]=A[1];
}
void Minkowski()
{
    for(ll i=1;i<n;i++) s1[i]=C1[i+1]-C1[i];s1[n]=C1[1]-C1[n];
    for(ll i=1;i<m;i++) s2[i]=C2[i+1]-C2[i];s2[m]=C2[1]-C2[m];
    A[tot=1]=C1[1]+C2[1];
    ll p1=1,p2=1;
    while(p1<=n&&p2<=m) ++tot,A[tot]=A[tot-1]+(s1[p1]*s2[p2]>=0?s1[p1++]:s2[p2++]);
    while(p1<=n) ++tot,A[tot]=A[tot-1]+s1[p1++];
    while(p2<=m) ++tot,A[tot]=A[tot-1]+s2[p2++];
}
int main()
{
	scanf("%d",&n),m=n;
    for(ll i=1;i<=n;i++)
        scanf("%lld%lld",&C1[i].x,&C1[i].y);
    Convex(C1,n);
    for(ll i=1;i<=m;i++)
        C2[i].x=-C1[i].x,C2[i].y=-C1[i].y;
    Convex(C2,m);
    Minkowski();
    Convex(A,tot);
    bs=A[1];for(ll i=tot;i>=1;i--) A[i]=A[i]-A[1];
    if (tot!=n)return puts("NO"),0;
    int p1=1,p2=1;
    for (int i=2; i<=n; i++) if (C1[i]<C1[p1]) p1=i;
    for (int i=2; i<=tot; i++) if (A[i]<A[p2]) p2=i;
    int pp1=p1,pp2=p2;
    for (int i=1; i<n; i++)
    {
		p1=(p1==n?1:p1+1);
		p2=(p2==n?1:p2+1);
		Node a=(C1[p1]-C1[pp1]),b=(A[p2]-A[pp2]);
		if (a.x*2!=b.x||a.y*2!=b.y) return puts("NO"),0;
    }
    return puts("YES"),0;
}