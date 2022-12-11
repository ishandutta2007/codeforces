#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	int n,m;
	cin >> n >> m;
	int sk[m];
	for(int i = 0;i<m;i++){
        cin >> sk[i];
	}
	sort(sk,sk + m);
	int dif = 10000000;

	for(int i = 0;i<=m - n;i++){

        if(sk[i + n - 1] - sk[i] < dif){
            dif = sk[i + n - 1] - sk[i];
        }
	}
	cout << dif;
	return 0;
}