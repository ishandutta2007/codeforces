#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef long double ld;
typedef pair<ld,li> pdi;
typedef pair<li,li> pll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back

vector<pair<char,char> > v;
li n, m, k, x, y, z, i, j, cnt;
string s, t;
char a, b, c, d;
bool vis[2000], good, ch;
map<char,bool> ma;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	a='R';
	b='L';
	c='D';
	d='U';
	cin >> n >> s;
	for (i=0; i<n; i++){
		if (ma[s[i]]==1){
			cnt++;
			ma[a]=0;
			ma[b]=0;
			ma[c]=0;
			ma[d]=0;
			if (s[i]==a) ma[b]=1;
			if (s[i]==b) ma[a]=1;
			if (s[i]==c) ma[d]=1;
			if (s[i]==d) ma[c]=1;
		}
		else {
			if (s[i]==a) ma[b]=1;
			if (s[i]==b) ma[a]=1;
			if (s[i]==c) ma[d]=1;
			if (s[i]==d) ma[c]=1;
		}
	}
	cnt++;
	cout << cnt;
}