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
const int Maxn=5005;
int a[Maxn],b[Maxn];
bool dp[Maxn][Maxn];
bool p[Maxn][Maxn];
bool pu[Maxn];
int main(){
	int N,K,V;
	scanf("%d %d %d",&N,&K,&V);
	int tot=0;
	for (int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		tot+=a[i];
	}
	if (tot<V){
		printf("NO\n");
		return 0;
	}
	for (int i=1;i<=N;++i){
		b[i]=a[i]%K;
	}
	dp[0][0]=true;
	for (int i=1;i<=N;i++){
		for (int j=0;j<K;j++){
			if (dp[i-1][j]){
				dp[i][j]=true;
				p[i][j]=false;
			}
			else if (dp[i-1][(j-b[i]+K)%K]){
				dp[i][j]=true;
				p[i][j]=true;
			}
		}
	}
	if (!dp[N][V%K]){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	vector<int> ch,cc;
	int tt1=0;
	int nx=N,ny=V%K;
	while (nx){
		//cout<<nx<<ny<<endl; 
		if (p[nx][ny]) ch.pb(nx),tt1+=a[nx];
		else cc.pb(nx);
		if (p[nx][ny]) ny-=b[nx];
		ny+=K;
		ny%=K;
		nx--;
	}
	bool flag=false;
//	cout<<ch.size()<<cc.size()<<endl;
	for (int i=0;i<(int)ch.size()-1;i++){
		//cerr<<i<<ch.size()-1<<endl;
		printf("%d %d %d\n",1000000000,ch[i],ch[i+1]);
	}
	for (int i=0;i<(int)cc.size()-1;i++){
		printf("%d %d %d\n",1000000000,cc[i],cc[i+1]);
	}
	//cerr<<123<<endl;
	if (ch.empty()){
		int ls=cc.back();
		int an;
		for (int i=1;i<=N;i++){
			if (i!=ls) an=i;
		}
		if (V) printf("%d %d %d\n",V/K,ls,an);
	}
	else if (cc.empty()){
		
		int ls=ch.back();
		int an=0;
		for (int i=1;i<=N;i++){
			if (i!=ls) an=i;
		}
		if (tot!=V){
			printf("%d %d %d\n",(tot-V)/K,ls,an);
		}
	}
	else{
		int ls=ch.back();
		int ls2=cc.back();
		if (tt1>V){
			printf("%d %d %d\n",(tt1-V)/K,ls,ls2);
		}
		else if (tt1<V){
			printf("%d %d %d\n",(V-tt1)/K,ls2,ls);
		}
	}
	return 0;
}