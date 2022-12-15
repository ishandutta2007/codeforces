#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
typedef long long LL;
const int N=2001;
int n;LL S;
struct dot{
	LL x,y;
	dot(){x=y=0;}
	dot(int X,int Y){x=X,y=Y;}
}p[N];
int pos[N];
dot operator -(dot a,dot b){
	return dot(a.x-b.x,a.y-b.y);
}
int m1,m2,m;
struct xint{int x,y;}s1[N*N],s2[N*N],s[N*N];
bool cmp(xint A,xint B){
	dot a=p[A.y]-p[A.x],b=p[B.y]-p[B.x]; 
	return (a.x*b.y-a.y*b.x>0); 
}
bool cmpy(dot a,dot b){return a.y<b.y||a.y==b.y&&a.x<b.x;}
int check(dot a,dot b,dot c,LL area){
	LL res=abs(a.y*b.x-a.x*b.y+b.y*c.x-b.x*c.y+c.y*a.x-c.x*a.y);
	if(res<area)return 1;
	if(res==area){
		cout<<"Yes"<<endl;
		cout<<a.x<<" "<<a.y<<endl;
		cout<<b.x<<" "<<b.y<<endl;
		cout<<c.x<<" "<<c.y<<endl;
		exit(0);
	}
	return -1;
}
int main(){
	cin>>n>>S;S=S*2;
	ref(i,1,n)cin>>p[i].x>>p[i].y;
	sort(p+1,p+n+1,cmpy); m1=m2=0; 
	ref(i,1,n)ref(j,1,n)if(i!=j) {
		if(cmpy(p[i],p[j]))s1[++m1]=(xint){i,j};
		else s2[++m2]=(xint){i,j};
	}
	sort(s1+1,s1+m1+1,cmp);
	sort(s2+1,s2+m2+1,cmp);
	m=m1+m2;
	ref(i,1,m1)s[i]=s1[i];ref(i,1,m2)s[m1+i]=s2[i];
	ref(i,1,n)pos[i]=i;
	ref(i,1,m){
		int x=s[i].x,y=s[i].y;
		int L=1,R=pos[x]-1;
		while(L<R){
			int mid=(L+R+1)>>1;
			if(check(p[mid],p[pos[x]],p[pos[y]],S)==1)R=mid-1;
			else L=mid;
		}
		if(L<=R)check(p[L],p[pos[x]],p[pos[y]],S);
		L=pos[y]+1,R=n;
		while(L<R){
			int mid=(L+R)>>1;
			if(check(p[mid],p[pos[x]],p[pos[y]],S)==1)L=mid+1;
			else R=mid;
		}
		if(L<=R)check(p[L],p[pos[x]],p[pos[y]],S);
		swap(p[pos[x]],p[pos[y]]);
		swap(pos[x],pos[y]);
	}
	cout<<"No"<<endl;
}