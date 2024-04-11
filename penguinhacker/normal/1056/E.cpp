#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int p=37, MOD=1e9+9;
int binPow(ll b, int p=MOD-2) {
	ll res=1;
	while(p) {
		if (p&1) res=res*b%MOD;
		b=b*b%MOD;
		p>>=1;
	}
	return res;
}

ll pre[1000000], iv[1000000], cnt[2];
string s, t;

int get(int l, int r) {
	return (pre[r]+MOD-(l?pre[l-1]:0))%MOD*iv[l]%MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;
	cnt[0]=count(s.begin(), s.end(), '0');
	cnt[1]=s.size()-cnt[0];
	ll pp=1;
	for (int i=0; i<t.size(); ++i) {
		iv[i]=binPow(pp);
		pre[i]=(pp*(t[i]-'a'+1)+(i?pre[i-1]:0))%MOD;
		pp=pp*p%MOD;
	}
	int ans=0;
	for (int len=1; len*cnt[0]<t.size(); ++len) {
		if ((t.size()-len*cnt[0])%cnt[1]) continue;
		int a=len, b=(t.size()-len*cnt[0])/cnt[1];
		int h1=-1, h2=-1;
		bool pos=1;
		for (int i=0, ind=0; i<s.size(); ++i) {
			int x=s[i]-'0';
			if (x==0) {
				if (h1!=-1&&get(ind, ind+a-1)!=h1) {
					pos=0;
					break;
				}
				h1=get(ind, ind+a-1);
				ind+=a;
			}
			if (x==1) {
				if (h2!=-1&&get(ind, ind+b-1)!=h2) {
					pos=0;
					break;
				}
				h2=get(ind, ind+b-1);
				ind+=b;
			}
		}
		if (h1==h2) pos=0;
		ans+=pos;
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/