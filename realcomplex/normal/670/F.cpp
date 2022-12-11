#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

int cnt[10];

bool can(){
	for(int i = 0;i<10;i++)
		if(cnt[i] != 0 )
			return true;
	return false;
}

int calc(int u){
	int a = 0;
	while(u > 0){
		a++;
		u/=10;
	}
	return a;
}

int main(){
	string a;
	cin >> a;
	string b;
	cin >> b;
	for(auto x : a){
		cnt[x-48]++;
	}
	bool eq = false; // jump or not
	for(int x = 1;x<b.size();x++){
		if(b[x] < b[0]){
			eq = true;//jump
			break;
		}
		else if(b[x] > b[0]){
			eq = false; //don't
			break;
		}
	}
	int l = 1;
	int k;
	bool is = false;
	for(int j = 6;j>=1;j--){
		l = a.size()-j;
		if(l<=0)
			continue;
		if(calc(l) != j)
			continue;
		k = l;
		is = true;
		while(k > 0){
			if(cnt[k%10] <= 0){
				is = false;
			}
			cnt[k%10]--;
			k/=10;
		}
		if(is){
			l = j;
			break;
		}
		while(l>0){
			cnt[l%10]++;
			l/=10;
		}
	}
	for(auto x : b)
		cnt[x-48]--;
	int cnt2[10];
	for(int j = 0;j<10;j++)
		cnt2[j] = cnt[j];
	string bef,aft;
	bool sw = false;
	int ct = 0;
	int av;
	while(can()){
		if(ct == 0){
			for(int j = 1;j<10;j++){
				if(cnt[j] != 0){
					av = j;
					break;
				}
			}
		}
		else{
			for(int j = 0;j<10;j++){
				if(cnt[j] != 0){
					av = j;
					break;
				}
			}
		}
		if((av > (b[0]-48)  or (av == (b[0]-48) and eq == true and ct != 0 and av != 0)) and !(ct == 0 and b[0] == '0')){ // its time to switch
			sw = true;
		}
		if(sw){
			aft += (char)av+48;
			cnt[av]--;
		}else{
			bef += (char)av+48;
			cnt[av]--;
		}
		ct++;
	}
	string cur;
	for(auto x : bef){
		if(x >= '0' and x <= '9')
		cur += x;
	}
	for(auto x : b){
		if(x >= '0' and x <= '9')
		cur += x;
	}
	for(auto x : aft){
		if(x >= '0' and x <= '9')
		cur += x;
	}
	if(b[0] != '0'){
		string ct = b;
		for(int i = 0;i<10;i++){
			while(cnt2[i] > 0){
				ct += (char)i+48;
				cnt2[i]--;
			}
		}
		cur = min(ct,cur);
	}
	cout << cur;
	cout << "\n";
	return 0;
}