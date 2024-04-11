#include <bits/stdc++.h>
#define ll long long
#define db(x) cout << "=======>> " << #x << " is " << x << endl
#define pb push_back
#define fi first
#define se second
#define pii pair<ll,ll>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define rep(i,j,k,l) for (int i=(j); i<=(k); i+=(l))
#define repr(i,j,k,l) for (int i=(j); i>=(k); i-=(l))
using namespace std;

ll prefix[200005][26];
ll alp[30];
ll m,n;
string s;
bool cek (ll n){
	for (int i = 0; i <=25; i++){
		if (alp[i]<=prefix[n][i]){
			continue;
		} else{
			return false;
		}
	}
	return true;
}
ll binser (){
	ll save=s.size()-1;
	ll le=0;
	ll ri=n;
	while (le<=ri){
		ll mid=(le+ri)/2;
		if (cek(mid)){
			save=mid;
			ri=mid-1;
		} else{
			le=mid+1;
		}
	}
	return save;
}
int main (){
	IOS;
	//ll n;
	cin>>n;
	//prefix.resize(n, vector<ll>(26,0));
	rep (i, 1,n,1){
		char a;
		cin>>a;
		for(int j=0;j<=25;j++){ prefix[i][j]=prefix[i-1][j];}
		prefix[i][a-'a']++;
	}
	//for (int i = 0; i <26; i++){
		//cout << prefix[n][i] << " ";
	//}
	//cout << endl;
	cin>>m;
	while(m--){
		//string s;
		cin>>s;
		//for(int j=0;j<=26;j+=1) alp[j]=0;
		memset(alp,0,sizeof(alp));
		for(int j=0;j<=s.size()-1;j+=1){
			alp[s[j]-'a']++;
		}
		//for (int i = 0; i <=25; i++){
			//cout << alp[i] << " ";
		//}
		cout << binser() << endl;
		//db(s);
	}
	
}