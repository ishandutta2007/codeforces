#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int x[2000010],y[2000010],p[2000010],fa[2000010],n,m,ans,z[2000010];
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
bool cmp(int A,int B){
	return (z[A]<z[B]);
}
int main(){
	cin>>n>>m;
	FOR(i,1,n) fa[i]=i;
	FOR(i,1,m){
		getint(x[i]),getint(y[i]),getint(z[i]);
	}
	FOR(i,2,m) p[i]=i;
	sort(p+2,p+m+1,cmp);
	z[0]=1000000000;
	FOR(i,2,m+1){
		if (getf(x[1])!=getf(y[1])) ans=z[p[i]];
		if (i>m) break;
		if (getf(x[p[i]])!=getf(y[p[i]])){
			fa[getf(x[p[i]])]=getf(y[p[i]]);
		}
	}
	cout<<ans<<endl;
	return 0;
}