#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define hash hsh
typedef long long LL;
struct data
{
	LL a,b;bool opt;
	void print()const {printf("%lld %c %lld\n",a,opt?'^':'+',b);}
};
vector<data>ans;
LL x,y,f1,f2;
LL exgcd(LL a,LL b,LL&x,LL&y){
	if(!b)return x=1,y=0,a;
	LL d=exgcd(b,a%b,x,y),t=x;
	return x=y,y=t-a/b*y,d;
}
void Xor(LL x,LL y){ans.pb({x,y,1});}
void Add(LL x,LL y){ans.pb({x,y,0});}
void get(LL x,LL a)
{
	LL ans=0;
	for(;a;a>>=1,Add(x,x),x+=x)if(a&1){if(ans)Add(ans,x);ans+=x;}
}
int main()
{
	scanf("%lld",&x);
	for(int i=20;i>=0;i--)if((1<<i)&x){get(x,1<<i);Xor(x*(1<<i),x);y=(x*(1<<i))^x;break;}
	LL a,b;
	exgcd(x,y,a,b);
	if(a<0)swap(x,y),swap(a,b);b=-b;
	get(x,a);get(y,b);
	f1=b*y;f2=a*x;
	if(f1&1)Add(f1,x),Add(f2,x),f1+=x,f2+=x;
	Xor(f1,f2);
	printf("%d\n",(int)ans.size());
	for(const auto&i:ans)i.print();
    return 0;
}