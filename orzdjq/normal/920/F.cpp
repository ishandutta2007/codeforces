#include<bits\stdc++.h>
using namespace std;
#define LL long long
#define ll   long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
const int Maxn=300005;
int a[Maxn],b[Maxn];
int d[1000005];
bool isp[1000005];
void _init(){
	memset(isp,true,sizeof(isp));
	for (int i=1;i<=1000000;i++) d[i]=1;
	for (int i=2;i<=1000000;i++){
		if (isp[i]){
			d[i]=2;
			for (int j=i+i;j<=1000000;j+=i){
				int tmp=j,cur=0;
				while (tmp%i==0)tmp/=i,cur++;
				d[j]*=(cur+1);
				isp[j]=false; 
			}
		}
	}
}
set<int> pos;
long long bit[Maxn];
void add(int x,LL v){
	while (x<Maxn){
		bit[x]+=v;
		x+=x&-x;
	}
}
LL query(int x){
	LL ans=0;
	while (x){
		ans+=bit[x];
		x-=x&-x;
	}
	return ans;
}
int main(){
	_init();
	//cout<<d[10];
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]>2) pos.insert(i);
	}
	for (int i=1;i<=n;i++){
		add(i,a[i]);
	}
	for (int i=1;i<=m;i++){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int l,r;
			scanf("%d %d",&l,&r);
			set<int>::iterator it=pos.lower_bound(l),it2;
			for (;it!=pos.end();){
				if (*it>r) break;
				int nw=d[a[*it]];
				add(*it,nw-a[*it]);
				a[*it]=nw;
				if (nw==2){
					it2=it;
					it++;
					pos.erase(it2);
				}
				else{
					it++;
				}
			}
		}
		else{
			int l,r;
			scanf("%d %d",&l,&r);
			LL ans=query(r)-query(l-1);
			printf("%I64d\n",ans);
		}
	}
	return 0;
}