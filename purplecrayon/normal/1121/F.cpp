#include <bits/stdc++.h>                                                                                                                                                                                                                                                                                
																																																																																														
#define ld long double
#define ll long long
#define ull unsigned long long

#define f first
#define s second
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																								
#define endl '\n'
#define pii pair <ll, ll>

#define ios ios_base::sync_with_stdio(0), cin.tie()
#define pb push_back
#define mp make_pair

#define pi 3.14159265358979323846264
#define y1 abacaba
 
#define fn "abc"

using namespace std;

const int MXN = 5e5 + 30;
const int MAXN = 1e3 + 2;
const ll INF = 1e9 + 7;
const ll BINF = 1e15;
const int mod = 1e9 + 9;
const ld EPS = 1e-15;   
const ll dx[] = {0, 0, 1, -1};
const ll dy[] = {1, -1, 0, 0};

int n, a, b;
char c[MXN];

int d[MXN];
string s;

int p[MXN];  

int main(){
    #ifdef DIAS
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #elif NAME 
    	freopen(fn".in", "r", stdin);
    	freopen(fn".out", "w", stdout);
    #endif
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		d[i] = INF;
    }
    for(int i = 1; i <= n; i++){
    	s = "";
   		for(int j = i; j <= n; j++){
   			s += c[j];
		}
   		s += '&';
		for(int j = 1; j < i; j++){
   			s += c[j];
		}
		int mx = 0;
		//cout << s << ' ';
		for(int k = 1; k < s.size(); k++){
			int j = p[k - 1];
			while(j > 0 && s[k] != s[j]) j = p[j - 1];
			if(s[k] == s[j]) j ++;
			p[k] = j;	 		
		}
		for(int k = n - i + 1; k < s.size(); k++){
			mx = max(mx, p[k]);	
		}
		//cout << mx << ' ';
		d[i] = min(d[i], d[i - 1] + a);
		for(int j = i; j <= i + mx - 1; j++){
			d[j] = min(d[j], d[i - 1] + b);
		}
		//cout << d[i] << ' ';
    }
    cout << d[n];
}