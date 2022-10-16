#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn],b[maxn];
multiset<int> mts;
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) mts.insert(b[i]=read());
	FOR(i,1,n){
		multiset<int>::iterator it1=mts.lower_bound((n-a[i])%n);
		if(it1==mts.end()){
			printf("%d ",(a[i]+*mts.begin())%n);
			if(i!=n) mts.erase(mts.begin());
		}
		else{
			printf("%d ",(a[i]+*it1)%n);
			if(i!=n) mts.erase(it1);
		}
	}
    ;
}