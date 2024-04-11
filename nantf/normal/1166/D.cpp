#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int q;
ll a,b,m,r[55],p2[55];
int main(){
	p2[0]=1;
	FOR(i,1,50) p2[i]=2*p2[i-1];
	q=read();
	while(q--){
		a=read();b=read();m=read();
		MEM(r,0);
		if(a==b) cout<<1<<" "<<a<<endl;
		else if(b-a<=m) cout<<2<<" "<<a<<" "<<b<<endl;
		else{
			bool flag=false;
			FOR(k,3,50){
				if(p2[k-2]<ceil(1.0*b/(a+m)) || p2[k-2]>b/(a+1)) continue;
				ll s=b-p2[k-2]*a;
				bool ok=true;
				FOR(i,2,k-2){
					ll upr=1.0*s/p2[k-i-1]-1,lwr=ceil(1.0*s/p2[k-i-1])-m;
					r[i]=min(upr,m);
					if(r[i]<lwr){ok=false;break;}
					s-=p2[k-i-1]*r[i];
				}
				if(!ok) continue;
				r[k-1]=min(m,s-1);
				r[k]=s-r[k-1];
				if(r[k]>m) continue;
				flag=true;
				ll s2=s=a;
				cout<<k<<" "<<s<<" ";
				FOR(i,2,k){
					s=s2+r[i];
					cout<<s<<" ";
					s2+=s;
				}
				cout<<endl;
				break;
			}
			if(!flag) puts("-1");
		}
	}
}
// orz CDW IMO AKer