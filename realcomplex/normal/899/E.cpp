#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

set<pii>seg,len;
const int N = (int)2e5 + 9;
int arr[N];

int answer = 0;

void Query(){
	answer++;
	int current_len = (*seg.begin()).fi;
	int index = (*seg.begin()).se;
	auto x = len.lower_bound(mp(index,current_len));
	seg.erase(seg.begin());
	len.erase(x);
	x = len.lower_bound(mp(index,current_len));
	if(x == len.begin())return;
	--x;
	auto y = len.lower_bound(mp(index,current_len));
	if(y == len.end())
		return;
	if(arr[(*x).fi] != arr[(*y).fi])
		return;
	index = (*x).fi;
	current_len = (*x).se + (*y).se;
	len.erase(x);
	len.erase(y);
	seg.erase(mp((*x).se,(*x).fi));
	seg.erase(mp((*y).se,(*y).fi));
	len.insert(mp(index,current_len));
	seg.insert(mp(current_len,index));
	
}

int main(){
	fastIO;
	int n;
	cin >> n;
	for(int i = 0;i<n;i++)
		cin >> arr[i];
	int l = 1,b = 0;
	for(int i = 1;i<=n;i++){
		if(i == n){
			if(l != 0){
				seg.insert(mp(-l,b));
				len.insert(mp(b,-l));
			}
		}
		else{
			if(arr[i] == arr[i-1]){
				l++;
			}
			else{
				seg.insert(mp(-l,b));
				len.insert(mp(b,-l));
				b = i;
				l = 1;
			}
		}
	}
	while(!seg.empty()){
		Query();
	}
	cout << answer;
	return 0;
}