#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;
	int sk = 0;
	int sum = 0;
	for(int i = 0;i<n;i++){
        cin >> sk;
        sum += sk;
	}
	int s,b;
	int t = 10000000;
	cin >> n;
	for(int i = 0;i<n;i++){
        cin >> s >> b;
        if(sum <= b && t == 10000000){
            if(s > sum){
                t = s;
            }
            else{
                t = sum;
            }
        }
	}
	if(t == 10000000){
        cout << -1;
	}
	else{
        cout <<t;
	}
	return 0;
}