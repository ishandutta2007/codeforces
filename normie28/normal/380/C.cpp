#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "petrol.inp"
#define FILE_OUT "petrol.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define endl "\n"
#define mp make_pair
string s;
int sizee;
vector <pair<int,pair<int,int>>> st;
 
void build(int idx = 1, int l = 0, int r = sizee){
	if (r-l < 2){
		st[idx].first = 0;
		if (s[l] == '('){
			st[idx].second.first++;
		}
		else{
			st[idx].second.second++;
		}
		return;
	}
	int mid = (l+r)/2;
	build(idx*2,l,mid);
	build(idx*2+1,mid,r);
	int num = min(st[idx*2].second.first,st[idx*2+1].second.second);
	st[idx].first = st[idx*2].first + st[idx*2+1].first + num;
	st[idx].second.first = st[idx*2].second.first+st[idx*2+1].second.first - num;
	st[idx].second.second = st[idx*2].second.second + st[idx*2+1].second.second - num;
}
 
pair<int,pair<int,int>> query(int i, int j, int idx = 1, int l = 0, int r = sizee){
	if (i >= r or j <= l){
		return mp(0,mp(0,0));
	}
	if ( l >= i and r <= j){
		return st[idx];
	}
	int mid = (l+r)/2;
	pair <int,pair<int,int>> lc = query(i,j,idx*2,l,mid);
	pair <int,pair<int,int>> rc = query(i,j,idx*2+1,mid,r);
	pair <int,pair<int,int>> ans;
	int temp = min(lc.second.first,rc.second.second);
	ans.first = lc.first + rc.first + temp;
	ans.second.first = lc.second.first + rc.second.first - temp;
	ans.second.second = lc.second.second + rc.second.second - temp;
	return ans;
 
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> s;
	sizee = s.size();
	st.assign(4*sizee,pair<int,pair<int,int>>(0,make_pair(0,0)));
	
	build();
	int q;
	cin >> q;
	for (int i = 0 ; i < q ; i++){
		int a,b;
		cin >> a >> b;
		a--;
		cout << 2*query(a,b).first << endl;
	}
}