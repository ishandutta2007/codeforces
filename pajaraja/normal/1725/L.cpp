#include<bits/stdc++.h>

using namespace std;


const int maxN = 1e6 + 10;
long long pref[maxN], b[maxN];
map<long long, int> mp;
int n;
int bit[maxN];
int a[maxN];

void update(int x) {

	for (int i = x; i < maxN; i+=i&-i) {
		bit[i]++;
	}
}

int get(int x) {
	int ans = 0;

	for (int i = x; i>0; i-=i&-i) {
		ans+=bit[i];
	}

	return ans;
}

int main() {

	cin >> n;
    long long mx = -1e9 -1;
	for (int i = 1; i<=n;i++) {
		scanf("%d", &a[i]);
	    pref[i] = pref[i-1] + a[i];
	    mx = max(mx, pref[i]);
	    b[i] = pref[i];
	}
    
    if (pref[n] != mx) {
    	printf("-1\n");
    	return 0;
    }
   
    sort(b + 1, b + n + 1);
    
    if (b[1] < 0) {
    	printf("-1\n");
    	return 0;
    }
    
    int cur = 0;
    for (int i = 1; i<=n; i++) {
        if (i == 1 || b[i] != b[i - 1]) mp[b[i]] = ++cur;
    }
  
    for (int i = 1; i<=n;i++) {
    	pref[i] = mp[pref[i]];
    }
   
   long long ans = 0;

   for (int i = 1; i<=n-1;i++) {
   	 ans+=i - 1 - get(pref[i]);
   	 update(pref[i]);
   }

   cout << ans << endl;

}