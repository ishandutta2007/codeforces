#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n,m,z;
    cin >> n >> m >> z;
    int sk[z];
    for(int i = 0;i<z;i++){
        sk[i] = 0;
    }
    int a = 1;
    while(n * a <= z){
        sk[(n * a) - 1]++;
        a++;
    }
    a = 1;
    while(m * a <= z){
        sk[(m * a) - 1]++;
        a++;
    }
    int sum = 0;
    for(int i = 0;i<z;i++){
        if(sk[i] == 2){
            sum++;
        }
    }
    cout << sum;
	return 0;
}