#include <bits/stdc++.h>
#define int long long
using namespace std;

char qry1(int x){
	cout << "? " << 1 << ' ' << x + 1 << endl;
	char r; cin >> r;
	return r;
}
int qry2(int l, int r){
	cout << "? " << 2 << ' ' << l + 1 << ' ' << r + 1 << endl; 
	int ret; cin >> ret;
	return ret;
}
void answer(string s){
	cout << "! " << s << endl;
}

string ans;
int32_t main(){
	int n;
	cin >> n; ans.resize(n);
	int pr = 0;
	vector<int> fi;
	map<char, int> M;
	for(int i = 0; i < n; i++){
		int c = qry2(0, i);
		if(c > pr){
			ans[i] = qry1(i);
			pr = c;
		}
	}
	for(int i = 0; i < n; i++){
		fi.clear();
		for(auto i : M){
			fi.push_back(i.second);
		}
		sort(fi.begin(), fi.end());
		int l = 0, u = --upper_bound(fi.begin(), fi.end(), i) - fi.begin();
		int mu = u;
		if(ans[i]) goto End;
		while(l != u){
			int m = (l + u + 1) / 2;
			if(qry2(fi[m], i) == mu - m + 1){
				l = m;
			}else{
				u = m - 1;
			}
		}
		ans[i] = ans[fi[l]];
		End:;
		M[ans[i]] = i;
	}
	answer(ans);
}