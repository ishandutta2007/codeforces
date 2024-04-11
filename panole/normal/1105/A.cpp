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
const int INF=1e9+10;
int ans,t,n,ANS,a[500010];
int main(){
//	freopen("t.in","r",stdin);
//	freopen("t.out","w",stdout);
	cin>>n;
	FOR(i,1,n) getint(a[i]);
	ANS=INF;
	FOR(i,1,200){
		t=0;
		FOR(j,1,n)
			if (a[j]<i-1) t+=i-1-a[j];
			else if (a[j]>i+1) t+=a[j]-i-1;
		if (t<ANS){
			ans=i;
			ANS=t;
		}
	}
	cout<<ans<<' '<<ANS<<endl;
	return 0;
}