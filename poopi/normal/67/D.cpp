						/* in the name of Allah */
#include <iostream>
using namespace std;

int n;
int num[1000010];
int p[1000010];
int res[1000010];

int main(){
	int tmp;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			scanf("%d", &tmp);
			p[tmp - 1] = i;
		}
		for(int i = 0; i < n; i++){
			scanf("%d", &tmp);
			num[i] = p[tmp - 1];
		}
		memset(res, -1, sizeof res);
		int cnt = 0;
		for(int i = 0; i < n; i++){
			int l = 0, r = cnt;
			while(l < r){
				int mid = (l + r) / 2;
				if(res[mid] > num[i])
					l = mid + 1;
				else r = mid;
			}
			res[l] = num[i];
			if(l == cnt)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}