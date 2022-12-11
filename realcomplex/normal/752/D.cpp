#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

typedef pair<string,int> si;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int L = (int)2e5 + 12345;

bool is[L];
vector<int>be[L];
int ir[L];

string rever(string c){
	reverse(c.begin(),c.end());
	return c;
}

bool palin(string a){
	if(a == rever(a))
		return true;
	else
		return false;
}

map<string,int>has;
int p = 0;

void add(string u){
	if(has[u] != 0)
		return;
	has[u] = ++p;
	is[p] = palin(u);
}

int clc(){
	int y;
	int h;
	int ans = 0;
	for(int i = 0;i<L;i++)sort(be[i].begin(),be[i].end());
	for(int i = 0;i<L;i++){
		y = ir[i];
		if(y == 0)
			continue;
		if(y == i){
			while(be[i].size() >= 2){
				h = be[i].size();
				if(be[i][h-2] < 0)break; // a bad point
				ans += be[i][h-1] + be[i][h-2];
				be[i].pop_back();
				be[y].pop_back();
			}
		}
		else{
			while(be[i].size() >= 1 and be[y].size() >= 1){
				if(be[i].back() + be[y].back() >= 0){
					ans += be[i].back() + be[y].back();
					be[i].pop_back();
					be[y].pop_back();
				}
				else{
					break;
				}
			}	
		}
	}
	vector<pii>sk;
	int extra = 0;
	int all = 0;
	for(int i = 0;i<L;i++){
		if(!is[i])
			continue;
		if(be[i].empty())
			continue;
		if(be[i].size() == 1){
			sk.push_back(mp(be[i].back(),0));
		}
		else{
			h = be[i].size();
			sk.push_back(mp(be[i][h-1],max(0,be[i][h-1] + be[i][h-2])));
			all += max(0,be[i][h-1] + be[i][h-2]);
		}
	}
	for(auto x : sk){
		extra = max(extra,x.fi + max(0,all - x.se));
	}
	return ans + extra;
}
	
int main(){
	fastIO;
	int k,n;
	cin >> k >> n;
	string c;
	int cur;
	for(int i = 0;i<k;i++){
		cin >> c >> cur;
		add(c);
		be[has[c]].push_back(cur);
		add(rever(c));
		ir[has[c]] = has[rever(c)];
		ir[has[rever(c)]] = has[c];
	}
	cout << clc() << "\n";
	return 0;
}