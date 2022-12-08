										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define Max 100001
#define Mod 1000000007LL

int n, k, oth;
bool np[Max];
int64 dv[Max], cnt[1100];
int64 dp[1100][1100];
int64 prc[100010];
vector <int64> pr;
map <int, int> mp;

void fine_prime(){
	dv[1] = -1;
	int ted = 0;
	for(int i = 2; i < Max; i++){
		if(!np[i]){
			ted++;
			pr.push_back(i);
			dv[i] = ted - 1;
			for(int j = i + i; j < Max; j += i)
				np[j] = true, dv[j] = ted - 1;
		}
	}
}

bool lucky(int num){
	while(num){
		int d = num % 10;
		if(d != 4 && d != 7)
			return false;
		num /= 10;
	}
	return true;
}

int64 mem(int idx, int rem){
	if(rem == 0)
		return 1;
	if(idx == n)
		return 0;
	if(dp[idx][rem] != -1)
		return dp[idx][rem];
	dp[idx][rem] = (mem(idx + 1, rem) + cnt[idx] * mem(idx + 1, rem - 1)) % Mod;
	return dp[idx][rem];;
}

void setC(int num, int sg){
	while(num > 1){
		prc[dv[num]] += sg;
		num /= pr[(int)dv[num]];
	}
}

int main(){
	fine_prime();
	int x, tmp;
	cin >> x >> k;
	for(int i = 0; i < x; i++){
		scanf("%d", &tmp);
		if(!lucky(tmp))
			oth++;
		else{
			if(mp.find(tmp) == mp.end()){
				cnt[n] = 0;
				mp[tmp] = n++;
			}
			cnt[mp[tmp]]++;
		}
	}
	int mn = min(k, oth);
	int p, q;
	for(p = oth; p > oth - mn; p--)
		setC(p, 1);
	for(q = 1; q <= mn; q++)
		setC(q, -1);
	memset(dp, -1, sizeof dp);
	int64 res = 0;
	for(int i = k - mn; i <= n && p <= oth && q >= 1; i++){
		int64 t1 = mem(0, i);
		int64 t2 = 1;
		for(int j = 0; j < pr.size(); j++)
			for(int k = 0; k < prc[j]; k++)
				t2 = (t2 * pr[j]) % Mod;
		res = (res + t1 * t2) % Mod;
		setC(++p, -1);
		setC(--q, 1);
	}
	cout << res << endl;
	return 0;
}