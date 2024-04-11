#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,b;
string ans;
bool query(int id,string cur){
	cout<<id<<" "<<cur;
	FOR(i,1,b-(int)cur.size()) cout<<"1";
	cout<<endl;
	cin>>cur;
	return cur[0]=='y';
}
void solve(vector<int> v){
//	cout<<"solving:\n";
//	FOR(i,0,(int)v.size()-1) cout<<v[i]<<endl;
	if((int)ans.size()==b) return;
	vector<int> stk;
//	stk.PB(v[0]);
//	ans.PB(query(v[0],ans+'0')?'1':'0');
	FOR(i,0,(int)v.size()-1){
		while(!stk.empty()){
			bool f=query(v[i],ans);
			if(f) ans.pop_back(),stk.pop_back();
			else break;
		}
		if((int)ans.size()!=b){
			stk.PB(v[i]);
			ans.PB(query(v[i],ans+'0')?'1':'0');
		}
	}
	ROF(i,(int)stk.size()-1,0){
		bool f=query(stk[i],ans);
		if(f) while(stk.back()!=stk[i]) ans.pop_back(),stk.pop_back();
	}
	solve(stk);
}
int main(){
	ios::sync_with_stdio(false);
	n=read();b=read();
	vector<int> v;
	FOR(i,1,n) v.PB(i);
	solve(v);
	cout<<"0 "<<ans<<endl;
}