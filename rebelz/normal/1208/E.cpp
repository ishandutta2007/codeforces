#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,w;
vector<int> v[1000005];
multiset<int> s[1000005];

int main(){
	n=readint(); w=readint();
	for(int i=1;i<=n;i++){
		v[i].resize(readint()+2);
		v[i][0]=0;
		for(int j=1;j<v[i].size()-1;j++) v[i][j]=readint();
		v[i][v[i].size()-1]=0;
	}
	sort(v+1,v+n+1,[&](const vector<int> &x,const vector<int> &y){return x.size()<y.size();});
	for(int i=1;i<=n;i++) if(v[i].size()!=w+2) s[i].insert(0);
	int now1=1,now2=n+1; ll ans=0;
	for(int i=1;i<=w;i++){
		for(int j=now1;j<=n;j++){
			if(s[j].size()) ans-=*(--s[j].end());
			s[j].insert(v[j][i]);
			ans+=*(--s[j].end());
		}
		while(now1<=n&&v[now1].size()==i+1) now1++;
//		cout<<"################################## "<<endl;
//		for(int j=1;j<=n;j++){
//			for(auto x:s[j]) cout<<x<<' ';
//			cout<<endl;
//		}
		printf("%lld ",ans);
		while(now2>1&&i+v[now2-1].size()-2>=w) now2--;
		for(int j=n;j>=now2;j--){
			ans-=*(--s[j].end());
			s[j].erase(s[j].find(v[j][i-w+v[j].size()-2]));
			if(s[j].size()) ans+=*(--s[j].end());
		}
	}
	printf("\n");
	return 0;
}