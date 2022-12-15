#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
#define SZ(x) ((int)x.size())
#define pb push_back
const int mod1=998244353;
const int mod2=1000000007;
const int N=100010;
int n;vector<vector<int> > ans;
struct xint{int x1,x2,y,id;}s[N];
bool cmp(xint a,xint b){return a.x1<b.x1||(a.x1==b.x1&&(a.x2<b.x2||(a.x2==b.x2&&a.y<b.y)));}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	ref(I,1,n){
		string a,b;
		cin>>a>>b;
		int S=0,p=SZ(a);
		ref(i,0,SZ(b)-1)S|=(1<<(b[i]-'a'));
		def(i,SZ(a)-1,0)if(S&(1<<(a[i]-'a')))p=i;else break;
		int hh1=0,hh2=0;
		ref(i,0,p-1){
			hh1=(1LL*hh1*29+(a[i]-'a'+1))%mod1;
			hh2=(1LL*hh2*31+(a[i]-'a'+1))%mod2;
		}
		s[I]=(xint){hh1,hh2,S,I};
	}
	sort(s+1,s+n+1,cmp);
	vector<int> res;
	res.pb(s[1].id);
	ref(I,2,n+1){
		if(I==n+1||s[I].x1!=s[I-1].x1||s[I].x2!=s[I-1].x2||s[I].y!=s[I-1].y){
			ans.pb(res);
			res.clear();
		}
		res.pb(s[I].id);
	}
	cout<<SZ(ans)<<endl;
	ref(i,0,SZ(ans)-1){
		cout<<SZ(ans[i]);
		ref(j,0,SZ(ans[i])-1)cout<<" "<<ans[i][j];
		cout<<endl;
	}
}