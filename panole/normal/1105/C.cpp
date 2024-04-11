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
const int MO=1e9+7;
int n,l,r;
LL ans,f[200010][3],s[3];
int main(){
//	freopen("t.in","r",stdin);
//	freopen("t.out","w",stdout);
	cin>>n>>l>>r;
	--l;
	s[0]=r/3-l/3;
	s[1]=(r+2)/3-(l+2)/3;
	s[2]=(r+1)/3-(l+1)/3;
	f[0][0]=1;
	FOR(i,0,n-1)
		FOR(j,0,2)
			if (f[i][j]){
				FOR(k,0,2)
					(f[i+1][(j+k)%3]+=f[i][j]*s[k])%=MO;
			}
	ans=(f[n][0]%MO+MO)%MO;
	cout<<ans<<endl;
	return 0;
}