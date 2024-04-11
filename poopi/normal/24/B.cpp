						/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct racer{
	int scr, cnt[60], num;
	racer(){
		scr = 0;
		memset(cnt, 0, sizeof cnt);
	}
};

int arr[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
map <string, int> mp;
string name[1010];
racer rc[1010];

bool cmp1(racer a, racer b){
	if(a.scr != b.scr)
		return a.scr > b.scr;
	for(int i = 0; i < 60; i++)
		if(a.cnt[i] != b.cnt[i])
			return a.cnt[i] > b.cnt[i];
	return false;
}

bool cmp2(racer a, racer b){
	if(a.cnt[0] != b.cnt[0])
		return a.cnt[0] > b.cnt[0];
	if(a.scr != b.scr)
		return a.scr > b.scr;
	for(int i = 1; i < 60; i++)
		if(a.cnt[i] != b.cnt[i])
			return a.cnt[i] > b.cnt[i];
	return false;
}

int main(){
	int ptr = 0;
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			string str;
			cin >> str;
			if(mp.find(str) == mp.end()){
				rc[ptr].num = ptr;
				name[ptr] = str;
				mp[str] = ptr++;
			}
			int tmp = mp[str];
			rc[tmp].cnt[j]++;
			if(j < 10)
				rc[tmp].scr += arr[j];
		}
	}
	sort(rc, rc + ptr, cmp1);
	cout << name[rc[0].num] << endl;
	sort(rc, rc + ptr, cmp2);
	cout << name[rc[0].num] << endl;
	return 0;
}