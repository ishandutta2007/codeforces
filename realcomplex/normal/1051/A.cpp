#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	int q;
	cin >> q;
	for(int test = 0; test < q; test ++ ){
		string s;
		cin >> s;
		int n = s.size();
		int u = 0, l = 0, dig = 0;
		for(char x : s){
			if(x >= '0' and x <= '9')
				dig ++ ;
			else if(x >= 'a' and x <= 'z')
				l ++ ;
			else
				u ++ ;
			
		}
		if(u > 0 and l > 0 and dig > 0){
			cout << s << "\n";
			continue;
		}
		if(n == u or n == l or n == dig){
			int p = 0;
			if(u == 0) s[p ++ ] = 'A';
			if(l == 0) s[p ++ ] = 'a';
			if(dig == 0) s[p ++ ] = '0';
			cout << s << "\n";
			continue;
		}
		if(u > 1){
			for(char &x : s){
				if(x >= 'A' and x <= 'Z'){
					if(dig == 0){
						dig ++ ;
						x = '1';
					}
					else if(l == 0){
						l ++ ;
						x = 'a';
					}
					else if(u == 0){
						u ++ ;
						x = 'A';
					}
				}
			}
		}
		else if(l > 1){
			for(char &x : s){
				if(x >= 'a' and x <= 'z'){
					if(dig == 0){
						dig ++ ;
						x = '1';
					}
					else if(l == 0){
						l ++ ;
						x = 'a';
					}
					else if(u == 0){
						u ++ ;
						x = 'A';
					}
				}
			}
		}
		else if(dig > 1){
			for(char &x : s){
				if(x >= '0' and x <= '9'){
					if(dig == 0){
						dig ++ ;
						x = '1';
					}
					else if(l == 0){
						l ++ ;
						x = 'a';
					}
					else if(u == 0){
						u ++ ;
						x = 'A';
					}
				}
			}
		}
		cout << s << "\n";
	}
	return 0;
}