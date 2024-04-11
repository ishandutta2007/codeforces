#include <bits/stdc++.h>

using namespace std;

int temp[200005];

int main() {

	int n,k,q;
	cin >> n >> k >> q;
	int a,b;
	for(int i = 0;i<n;i++){
        cin >> a >> b;
        temp[a]++;
        temp[b + 1]--;
	}
	for(int i = 1;i<=200005;i++){
        temp[i] += temp[i - 1];
	}
	for(int x = 1;x<=200005;x++){
        if(temp[x] >= k){
            temp[x] = 1;
        }
        else{
            temp[x] = 0;
        }
	}
	for(int i = 1;i<=200005;i++){
        temp[i] += temp[i - 1];
	}
	for(int i = 0;i<q;i++){
        cin >> a >> b;
        cout << temp[b] - temp[a - 1] << "\n";
	}
	return 0;
}