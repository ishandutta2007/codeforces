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
bitset<100010> a[44];
int now,n,t,ans,m,ren,c[55][55],p[500010],tp[500010];
string s;
map<string,int> M;
bool u[500010];
int main(){
//	freopen("t.in","r",stdin);
//	freopen("t.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	now=0;
	FOR(i,1,n){
		cin>>tp[i];
		if (tp[i]==1){
			if (tp[i-1]==1) continue;
			++now;
		}
		else{
			cin>>s;
			if (M.find(s)==M.end()) M[s]=++ren;
			t=M[s];
			a[t][now]=1;
		}
	}
	FOR(i,1,ren) c[i][i]=1;
	FOR(i,1,ren)
		FOR(j,i+1,ren)
			if (((int)(a[i]&a[j]).count())!=0){
				c[i][j]=c[j][i]=0;
			}
			else c[i][j]=c[j][i]=1;
	int rp=10000;
	while (rp--){
		FOR(i,1,ren) p[i]=i;
		random_shuffle(p+1,p+ren+1);
		int s=0;
		FOR(i,1,ren) u[i]=0;
		FOR(i,1,ren){
			bool gg=0;
			int x=p[i];
			FOR(j,1,ren)
				if (u[j] && !c[j][x]) gg=1;
			if (!gg){
				++s;
				u[x]=1;
			}
		}
		ans=max(ans,s);
	}
	cout<<ans<<endl;
	return 0;
	
}