//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1000,
	  maxval = 2e6 + 85 - 69;
int a[maxn];
int cnt[maxval];
int n;
bool isprime[maxval];

void sieve(void){
	memset(isprime, true, sizeof isprime);
	isprime[0] = isprime[1] = false;
	for(int i = 0; i < maxval; i++)
		if(isprime[i])
			for(int j = i + i; j < maxval; j += i)
				isprime[j] = false;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	if(cnt[1]){
		int ggg = -1;
		for(int i = 2; i < maxval; i++)
			if(cnt[i] and isprime[i + 1])
				ggg = i;
		if(ggg != -1 and cnt[1] + 1 >= 2){
			cout << cnt[1] + 1 << endl;
			cout << ggg << ' ';
			for(int i = 0; i < cnt[1]; i++)
				cout << 1 << ' ';
			cout << endl;
			return 0;
		}
		else if(cnt[1] >= 2){
			cout << cnt[1] << endl;
			for(int i = 0; i < cnt[1]; i++)
				cout << 1 << ' ';
			cout << endl;
			return 0;
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++)
			if(isprime[a[i] + a[j]]){
				cout << 2 << endl;
				cout << a[i] << ' ' << a[j] << endl;
				return 0;
			}
	cout << 1 << '\n' << a[0] << endl;
	return 0;
}