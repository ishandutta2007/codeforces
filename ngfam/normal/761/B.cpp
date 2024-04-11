#include <bits/stdc++.h>

using namespace std;

const int N = 111;

int len, n, a[N], b[N], cnt[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	cin >> n >> len;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i){
		cin >> b[i];
	}

	for(int pa = 0; pa < len; ++pa){
		for(int pb = 0; pb < len; ++pb){
			memset(cnt, 0, sizeof cnt);
			for(int i = 1; i <= n; ++i){
			//  memset(cnt, 0, sizeof cnt);
				int newpa = (pa - a[i]);
				int newpb = (pb - b[i]);
 				if(newpa < 0) newpa += len;
				if(newpb < 0) newpb += len;
				++cnt[newpa];
				++cnt[newpb];
			}
			bool ok = false;
			for(int i = 0; i < len; ++i){
				if(cnt[i] != 0 && cnt[i] != 2){
					ok = true;
					break;	
				}
			}
			if(ok == false){
				puts("YES");
				return 0;
			}
		}
	}

	puts("NO");

	return 0;
}