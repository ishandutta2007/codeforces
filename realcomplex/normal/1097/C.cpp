#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	int n;
	cin >> n;
	multiset<pii> brack;
	string t;
	int bal = 0;
	int mzb = 0;
	for(int i = 0 ;i < n; i ++ ){
		cin >> t;
		bal = 0;
		mzb = 0;
		for(char x : t){
			if(x == '(')
				bal ++ ;
			else
				bal -- ;
			mzb = min(mzb, bal); 
		}
		brack.insert(mp(mzb, bal));
	}
	int answ = 0;
	int cbal, mn;
	while(!brack.empty()){
		auto it = brack.end();
		-- it;
		mn = it -> fi;
		cbal = it -> se;
		brack.erase(it);
		if(mn < 0)
			continue;
		if(brack.empty())
			break;
		it = brack.lower_bound(mp(-cbal, -cbal));
		if(it -> se != -cbal){
			continue;
		}
		answ ++ ;
		brack.erase(it);
	}
	cout << answ;
	return 0;
}