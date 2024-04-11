#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1023456;
const int MOD=1e9+7;
#ifndef ONLINE_JUDGE
ifstream fin("test.in");
ofstream fout("test.out");
#define cin fin
#define cout fout
#endif
ll cnt[26], fac[maxn], f[26], n;
string a, b;
void init(){
	fac[0]=1;
	for(int i=1; i<maxn; i++)
		fac[i]=fac[i-1]*i%MOD;
}
ll fast_pow(ll x, ll k){
	ll product=1, base=x;
	while(k){
		if(k&1){
			product*=base;
			product%=MOD;
		}
		base*=base;
		base%=MOD;
		k>>=1;
	}
	return product;
}
ll solve(const string& str){
	int s=0, k=1;
	memcpy(f, cnt, sizeof(cnt));
	for(int i=0; i<n; i++){
		ll p=0, cur=str.at(i)-'a';
		for(int j=0; j<cur; j++) p+=f[j];
		s=(s+p*fac[n-i-1]%MOD*k%MOD)%MOD;
		if(!f[cur]) break;
		k=k*f[cur]%MOD;
		f[cur]--;
	}
	for(int i=0; i<26; i++)
		s=s*fast_pow(fac[cnt[i]], MOD-2)%MOD;
	return s;
}
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	init();
	cin>>a>>b;
	n=a.length();
	for(char ch:a) cnt[ch-'a']++;
	cout<<(solve(b)-solve(a)-1+MOD)%MOD<<endl;
	return 0;
}